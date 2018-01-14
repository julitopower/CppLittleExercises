cmake_minimum_required(VERSION 3.2)

project(cpp_matrix_python_wrapper)


find_package( PythonInterp 2.7 REQUIRED )

link_directories(/usr/local/cuda-8.0/lib64/)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(pybind11)

add_executable(matrix2d matrix2d.cpp)

# add_library(example MODULE py_api.cpp)
# target_link_libraries(example PRIVATE pybind11::module api)
# set_target_properties(example PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
#                                            SUFFIX "${PYTHON_MODULE_EXTENSION}")

