cmake_minimum_required(VERSION 3.10)
project(MyFirstQtApplication)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})

message(STATUS ${Qt5Widgets_INCLUDE_DIRS})
ADD_DEFINITIONS(${QT_DEFINITIONS})
SET(QT_USE_QTNETWORK TRUE)
SET(QT_USE_QTOPENGL TRUE)
add_subdirectory(src)

