################################################################################
# Example usage of cJSON 3rd party library
################################################################################
CMAKE_minimum_required(VERSION 3.0)

project(json)

add_library(cjson SHARED cJSON.c)

add_executable(main main.c)
target_link_libraries(main cjson)
