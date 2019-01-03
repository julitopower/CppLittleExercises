#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <memory>
#include <ostream>

class TreeNode;
using TreeNodePtr = std::unique_ptr<TreeNode>;

class TreeNode {
public:

  // Alias for payload type
  using type = int;

  // Constructor
  TreeNode(type value);

  // Value accessor
  type GetValue() const;

  // Children accessor
  const std::vector<TreeNodePtr>& GetChildren() const;

  // Children mutator
  void AddChild(TreeNodePtr&& child);
private:
  type m_value;
  std::vector<TreeNodePtr> m_children;
};

// Serialize a tree into a stream
void serialize(const TreeNode& node, std::ostream& os);

#endif
