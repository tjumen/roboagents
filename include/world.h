#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "robot.h"
#include "util.h"
#include <unordered_map>
#include <memory>
#include <mutex>

// Forward declaration
class Robot;

class Location;

/*
 * I didn't change the data structure for representing the world due to time constaints.
 *
 * It can definitely be improved. The map can be represented with vector of vectors or chars,
 * as in std::vector<std::vector<char> > map.
 * Alternatively, we can use OpenCV cv::Mat object of type CV_8UC1 to store the world map.
*/
class World {
public:
    World(char map[7][7]);
    bool addRobot(char label, int row, int col);
    void run();
    void display();
    bool updateRobotLocation(char label, Direction direction);
    bool doesRobotExist(char label);

private:

    std::mutex m;
    char map_[7][7];
    std::unordered_map<char, Location> robotLocationMap;

};

#endif
