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

link_directories(
  /media/nvidia/development/sources/incubator-mxnet/lib/
  /usr/local/cuda-8.0/lib64/
  )

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 11)

add_executable(julio main.cpp)
target_link_libraries(julio mxnet cuda cudart)
