cmake_minimum_required(VERSION 3.2)

project(mxnet_cpp)

add_definitions(-DMSHADOW_USE_CBLAS -DMSHADOW_USE_SSE=0)
include_directories(
  /usr/local/cuda-8.0/include
  /media/nvidia/development/sources/incubator-mxnet/include
  /media/nvidia/development/sources/incubator-mxnet/dmlc-core/include
  /media/nvidia/development/sources/incubator-mxnet/mshadow
  /media/nvidia/development/sources/incubator-mxnet/nnvm/include
  /media/nvidia/development/sources/incubator-mxnet/dlpack/include    
  /media/nvidia/development/sources/incubator-mxnet/cpp-package/include
  )

################################################################################
# TODO: Make this variables the user can set
################################################################################
link_directories(
  /media/nvidia/development/sources/incubator-mxnet/lib/
  /usr/local/cuda-8.0/lib64/
  )

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 14)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

add_executable(mxnet_c_api_cpu main_cpu.cpp)
target_link_libraries(mxnet_c_api_cpu mxnet)

add_executable(mxnet_cpp_api_gpu main_gpu.cpp)
target_link_libraries(mxnet_cpp_api_gpu mxnet cuda cudart)
