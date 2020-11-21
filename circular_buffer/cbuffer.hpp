#pragma once
#include <vector>
#include <cassert>

template <typename T>
class CBuffer {
 public:
  CBuffer(std::size_t capacity, T value) : buffer_(capacity, value), 
                                           init_(buffer_.begin()),
                                           end_(buffer_.begin()) {
    assert(capacity > 0);
  }

  void push(T value) {
    // end_ is always in a valid position for insertion
    *end_ = value;
    ++end_;
    if (end_ == buffer_.end()) {
      end_ = buffer_.begin();
    }
    ++size_;

    if (size_ > buffer_.size()) {
      pop();
    }
  }

  void pop() {
    // drop the oldest element, which is always placed in init_
    if (size_ == 0) {
      return;
    }   
    ++init_;
    if (init_ == buffer_.end()) {
      init_ = buffer_.begin();
    }
    --size_;
  }

  T peek() {
    assert(size_ > 0);
    return *init_;
  }

  template <typename K>
  friend std::ostream& operator<<(std::ostream& os, const CBuffer<K>& cbuffer);

 private:
  std::vector<T> buffer_;
  decltype(std::declval<std::vector<T>>().begin()) init_;
  decltype(std::declval<std::vector<T>>().begin()) end_;
  std::size_t size_ = 0;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const CBuffer<T>& cbuffer) {
  if (cbuffer.size_ == 0) {
    return os;
  }
  auto end = (cbuffer.end_ > cbuffer.init_) ? cbuffer.end_ : cbuffer.buffer_.end();
  for (auto it = cbuffer.init_ ; it != end ; ++it) {
    std::cout << *it << ", ";
  }

  if (end == cbuffer.buffer_.end()) {

    for (auto it = cbuffer.buffer_.begin() ; it != cbuffer.end_ ; ++it) {
      std::cout << *it << ", ";
    }
  }

  std::cout << std::endl;
  return os;
}
