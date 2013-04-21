#ifndef TREE_H
#define TREE_H
#include <list>
#include <memory>
#include <string>

class TreeNode {
	private:
		std::list<std::auto_ptr<TreeNode>> children;
		int value;
	public:
		TreeNode(int value);
		void addChild(TreeNode *);
		void addChild(int value);
		void addChild(TreeNode &);
		std::list<std::auto_ptr<TreeNode>> &  getChildren();
		~TreeNode();
		void print();
		static TreeNode & read(std::string tree);
};

#endif
