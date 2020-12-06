/*
 * This file is used to launch all the tests using cppUnit
 */
#include <iostream>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>

int main(int argc, char** argv) {
	// Enable reporting
	CppUnit::TestResult controller;

 	 //--- Add a listener that colllects test result
	CppUnit::TestResultCollector result;
  	controller.addListener( &result );        

	//--- Add a listener that print dots as test run.
	CppUnit::BriefTestProgressListener progress;
  
	controller.addListener( &progress );      	
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry & registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest( registry.makeTest() );
	runner.run(controller);
	return 0;
}
