cmake_minimum_required(VERSION 3.8)
project(topk)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

add_library(topk src/topk.cpp)

add_executable(app bin/app.cpp)
target_link_libraries(app topk)

# Generate Python bindings
add_subdirectory(python)
