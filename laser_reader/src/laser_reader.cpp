#include "../include/laser_reader/laser_reader.h"
#include "sensor_msgs/LaserScan.h"
#include <ros/ros.h>

// TurtleClass constructor make changes in the constructor as per definition
TurtleClass::TurtleClass() {
  n = ros::NodeHandle("~");
  laser_sub =
      n.subscribe("/kobuki/laser/scan", 10, &TurtleClass::laser_callback, this);
  ROS_INFO("Initializing node.");
  usleep(2000000);
  // an array of 720 pointers to float
//   last_laser_ranges = new float[720];
  for (int i = 0; i < 10; i++) {
    last_ten_scans[i] = new float[720];
  } 
}

/* CREATE THE CLASS DESTRUCTOR HERE */
TurtleClass::~TurtleClass() { 
    // delete last_laser_ranges; 
    for (int i = 0; i < 10; i++) {
        delete[] last_ten_scans[i];
    }
}

void TurtleClass::laser_callback(
    const sensor_msgs::LaserScan::ConstPtr &laser_msg) {

    /* WRITE HERE YOUR CODE */
    // for (int i = 0; i < laser_msg->ranges.size(); i++) {
    //     last_laser_ranges[i] = laser_msg->ranges[i];
    // }

    // Shift the elements in last_ten_scans array to make space for the new scan
    for (int i = 9; i > 0; i--) {
        for (int j = 0; j < 720; j++) {
            last_ten_scans[i][j] = last_ten_scans[i - 1][j];
        }
    }

    // Store the new scan in the first element of last_ten_scans array
    for (int i = 0; i < 720; i++) {
        last_ten_scans[0][i] = laser_msg->ranges[i];
    }

//   std::cout << "Distance measured by the ray at the front of the robot: ";
//   std::cout << *(last_laser_ranges + 360) << std::endl;

    // Print the range measured at the front of the robot for the last 10 scans
    std::cout << "Range measured by the ray at the front for the last 10 scans:\n";
    for (int i = 0; i < 10; i++) {
        std::cout << "Scan " << i << ": " << last_ten_scans[i][360] << std::endl;
    }

}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_class_node");

  TurtleClass tc = TurtleClass();
  ros::spin();

  return 0;
}