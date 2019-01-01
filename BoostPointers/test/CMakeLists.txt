set(TESTS letterfrequencycalculator.cpp)

include(CTest)
add_executable(test_bin ${TESTS})
target_link_libraries(test_bin ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} frequencycalculator)
add_test(test1 test_bin)
