#include <iostream>
#include "../src/BinarySearch.hpp"
#include <cppunit/extensions/HelperMacros.h>
#include <string>
using namespace std;

class BinarySearchTest: public CppUnit::TestFixture {

	BinarySearcher * searcher;

	// Define the class containing the tests
	CPPUNIT_TEST_SUITE (BinarySearchTest);
	// Define the tests to be executed
	CPPUNIT_TEST (testSearchIterInEmptyArray);
	CPPUNIT_TEST (testSearchIterInOneElementArrayFound);
	CPPUNIT_TEST (testSearchIterInOneElementArrayNotFound);
	CPPUNIT_TEST (testSearchIterInEvenArray);
	CPPUNIT_TEST (testSearchIterInOddArray);

	CPPUNIT_TEST (testSearchRecursiveInEmptyArray);
	CPPUNIT_TEST (testSearchRecursiveInOneElementArrayFound);
	CPPUNIT_TEST (testSearchRecursiveInOneElementArrayNotFound);
	CPPUNIT_TEST (testSearchRecursiveInEvenArray);
	CPPUNIT_TEST (testSearchRecursiveInOddArray);

	CPPUNIT_TEST (testSearchRecursiveIIInEmptyArray);
	CPPUNIT_TEST (testSearchRecursiveIIInOneElementArrayFound);
	CPPUNIT_TEST (testSearchRecursiveIIInOneElementArrayNotFound);
	CPPUNIT_TEST (testSearchRecursiveIIInEvenArray);
	CPPUNIT_TEST (testSearchRecursiveIIInOddArray);

	CPPUNIT_TEST (testSearchVectorIterInEmptyArray);
	CPPUNIT_TEST (testSearchVectorIterInOneElementArrayFound);
	CPPUNIT_TEST (testSearchVectorIterInOneElementArrayNotFound);
	CPPUNIT_TEST (testSearchVectorIterInEvenArray);
	CPPUNIT_TEST (testSearchVectorIterInOddArray);
	CPPUNIT_TEST_SUITE_END();
public:
	void testSearchIterInEmptyArray() {
		int array[] = { };
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchIterative(2, array, 0));
	}

	void testSearchIterInOneElementArrayFound() {
		int array[] = {1};
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchIterative(1, array, 1));
	}

	void testSearchIterInOneElementArrayNotFound() {
		int array[] = {1};
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchIterative(2, array, 1));
	}

	void testSearchIterInEvenArray() {
		int array[] = {1,2,3,4};
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchIterative(1, array, 4));
		CPPUNIT_ASSERT_EQUAL(1, searcher->searchIterative(2, array, 4));
		CPPUNIT_ASSERT_EQUAL(2, searcher->searchIterative(3, array, 4));
		CPPUNIT_ASSERT_EQUAL(3, searcher->searchIterative(4, array, 4));
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchIterative(90, array, 4));
	}

	void testSearchIterInOddArray() {
		int array[] = {1,2,3,4,5};
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchIterative(1, array, 5));
		CPPUNIT_ASSERT_EQUAL(1, searcher->searchIterative(2, array, 5));
		CPPUNIT_ASSERT_EQUAL(2, searcher->searchIterative(3, array, 5));
		CPPUNIT_ASSERT_EQUAL(3, searcher->searchIterative(4, array, 5));
		CPPUNIT_ASSERT_EQUAL(4, searcher->searchIterative(5, array, 5));
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchIterative(90, array, 5));
	}

	void testSearchRecursiveInEmptyArray() {
		int array[] = { };
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchRecursive(2, array, 0));
	}

	void testSearchRecursiveInOneElementArrayFound() {
		int array[] = {1};
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchRecursive(1, array, 1));
	}

	void testSearchRecursiveInOneElementArrayNotFound() {
		int array[] = {1};
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchRecursive(2, array, 1));
	}

	void testSearchRecursiveInEvenArray() {
		int array[] = {1,2,3,4};
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchRecursive(1, array, 4));
		CPPUNIT_ASSERT_EQUAL(1, searcher->searchRecursive(2, array, 4));
		CPPUNIT_ASSERT_EQUAL(2, searcher->searchRecursive(3, array, 4));
		CPPUNIT_ASSERT_EQUAL(3, searcher->searchRecursive(4, array, 4));
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchRecursive(90, array, 4));
	}

	void testSearchRecursiveInOddArray() {
		int array[] = {1,2,3,4,5};
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchRecursive(1, array, 5));
		CPPUNIT_ASSERT_EQUAL(1, searcher->searchRecursive(2, array, 5));
		CPPUNIT_ASSERT_EQUAL(2, searcher->searchRecursive(3, array, 5));
		CPPUNIT_ASSERT_EQUAL(3, searcher->searchRecursive(4, array, 5));
		CPPUNIT_ASSERT_EQUAL(4, searcher->searchRecursive(5, array, 5));
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchRecursive(90, array, 5));
	}

	void testSearchRecursiveIIInEmptyArray() {
		int array[] = { };
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchRecursiveII(2, array, 0));
	}

	void testSearchRecursiveIIInOneElementArrayFound() {
		int array[] = {1};
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchRecursiveII(1, array, 1));
	}

	void testSearchRecursiveIIInOneElementArrayNotFound() {
		int array[] = {1};
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchRecursiveII(2, array, 1));
	}

	void testSearchRecursiveIIInEvenArray() {
		int array[] = {1,2,3,4};
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchRecursiveII(1, array, 4));
		CPPUNIT_ASSERT_EQUAL(1, searcher->searchRecursiveII(2, array, 4));
		CPPUNIT_ASSERT_EQUAL(2, searcher->searchRecursiveII(3, array, 4));
		CPPUNIT_ASSERT_EQUAL(3, searcher->searchRecursiveII(4, array, 4));
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchRecursiveII(90, array, 4));
	}

	void testSearchRecursiveIIInOddArray() {
		int array[] = {1,2,3,4,5};
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchRecursiveII(1, array, 5));
		CPPUNIT_ASSERT_EQUAL(1, searcher->searchRecursiveII(2, array, 5));
		CPPUNIT_ASSERT_EQUAL(2, searcher->searchRecursiveII(3, array, 5));
		CPPUNIT_ASSERT_EQUAL(3, searcher->searchRecursiveII(4, array, 5));
		CPPUNIT_ASSERT_EQUAL(4, searcher->searchRecursiveII(5, array, 5));
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchRecursiveII(90, array, 5));
	}

	/////

	void testSearchVectorIterInEmptyArray() {
		std::vector<int> array;
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchVectorIter(2, array));
	}

	void testSearchVectorIterInOneElementArrayFound() {
		std::vector<int> array;
		array.push_back(1);
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchVectorIter(1, array));
	}

	void testSearchVectorIterInOneElementArrayNotFound() {
		std::vector<int> array;
		array.push_back(1);
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchVectorIter(2, array));
	}

	void testSearchVectorIterInEvenArray() {
		std::vector<int> array;
		array.push_back(1);
		array.push_back(2);
		array.push_back(3);
		array.push_back(4);
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchVectorIter(1, array));
		CPPUNIT_ASSERT_EQUAL(1, searcher->searchVectorIter(2, array));
		CPPUNIT_ASSERT_EQUAL(2, searcher->searchVectorIter(3, array));
		CPPUNIT_ASSERT_EQUAL(3, searcher->searchVectorIter(4, array));
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchVectorIter(90, array));
	}

	void testSearchVectorIterInOddArray() {
		std::vector<int> array;
		array.push_back(1);
		array.push_back(2);
		array.push_back(3);
		array.push_back(4);
		array.push_back(5);
		CPPUNIT_ASSERT_EQUAL(0, searcher->searchVectorIter(1, array));
		CPPUNIT_ASSERT_EQUAL(1, searcher->searchVectorIter(2, array));
		CPPUNIT_ASSERT_EQUAL(2, searcher->searchVectorIter(3, array));
		CPPUNIT_ASSERT_EQUAL(3, searcher->searchVectorIter(4, array));
		CPPUNIT_ASSERT_EQUAL(4, searcher->searchVectorIter(5, array));
		CPPUNIT_ASSERT_EQUAL(-1, searcher->searchVectorIter(90, array));
	}

	void setUp() {
		searcher = new BinarySearcher();
	}

	void tearDown() {
		delete searcher;
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION (BinarySearchTest);

