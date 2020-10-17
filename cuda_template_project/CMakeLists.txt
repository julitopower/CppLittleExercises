cmake_minimum_required(VERSION 3.8)

project(cuda_example LANGUAGES CXX CUDA)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED 14)

add_library(cu_app_obj OBJECT main.cu)
set_property(TARGET cu_app_obj PROPERTY CUDA_PTX_COMPILATION ON)

add_executable(app main.cpp main.cu)


