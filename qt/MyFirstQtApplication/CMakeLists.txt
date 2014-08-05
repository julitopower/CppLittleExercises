project(MyFirstQtApplication)
cmake_minimum_required(VERSION 2.8)
find_package(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
SET(QT_USE_QTNETWORK TRUE)
SET(QT_USE_QTOPENGL TRUE)
add_subdirectory(src)

