cmake_minimum_required(VERSION 3.8)

project(cuda_matmul LANGUAGES CXX CUDA)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CUDA_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CUDA_CXX_STANDARD_REQUIRED True)

set(CMAKE_VERBOSE_MAKEFILE ON)

# Generate the cuda PTX file. 
add_library(cu_app_obj OBJECT main.cu main.cuh)
set_property(TARGET cu_app_obj PROPERTY CUDA_PTX_COMPILATION ON)

add_library(cuMatMul STATIC main.cu main.cuh)
set_target_properties(cuMatMul
                       PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(app main.cpp)
target_link_libraries(app PRIVATE cuMatMul)



