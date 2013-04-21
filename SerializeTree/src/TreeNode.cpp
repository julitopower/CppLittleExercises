#include "Tree.hpp"
#include <iostream>
#include <exception>
#include <memory>
#include <string>

TreeNode::TreeNode(int value):value(value) {
}

void TreeNode::addChild(TreeNode * node) {
	children.push_back(std::auto_ptr<TreeNode>(node));
}

void TreeNode::addChild(int value) {
	TreeNode * newTree = new TreeNode(value);
	children.push_back(std::auto_ptr<TreeNode>(newTree));
}

void TreeNode::addChild(TreeNode & ref) {
	children.push_back(std::auto_ptr<TreeNode>(&ref));
}

std::list<std::auto_ptr<TreeNode>> & TreeNode::getChildren() {
	return children;
}

void TreeNode::print() {
	std::cout << value << std::endl;
	for(auto it = children.begin(), e = children.end() ; it != e ; it++) {
		(*it)->print();
	}
	std::cout << "-" << std::endl ;	
}

TreeNode::~TreeNode() {
	std::cout << "Calling dedstruct"<< std::endl;
}

TreeNode & TreeNode::read(std::string tree) {
// Need a split string function here: http://stackoverflow.com/questions/236129/splitting-a-string-in-c	
}
