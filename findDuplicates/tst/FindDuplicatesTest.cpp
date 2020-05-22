#include "FindDuplicates.hpp"
#include <iostream>
#include <list>
#include <cassert>
#include <cppunit/extensions/HelperMacros.h>
#include <memory>

FindDuplicates processor;

class FindDuplicatesTest : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(FindDuplicatesTest);
  CPPUNIT_TEST(testGivenInputWithSameElement2TimesWhenFindDuplicatesThenResultWithOneElementIsReturned);
  CPPUNIT_TEST(testGivenOneOfTheListsIsEmptyWhenFindDuplicatesThenEmptyListIsReturned);
  CPPUNIT_TEST(testGivenOneCommonElementWhenFindDuplicatesThenCommonElementIsReturned);
  CPPUNIT_TEST_SUITE_END();
 public:
  void testGivenInputWithSameElement2TimesWhenFindDuplicatesThenResultWithOneElementIsReturned() {
    std::list<int> inputA;
    std::list<int> inputB;
    inputA.push_back(1);
    inputA.push_back(1);
    inputB.push_back(1);
    inputB.push_back(1);
    std::unique_ptr<std::list<int>> result = processor.findDuplicates(inputA, inputB);
    assert(result->size() == 1);
    assert(result->front() == 1);

  }

  void testGivenOneCommonElementWhenFindDuplicatesThenCommonElementIsReturned() {
    std::list<int> inputA;
    std::list<int> inputB;
    inputA.push_back(1);
    inputA.push_back(2);
    inputB.push_back(1);
    inputB.push_back(3);
    auto result = processor.findDuplicates(inputA, inputB);
    assert(result->size() == 1);
    assert(result->front() == 1);
  }

  void testGivenOneOfTheListsIsEmptyWhenFindDuplicatesThenEmptyListIsReturned() {
    std::list<int> inputA;
    std::list<int> inputB;
    inputB.push_back(1);
    auto result = processor.findDuplicates(inputA, inputB);
    assert( result->size() == 0);
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(FindDuplicatesTest);
