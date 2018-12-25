cmake_minimum_required(VERSION 3.2)

################################################################################
# GENERAL PROJECT SETUP
################################################################################
project(cpp_matrix_python_wrapper LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 14)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

################################################################################
# SETUP DEPENDENCIES
################################################################################
find_package(PythonInterp 2.7 REQUIRED)
find_library(CBLAS cblas /usr/lib/)
if(NOT CBLAS)
  message(FATAL_ERROR "Required library CBLAS ${CBLAS}")
endif()
################################################################################
# ADD PYBIND 11
################################################################################
add_subdirectory(pybind11)

################################################################################
# THE ACTUAL TARGETS
################################################################################
add_executable(matrix2d matrix2d.cpp)
target_link_libraries(matrix2d ${CBLAS})
add_library(matrix2d_lib matrix2d.cpp)
target_link_libraries(matrix2d_lib)

################################################################################
# THE PYTHON WRAPPER
################################################################################
pybind11_add_module(cpp_matrix py_matrix.cpp)
target_link_libraries(cpp_matrix PRIVATE matrix2d_lib ${CBLAS})

################################################################################
# This is another way to build the Python wrapper using CMake and Pybind11. It
# is here for reference purposes.
#
# add_library(example MODULE py_api.cpp)
# target_link_libraries(example PRIVATE pybind11::module api)
# set_target_properties(example PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
#                                            SUFFIX "${PYTHON_MODULE_EXTENSION}")
################################################################################
install(FILES script.py DESTINATION ${CMAKE_BINARY_DIR})
