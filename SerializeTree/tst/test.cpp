#include <iostream>
#include "Tree.hpp"

int main(int argc, char** argv)
{
  auto n1 = TreeNodePtr(new TreeNode(3));
  auto n2 = TreeNodePtr(new TreeNode(4));
  n1->AddChild(std::move(n2));
  n1->AddChild(TreeNodePtr(new TreeNode(8)));
  
  for (const auto& value : n1->GetChildren()) {
    std::cout << value.get() << std::endl;
  }

  return 0;
}
