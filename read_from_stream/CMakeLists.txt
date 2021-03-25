cmake_minimum_required(VERSION 3.2)
project(app)

add_library(stream stream.cpp)
add_executable(app main.cpp)
target_link_libraries(app stream)
