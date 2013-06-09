#include "BinarySearch.hpp"
#include <iostream>
using namespace std;

BinarySearcher::BinarySearcher() {}

void arrayCopy(int * source, int * destination, int ini, int end) {
	int destIndex = 0;
	while(ini <= end) {
		destination[destIndex++] = source[ini++];
	}
}

int BinarySearcher::searchVectorIter(int value, std::vector<int> & container){
	int ini = 0;
	int end = container.size() - 1;
	while(ini <= end) {
		int mid = (end + ini) / 2;
		if (value == container.at(mid)) {
			return mid;
		} else if (value < container.at(mid)) {
			end = mid -1;
		} else {
			ini = mid + 1;
		}
	}

	return -1;
}

int BinarySearcher::searchIterative(int value, int array[], unsigned int size) {
	int ini = 0;
	int end = size - 1;
	while (ini <= end) {
		int mid = (end + ini) / 2;
		if (array[mid] == value) {
			return mid;
		} else if (value < array[mid]) {
			end = mid - 1;
		} else {
			ini = mid + 1;
		}
	}

	return -1;
}

int BinarySearcher::searchRecursive(int value, int array[], unsigned int size) {
	//Sanity check
	if (size == 0) {
		return -1;
	}

	int mid = (size-1)/2;
	if (value == array[mid]) {
		return mid;
	} else if (value < array[mid]) {
		int aux[mid];
		arrayCopy(array, aux, 0, mid-1);
		return searchRecursive(value, aux,mid);
	} else {
		int aux[size - (mid+1)];
		arrayCopy(array, aux, mid+1, size - 1);
		int res =  searchRecursive(value, aux, size - (mid+1));
		return (res < 0)? res : res + mid + 1;
	}
	return -1;
}

int BinarySearcher::searchRecursiveII(int value, int array[], unsigned int size) {
	if(size == 0) return -1;
	return searchRecursive_(value,array,0, size-1);
}

int BinarySearcher::searchRecursive_(int value, int array[], int ini, int end){
	//Base case
	if (ini > end) {
		return -1;
	}

	int mid = (end + ini) / 2;
	if (array[mid] == value) {
		return mid;
	} else if (value < array[mid]) {
		end = mid - 1;
	} else {
		ini = mid + 1;
	}

	return searchRecursive_(value,array,ini,end);
}
