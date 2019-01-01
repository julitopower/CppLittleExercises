cmake_minimum_required(VERSION 2.8)

project(BoostPointers LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

enable_testing()
add_subdirectory(src)
add_subdirectory(test)

add_executable(app main.cpp)
target_link_libraries(app frequencycalculator)

