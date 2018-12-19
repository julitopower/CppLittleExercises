################################################################################
# Small project demonstrating the use of functional facilities provided by
# STL
################################################################################
cmake_minimum_required(VERSION 3.3)
project(cpp_function LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(main main.cpp)
