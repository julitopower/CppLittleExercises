# Specify your header and source files
set(SRC Main.cpp
        FindDuplicatesTest.cpp)
set(ALL ${SRC} ${HDR})


add_executable(main ${ALL})
TARGET_LINK_LIBRARIES(main cppunit findDuplicatesLib)

add_test(test ${CMAKE_BINARY_DIR}/bin/main)
