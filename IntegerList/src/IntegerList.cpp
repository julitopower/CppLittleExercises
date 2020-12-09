#include <memory>


#include "IntegerList.hpp"

class IntegerListNode {
private:
  int value_;
  std::unique_ptr<IntegerListNode> nextNode_;

public:
  IntegerListNode(int value) : value_{value} {};
  IntegerListNode& next() {
    return *nextNode_;
  }
  
  int getValue() const {
    return value_;
  }

  /**
   * Takes ownership of the node passed as argument
   */
  void addNext(std::unique_ptr<IntegerListNode>&& next) {
    nextNode_.swap(next);
  }
};

void IntegerList::addValue(int value) {
  auto node = std::make_unique<IntegerListNode>(value);
  if (!front_) {
    front_.swap(node);
    back_ = front_.get();
  } else {
    back_->addNext(std::move(node));
    back_ = &(back_->next());
  }
}

void IntegerList::traverse(std::function<void(int)> fn) const {
  IntegerListNode* next = front_.get();
  while (next) {
    fn(next->getValue());
    next = &(next->next());
  }
}

IntegerList::IntegerList() {}
IntegerList::~IntegerList() {}
