cmake_minimum_required(VERSION 3.0)

project(c_hash LANGUAGES C)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()
set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

include_directories(include)

add_executable(hash main.c)
add_executable(counter counter.c)
