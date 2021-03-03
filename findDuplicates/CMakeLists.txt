# Specify minimum CMAKE required
cmake_minimum_required(VERSION 3.2)

# Set your project name
project(FindDupplicates)
set(CMAKE_CXX_STANDARD 11)

include_directories(src)

# Set the folder to output binaries
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/)

# Enable Testing
enable_testing()

# Finally add the subdirectories containing the compilable files
add_subdirectory(src)
add_subdirectory(tst)
