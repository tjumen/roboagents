#include "world.h"
#include "robot.h"
#include <unordered_set>

int main(int argc, char** argv) {

  //I didn't change the data structure for representing the world due to time constaints.
  char map[7][7] = {
    {'1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '1', '1', '0', '1'},
    {'1', '0', '0', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1', '1'},
  };

  std::shared_ptr<World> world_ptr = std::make_shared<World>(map);

  Robot robotA('A', world_ptr);
  Robot robotB('B', world_ptr);

  // place robots 'A' and 'B' in the world. Both robots have the same behavior.
  // A robot moves one space a second in one direction until blocked, then moves in another direction
  // (the new is selected randomly)
  world_ptr->addRobot(robotA.getLabel(), 1, 1);
  world_ptr->addRobot(robotB.getLabel(), 5, 4);

  // Launch robots 'A' and 'B' in their own threads
  std::thread thA, thB;
  thA = robotA.run();
  thB = robotB.run();

  // periodically display where the robots are in the world "map"
  world_ptr->run();

  thA.join();
  thB.join();
}
