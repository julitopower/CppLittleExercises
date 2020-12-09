cmake_minimum_required(VERSION 3.2)
project(integerlist)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_library(integerlist src/IntegerList.cpp)

add_executable(app bin/app.cpp)
target_link_libraries(app integerlist)
