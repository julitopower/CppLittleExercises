include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(test1 test.cpp)
target_link_libraries(test1 tree)
