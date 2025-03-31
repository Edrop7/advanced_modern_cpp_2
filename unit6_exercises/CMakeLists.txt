cmake_minimum_required(VERSION 3.0.2)
project(unit6_exercises)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++17)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp
)


include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(magic_printer_library
  src/magic_printer.cpp
)
add_library(subscriber_basic_library
  src/subscriber_basic.cpp
)
add_library(magic_subscriber_class_library
  src/main_magic_subscriber_class.cpp
)
add_library(magic_subscriber_function_library
  src/main_magic_subscriber_function.cpp
)

## Create executables
add_executable(main_magic_printer_node src/main_magic_printer.cpp)
add_executable(main_subscriber_basic_node src/main_subscriber_basic.cpp)
add_executable(magic_subscriber_class_node src/main_magic_subscriber_class.cpp)
add_executable(magic_subscriber_function_node src/main_magic_subscriber_function.cpp)
add_executable(main_pcl_topic_subscriber_node src/main_pcl_topic_subscriber.cpp)
add_executable(basic_example_u6_specialization_node src/examples/basic_example_u6_specialization.cpp)
add_executable(basic_example_u6_specialization_2_node src/examples/basic_example_u6_specialization_2.cpp)
add_executable(basic_example_u6_specialization_functions_node src/examples/basic_example_u6_specialization_functions.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(main_magic_printer_node
    magic_printer_library
    ${catkin_LIBRARIES}
)
target_link_libraries(main_subscriber_basic_node
	subscriber_basic_library
	${catkin_LIBRARIES}
)
target_link_libraries(magic_subscriber_class_node
	magic_subscriber_class_library
	${catkin_LIBRARIES}
)
target_link_libraries(magic_subscriber_function_node
	magic_subscriber_function_library
	${catkin_LIBRARIES}
)
target_link_libraries(main_pcl_topic_subscriber_node
    magic_subscriber_function_library
    ${catkin_LIBRARIES}
)
target_link_libraries(basic_example_u6_specialization_node
	${catkin_LIBRARIES}
)
target_link_libraries(basic_example_u6_specialization_2_node
	${catkin_LIBRARIES}
)
target_link_libraries(basic_example_u6_specialization_functions_node
	${catkin_LIBRARIES}
)