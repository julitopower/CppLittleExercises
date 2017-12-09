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
  /* Algorithm

     queueu = Queue{}
     write root_children_nb:root_value
     queue.push(root)
     while queue is not empty {
         node = queue.pop()
         write node.children_nb + :
         for (child in node.childre()) {
             write child_children_nb:child_value:
             queueu.push(child)
         }
     }
  */
}


