#include "IntegerList.hpp"
#include <iostream>

using namespace std;
IntegerListNode::IntegerListNode(int value){
	this->value = value;
	this->nextNode = 0;
}

IntegerListNode & IntegerListNode::next() {
	return *(this->nextNode);
}  

IntegerListNode::~IntegerListNode(){
	if (this != nextNode) {
		delete(nextNode);
	}
}

int IntegerListNode::getValue() {
	return this->value;
}

void IntegerListNode::addNext(IntegerListNode & next) {
	nextNode = &next;
}
