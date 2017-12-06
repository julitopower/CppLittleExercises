#include "Tree.hpp"

TreeNode::TreeNode(int value) : m_value{value} {};

int TreeNode::GetValue() const {
  return m_value;
}

const std::vector<TreeNodePtr>& TreeNode::GetChildren() const {
  return m_children;
}

void TreeNode::AddChild(TreeNodePtr&& child) {
  m_children.push_back(std::move(child));
}

void serialize(const TreeNode& node, std::ostream& os) {
  
}


