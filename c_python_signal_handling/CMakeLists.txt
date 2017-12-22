cmake_minimum_required(VERSION 2.8)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(testing)

set(CMAKE_CXX_STANDARD 11)
add_executable(signal_handling main.cpp)


add_library(l1 SHARED lib.cpp)
set_property(TARGET l1 PROPERTY POSITION_INDEPENDENT_CODE ON)

add_library(l2 SHARED lib.cpp)
set_property(TARGET l1 PROPERTY POSITION_INDEPENDENT_CODE ON)

file(COPY ${CMAKE_SOURCE_DIR}/module.py DESTINATION ${CMAKE_BINARY_DIR})
