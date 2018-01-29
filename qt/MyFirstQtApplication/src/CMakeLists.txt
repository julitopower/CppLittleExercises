set(HDS Window.hpp)
set(SRC main.cpp Window.cpp)
add_executable(${PROJECT_NAME} ${SRC})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Widgets Qt5::Core)
