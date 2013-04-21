#ifndef FIND_DUPLICATES_H
#define FIND_DUPLICATES_H

#include <list>
#include <memory>

using namespace std;

class FindDuplicates {
	public:
		auto_ptr<list<int>> findDuplicates(list<int> & inputA, list<int> & inputB);
};

#endif


