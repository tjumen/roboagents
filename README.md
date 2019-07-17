# Roboagents

This program will simulate autonomous robots running around a 2D world. In addition to running without bugs and meeting all of the following design criteria, we will be evaluating the object-oriented design and coding style, so please code as if you were handing it off to a colleague to maintain. You do not need to write tests (unless it helps you), and full documentation is not necessary, but please briefly comment any non-obvious code.

This project has two classes for you to finish implementing, Robot and World. The World class encapsulates a simple 2D world.
* The world map is represented by a 2D data structure of your choice with each coordinate either blocked or unobstructed. The map is a rectangle of arbitrary size that is blocked around the entire border and has arbitrary internal coordinates blocked. You do not have to handle map configuration edge cases.
* World provides a way to place robots, and keeps track of the location of them. Each robot exists in a single coordinate space. There can be up to a few robots on the map at a time.
* World provides a movement API for the Robot class.
  * A robot can try to move a single space in any direction (holonomic), but if that space is blocked the robot does not move. Robot receives whether the move was successful or no
* World continuously displays the world (obstacles plus robots) to the terminal using ASCII. Below is example output with two robots A and B

1111111
1A00001
100B001
1001101
1001101
1000001
1111111# roboagents

