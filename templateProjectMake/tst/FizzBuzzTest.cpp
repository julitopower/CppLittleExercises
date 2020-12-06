#include <iostream>
#include "../src/FizzBuzz.hpp"
#include <cppunit/extensions/HelperMacros.h>
#include <string>
using namespace std;


class FizzBuzzTest : public CppUnit::TestFixture {

	CPPUNIT_TEST_SUITE(FizzBuzzTest);
	CPPUNIT_TEST(testGiven3WhenFizzBuzzThenFizz);
	CPPUNIT_TEST(testGive5WhenFizzBuzzThenBuzz);
	CPPUNIT_TEST(testGiven15WhenFizzBuzzThenFizzBuzz);
	CPPUNIT_TEST_SUITE_END();
	public:
		void testGiven3WhenFizzBuzzThenFizz() {
			CPPUNIT_ASSERT_EQUAL ( string("Fizz"), fizzBuzz(3) );
		}

		void testGive5WhenFizzBuzzThenBuzz() {
			CPPUNIT_ASSERT_EQUAL ( string("Buzz"), fizzBuzz(5) );

		}

		void testGiven15WhenFizzBuzzThenFizzBuzz() {
			CPPUNIT_ASSERT_EQUAL ( string("FizzBuzz"), fizzBuzz(15) );
		}
};

CPPUNIT_TEST_SUITE_REGISTRATION(FizzBuzzTest);

