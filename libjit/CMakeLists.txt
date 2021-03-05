################################################################################
# Libjit example
#
# See: https://www.gnu.org/software/libjit/
################################################################################
cmake_minimum_required(VERSION 3.10)
project(jittest)

add_executable(app main.cpp)
target_link_libraries(app jit)
