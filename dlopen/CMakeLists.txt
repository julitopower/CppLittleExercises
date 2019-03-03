cmake_minimum_required(VERSION 3.0)
project(dlopen)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

set(CMAKE_CXX_STANDARD 14)

# Generate RPATH at build time
SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
# We want the two libraries in the same folder
set(CMAKE_INSTALL_RPATH "$ORIGIN")
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

################################################################################
# Becuase l2 depends on l1, when l2 is loaded
# via RPATH l1 will be found
################################################################################
add_library(l1 SHARED lib1.cpp)
add_library(l2 SHARED lib2.cpp)
target_link_libraries(l2 l1)

################################################################################
# The executable knows nothing about the location
# of the libraries. It uses dlopen, and relies on
# the loader to be able to find the dependencies
################################################################################
add_executable(app main.cpp)
target_link_libraries(app dl)
