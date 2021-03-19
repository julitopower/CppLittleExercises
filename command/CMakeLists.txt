cmake_minimum_required(VERSION 3.2)
project(command)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(command command.cpp)

add_executable(app main.cpp)
target_link_libraries(app command pthread)
