project(BoostPointers)
cmake_minimum_required(VERSION 2.8)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_subdirectory(src)
add_subdirectory(test)
add_executable(app main.cpp)
target_link_libraries(app frequencycalculator)

