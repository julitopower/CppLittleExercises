# Specify minimum CMAKE required
cmake_minimum_required(VERSION 2.8)

# Set your project name
project(FindDupplicates)

include_directories(src)

# Set the folder to output binaries
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/)

# This whole project uses C++11
set(CMAKE_CXX_FLAGS "-std=c++11")

# Enable Testing
enable_testing()

# Finally add the subdirectories containing the compilable files
add_subdirectory(src)
add_subdirectory(tst)
