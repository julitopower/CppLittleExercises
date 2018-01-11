cmake_minimum_required(VERSION 3.4)
project(gsl_vector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GSL_ROOT_DIR /media/nvidia/development/sources/)
find_package(GSL REQUIRED)
include_directories(${GSL_INCLUDE_DIRS})

add_executable(gsl_vector main.cpp)
target_link_libraries(gsl_vector ${GSL_LIBRARIES})
