cmake_minimum_required(VERSION 3.2)
project(thrift_books_catalog)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(gen-cpp)

add_library(tbooks SHARED gen-cpp/books_types.cpp gen-cpp/Catalog.cpp)
target_link_libraries(tbooks thrift)

add_executable(app bin/main.cpp)
target_link_libraries(app thrift tbooks)
