#include "robot_commander/robot_commander.h"
#include <ros/ros.h>
#include <iostream>
#include <exception>

int main(int argc, char **argv) {
  ros::init(argc, argv, "exercise_8_1");

  RobotCommander my_robot;

  int n =0;
    
  while(n<5){
      
  float turn_velocity;
  std::cout << "Enter turn velocity: ";

  // INSERT YOUR CODE BELOW THIS LINE
    try {
        std::cin >> turn_velocity;
        if (std::cin.fail()) 
            throw 'x';
        else if (turn_velocity >= -1.0 && turn_velocity <= 0.0)
            my_robot.turn(turn_velocity, 5);
        else if (turn_velocity > 0.0)
            throw 1;
        else if (turn_velocity < -1.0)
            throw 1;
        else
            throw 'x';
    } catch (int n) {
        std::cout << "Enter turn velocity between -1.0 and 0.0" << std::endl;
    } catch (...) {
        std::cout << "Please enter a decimal number." << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n'); 
    }
    

    
  // INSERT YOUR CODE ABOVE THIS LINE
  n++;
  }
  
  return 0;
}