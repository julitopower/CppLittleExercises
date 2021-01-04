cmake_minimum_required(VERSION 3.2)
project(ObserverPattern)

set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

add_library(observer src/Observer.cpp src/Observable.cpp src/Event.cpp)

add_executable(app bin/main.cpp)
target_link_libraries(app observer)
