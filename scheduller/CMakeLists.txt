cmake_minimum_required(VERSION 3.8)
project(scheduller)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SRC_DIR})
add_executable(app main.cpp task.cpp)
