cmake_minimum_required(VERSION 3.10)

# Project name
project(TrafficManagementSystem)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Define the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../exe)

# Add subdirectories for each component
add_subdirectory(src/traffic)
add_subdirectory(src/vehicle)
add_subdirectory(src/pedestrian)

# Define the include directories
include_directories(src)
