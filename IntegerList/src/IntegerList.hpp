#ifndef INTEGER_LIST_HPP
#define INTEGER_LIST_HPP

class IntegerListNode {
private:
	int value;
	IntegerListNode * nextNode;
public:
	IntegerListNode(int value);
	IntegerListNode & next();
	int getValue();
	void addNext(IntegerListNode & next);
	~IntegerListNode();
};

class IntegerList {
private:
	IntegerListNode * root;
	int size;
public:
	IntegerList();
};

#endif
