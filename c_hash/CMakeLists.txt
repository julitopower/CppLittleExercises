cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
project(c_hash)

include_directories(./include)
add_executable(hash main.c)
add_executable(counter counter.c)
