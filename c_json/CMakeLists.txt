################################################################################
# Example usage of cJSON 3rd party library
################################################################################
CMAKE_minimum_required(VERSION 3.2)
project(json LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

add_library(cjson SHARED cJSON.c)

add_executable(main main.c)
target_link_libraries(main cjson)
