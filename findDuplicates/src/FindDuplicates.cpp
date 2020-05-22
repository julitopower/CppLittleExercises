#include <iostream>
#include <list>
#include <map>

#include "FindDuplicates.hpp"

std::unique_ptr<std::list<int>>
FindDuplicates::findDuplicates(std::list<int> & inputA, std::list<int> & inputB) {
  std::unique_ptr<std::list<int>> result(new std::list<int>());
  if (inputA.empty() || inputB.empty()) {
    return result;
  }

  // Build and populate auxiliary map with contents of inputA
  std::map<int, bool> auxMap;
  for (auto it = inputA.begin(), end = inputA.end() ; it != end ; ++it) {
    auxMap[*it] = false ;
  }
  
  // Look for duplicates traversing the second list
  for (auto it = inputB.begin(), end = inputB.end() ; it != end ; ++it) {
    if (auxMap.count(*it) != 0 ) {
      bool alreadyFound = auxMap[*it];
      if (!alreadyFound) {
        result->push_back((*it));
        auxMap[(*it)] = true;
      }
    }
  }
  
  return result;
}

