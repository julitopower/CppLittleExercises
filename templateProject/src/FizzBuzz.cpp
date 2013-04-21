#include <iostream>
#include <string>
#include "FizzBuzz.hpp"
using namespace std;

#ifndef TEST
int main(int argc, char** argv) {
	cout << fizzBuzz(3) << endl;	
	return 0;	
}
#endif

string fizzBuzz(int value) {
	string aux;
	if (value%3 == 0) {
		aux = "Fizz";
	}
	if (value%5 == 0) {
		aux += "Buzz";
	}
	return aux;
}
