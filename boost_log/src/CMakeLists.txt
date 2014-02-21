SET(SRC main.cpp)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

ADD_EXECUTABLE(APP ${SRC})
TARGET_LINK_LIBRARIES(APP /tmp/lib/libboost_log.so /tmp/lib/libboost_system.so /tmp/lib/libboost_thread.so pthread)