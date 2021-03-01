#pragma once

#include <functional>
#include <memory>

// Forward declaration
class IntegerListNode;

/*! \brief Singly linked list with only insertion and traversal

  All insertions happen at the back of the list. This list doesn't
  support deletion of element. Elements are traversed in the order
  in which they were inserted.
 */
class IntegerList {
private:
  // Owning pointer
  std::unique_ptr<IntegerListNode> front_;
  // Non-owning pointer
  IntegerListNode *back_;
  std::size_t size_;

public:
  /* Invariants:
   *   - size() is zero
   *   - front()/back()/traverse(...) throw if called
   */
  IntegerList();
  ~IntegerList();

  /* Invariants:
        - Size is incremented in one
        - front()/back()/traverse(...) can be called safely
        - immediately after this call back() return value
  */
  void addValue(int value);

  /* Traverse the list, executing fn on every element */
  void traverse(std::function<void(int)> fn) const;

  /* Get the value of the element at the front */
  int front() const;
  /* Get the value of the element at the back */
  int back() const;
  /* Get the number of elements in the queue */
  int size() const;
  /* Remove the last element inserted */
  void pop_back();
};
