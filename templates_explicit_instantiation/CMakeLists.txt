cmake_minimum_required(VERSION 3.3)

project(templates)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main main.cpp template_inst.cpp)
