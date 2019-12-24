cmake_minimum_required(VERSION 3.4)
project(kinematics)

set(CMAKE_CXX_STANDARD 11)

# all include libraries
include_directories(include)

# Robot library
add_library(kinematics_lib SHARED include/Kinematics.h src/Kinematics.c 
                        include/Tests.h src/Tests.c
                        include/Util.h src/Util.c)

# Lab 3: using the robot class
# Lab 4: sensors on robot
add_executable(kinematics src/main.c)
target_link_libraries(kinematics kinematics_lib m)