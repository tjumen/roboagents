#include "robot.h"
#include <thread>
#include <chrono>
#include <iostream>

Robot::Robot() {}

Robot::Robot(char label, std::shared_ptr<World> world_ptr):
    label_(label), world_ptr_(world_ptr)
{
    // pick the initial direction at random
    direction = static_cast<Direction>(rand() % 4);
}


// The robot moves based on simple behavior.
// It moves one space a second in one direction until blocked, then moves in another direction.
// New direction is selected randomly.
void Robot::moveStep() {
    // try moving the robot in the world
    bool isMoved = world_ptr_->updateRobotLocation(label_, direction);
    while (!isMoved) {
        // change direction. New direction is picked randomly
        direction = static_cast<Direction>(rand() % 4);
        isMoved = world_ptr_->updateRobotLocation(label_, direction);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

std::thread Robot::run() {
    return std::thread(&Robot::start, this);
}

char Robot::getLabel() {
    return label_;
}

// Start the robot and let it run for awhile
void Robot::start() {

    if (!world_ptr_->doesRobotExist(label_) ) {
        return;
    }

    for (int i = 0; i < 1000; ++i) {
        moveStep();
    }
}
