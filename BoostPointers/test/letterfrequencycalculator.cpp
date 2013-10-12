#define BOOST_TEST_MODULE MyTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/letterfrequencycalculator.h"
#include <string>

BOOST_AUTO_TEST_CASE(test1)
{
    freq::LetterFrequencyCalculator calculator;
    std::string value("shit");
    BOOST_CHECK_EQUAL(0,calculator.calculate(value, 'c'));
}

BOOST_AUTO_TEST_CASE(oneInFour)
{
    freq::LetterFrequencyCalculator calculator;
    std::string value("shit");
    BOOST_CHECK_EQUAL(25, calculator.calculate(value, 't'));
}

BOOST_AUTO_TEST_CASE(allequal)
{
    freq::LetterFrequencyCalculator calculator;
    std::string value("tttt");
    BOOST_CHECK_EQUAL(100, calculator.calculate(value, 't'));
}

BOOST_AUTO_TEST_CASE(emptyString)
{
    freq::LetterFrequencyCalculator calculator;
    std::string value("");
    BOOST_CHECK_EQUAL(0, calculator.calculate(value, 't'));
}
