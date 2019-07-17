#include <iostream>
#include <thread>
#include <chrono>
#include "world.h"


World::World(char map[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            map_[i][j] = map[i][j];
        }
    }
}

/*
 * Adds robot at row and col location if the coordinate is unobsructed
 * Returns true if the world coordinate is unobstracted
 * and false otherwise
*/
bool World::addRobot(char label, int row, int col) {

    // we can't add a robot if the world coordinate is blocked
    // or robot with that label has been added before
    if (map_[row][col] != '0' || robotLocationMap.count(label) > 0)  {
        return false;
    }

    map_[row][col] = label;
    Location coords(col, row);
    robotLocationMap[label] = coords;
    return true;
}

bool World::doesRobotExist(char label) {
    return robotLocationMap.count(label) > 0;
}

void World::run() {
    while (true) {
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// This method updates the state of the world and the code in the method
// can only be executed by one thread.
// This means that only one robot can update the state of the world at a time.
// I use lock-based approach. The code is protected with a mutex.
bool World::updateRobotLocation(char label, Direction direction) {

    //   locks the code in this scope to avaid race condition when several robots try to modify
    //   'robotLocationMap' and 'map_' simultaneously
    //   Note: we can use fine grained locks or
    //   lock free data structures but this is okay for now.
    std::lock_guard<std::mutex> guard(m);

    // Make sure that the robot with this label actually exists in the world
    if (robotLocationMap.count(label) < 0) {
        return false;
    }

    Location coords, old_coords;
    old_coords = robotLocationMap[label];
    coords = old_coords;

    switch(direction) {
    case north:
        coords.y = coords.y - 1;
        break;
    case south:
        coords.y = coords.y + 1;
        break;
    case east:
        coords.x = coords.x + 1;
        break;
    case west:
        coords.x = coords.x - 1;
        break;
    }

    bool isSuccess = false;
    char whatIsThere = map_[coords.y][coords.x];
    if (whatIsThere == '0') {
        map_[coords.y][coords.x] = label;
        map_[old_coords.y][old_coords.x] = '0';
        robotLocationMap[label] = coords;
        isSuccess = true;
    }
    return isSuccess;
}

void World::display() {
    // "Clear" screen
    for (int i = 0; i < 20; i++)
        std::cout << std::endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            std::cout << map_[i][j];
        }
        std::cout << std::endl;
    }
}
