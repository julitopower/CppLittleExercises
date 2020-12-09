#ifndef INTEGER_LIST_HPP
#define INTEGER_LIST_HPP

#include <functional>
#include <memory>

// Forward declaration
class IntegerListNode;

class IntegerList {
private:
  std::unique_ptr<IntegerListNode> front_;
  IntegerListNode* back_;
  std::size_t size;

public:
  IntegerList();
  ~IntegerList();
  void addValue(int value);

  void traverse(std::function<void(int)> fn) const;
  int front();
  int back();
};

#endif
