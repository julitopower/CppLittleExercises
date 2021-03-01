#include <memory>
#include <stdexcept>

#include "IntegerList.hpp"

class IntegerListNode {
private:
  int value_;
  std::unique_ptr<IntegerListNode> nextNode_;

public:
  IntegerListNode(int value) : value_{value} {};
  IntegerListNode &next() const { return *nextNode_; }

  int getValue() const { return value_; }

  /**
   * Takes ownership of the node passed as argument
   */
  void addNext(std::unique_ptr<IntegerListNode> &&next) {
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
  ++size_;
}

void IntegerList::traverse(std::function<void(int)> fn) const {
  IntegerListNode *next = front_.get();
  while (next) {
    fn(next->getValue());
    next = &(next->next());
  }
}

int IntegerList::front() const {
  if (size_ > 0) {
    return front_->getValue();
  } else {
    throw std::logic_error{"List is empty"};
  }
}

int IntegerList::back() const {
  if (size_ > 0) {
    return back_->getValue();
  } else {
    throw std::logic_error{"List is empty"};
  }
}

int IntegerList::size() const { return size_; }

IntegerList::IntegerList() {}
IntegerList::~IntegerList() {}
