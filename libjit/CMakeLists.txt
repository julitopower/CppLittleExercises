cmake_minimum_required(VERSION 3.10)
project(jittest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(app main.cpp)
target_link_libraries(app jit)
