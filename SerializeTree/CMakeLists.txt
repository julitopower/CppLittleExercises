cmake_minimum_required(VERSION 3.0)

project(serialize_tree)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

enable_testing()

add_subdirectory(src)
add_subdirectory(bin)
add_subdirectory(tst)




 
