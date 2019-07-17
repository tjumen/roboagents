#ifndef ROBOT_H_
#define ROBOT_H_

#include "world.h"
#include "util.h"
#include <thread>

// Forward declaration
class World;

// Define and implement the following class
class Robot {

public:
    Robot();
    Robot(char label, std::shared_ptr<World> world_ptr);
    std::thread run();
    char getLabel();

private:
    void start();
    void moveStep();
    char label_;
    std::shared_ptr<World> world_ptr_;
    Direction direction;

};

#endif
