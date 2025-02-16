cmake_minimum_required(VERSION 3.10)
project(RobotDrawProject)

set(CMAKE_CXX_STANDARD 17)

# Add include directory
include_directories(include)

# Collect all source files
file(GLOB SOURCES "modules/*/*.cpp")

# Compile all source files and move the executable to the bin directory
add_executable(robot_draw main.cpp ${SOURCES})
set_target_properties(robot_draw PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../bin)