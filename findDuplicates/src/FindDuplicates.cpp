#include "FindDuplicates.hpp"
#include <list>
#include <map>
#include <iostream>
#include <memory>
using namespace std;

auto_ptr<list<int>> FindDuplicates::findDuplicates(list<int> & inputA, list<int> & inputB) {
	auto_ptr<list<int>> result(new list<int>());
	if (inputA.empty() || inputB.empty()) {
		return result;
	}

	// Build and populate auxiliary map with contents of inputA
	map<int, bool> auxMap;
	for(auto it = inputA.begin(), end = inputA.end() ; it != end ; it++) {
		auxMap[(*it)] = false ;
	}
	
	// Lood for duplicates traversing the second list
	for(auto it = inputB.begin(), end = inputB.end() ; it != end ; it++) {
		if ( auxMap.count((*it)) != 0 ) {
			bool alreadyFound = auxMap[(*it)];
			if (!alreadyFound) {
				result->push_back((*it));
				auxMap[(*it)] = true;
			}
		}
	}
	
	return result;
}

