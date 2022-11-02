# Robot Simulator

Write a robot simulator.

A robot factory's test facility needs a program to verify robot movements.

The robots have three possible movements:

* turn right
* turn left
* advance

Robots are placed on a hypothetical infinite grid, facing a particular direction (north, east, south, or west) at a set of {x,y} coordinates, e.g., {3,8}, with coordinates increasing to the north and east.

The robot then receives a number of instructions, at which point the testing facility verifies the robot's new position, and in which direction it is pointing.

* The letter-string "RAALAL" means:
  * Turn right
  * Advance twice
  * Turn left
  * Advance once
  * Turn left yet again

Say a robot starts at {7, 3} facing north. Then running this stream of instructions should leave it at {9, 4} facing west.

## Example

```cpp
Robot robot({7,3}, {Bearing::NORTH});

robot.turn_right();
robot.advance();
robot.advance();
robot.turn_left();
robot.advance();
robot.turn_left();

robot.get_position() == {9,4};
robot.get_bearing() == Bearing::WEST;
```

## Installation/Usage

[See the ExercismPractice README for general usage and installation details.](https://github.com/Lignite17/ExercismPractice/blob/main/README.md)

## License
[MIT](https://choosealicense.com/licenses/mit/)
