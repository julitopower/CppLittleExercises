CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
project(png_test CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

################################################################################
# Default build type: Release with Debug info
################################################################################
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

################################################################################
# Find Libpng
################################################################################
find_package(PNG REQUIRED)

message(STATUS "PNG headers found in ${PNG_INCLUDE_DIR}")
include_directories(${PNG_INCLUDE_DIR})

set(SRC main.cpp)
add_executable(demo ${SRC})
target_link_libraries(demo ${PNG_LIBRARIES})
