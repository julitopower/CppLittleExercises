cmake_minimum_required(VERSION 3.2)
project(curlclient)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

find_package(CURL)

include_directories(include ${CURL_INCLUDE_DIRS})
add_library(netclient src/netclient.cpp include/netclient.hpp)
target_link_libraries(netclient ${CURL_LIBRARIES})

add_executable(app bin/app.cpp)
target_link_libraries(app netclient)
