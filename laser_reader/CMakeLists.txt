cmake_minimum_required(VERSION 3.0.2)
project(laser_reader)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES laser_reader
#  CATKIN_DEPENDS roscpp sensor_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(laser_reader src/laser_reader.cpp)
target_link_libraries(laser_reader ${catkin_LIBRARIES})

add_executable(laser_subscriber src/laser_subscriber.cpp)
target_link_libraries(laser_subscriber ${catkin_LIBRARIES})