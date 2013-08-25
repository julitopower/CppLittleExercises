#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP
#include <vector>

class BinarySearcher {
public:
	BinarySearcher();
	int searchIterative(int value, int array[], unsigned int size);
	int searchRecursive(int value, int array[], unsigned int size);
	int searchRecursiveII(int value, int array[], unsigned int size);
	int searchVectorIter(int value, std::vector<int> & container);

private:
	// Do not allow copy
	BinarySearcher(const BinarySearcher & that);
	// Do not assignment
	BinarySearcher * operator=(const BinarySearcher & that);

	int searchRecursive_(int value, int array[], int ini, int end);
};
#endif
