#include <iostream>
#include "../src/IntegerList.hpp"
#include <cppunit/extensions/HelperMacros.h>
#include <string>
using namespace std;


class TestSuite : public CppUnit::TestFixture {

	CPPUNIT_TEST_SUITE(TestSuite);
	CPPUNIT_TEST(IntegerListNodeTests);
	CPPUNIT_TEST_SUITE_END();
	public:
		void IntegerListNodeTests() {
			IntegerListNode n(3);
			CPPUNIT_ASSERT(n.getValue() == 3);
			IntegerListNode * k = new IntegerListNode(4);
			IntegerListNode & ref = *k;
			k->addNext(ref);
			n.addNext(*k);
			CPPUNIT_ASSERT(n.next().getValue() == 4);
		}


};

CPPUNIT_TEST_SUITE_REGISTRATION(TestSuite);


