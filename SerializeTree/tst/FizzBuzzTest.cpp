#include <iostream>
#include "../src/Tree.hpp"
#include <cppunit/extensions/HelperMacros.h>
#include <string>
using namespace std;


class FizzBuzzTest : public CppUnit::TestFixture {

	CPPUNIT_TEST_SUITE(FizzBuzzTest);
	CPPUNIT_TEST(testPrintTree);
	CPPUNIT_TEST_SUITE_END();
	public:
		void testPrintTree() {
			TreeNode root(0);
			TreeNode * pChild = new TreeNode(45);
			root.addChild(new TreeNode(1));
			root.addChild(3);
			root.addChild(*pChild);
			CPPUNIT_ASSERT_EQUAL (1,1);
			cout << endl;
			root.print();
		}
};

CPPUNIT_TEST_SUITE_REGISTRATION(FizzBuzzTest);

