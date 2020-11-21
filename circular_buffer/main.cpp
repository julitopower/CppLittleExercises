#include <iostream>
#include "cbuffer.hpp"

int main(int argc, char** argv) {
  std::cout << "Hello world" << std::endl;

  CBuffer<std::int32_t> b(3, 0);

  // Print the buffer as it gets full
  std::cout << b;
  for (auto i = 0U ; i < 10 ; ++i) {
    b.push(i);
    std::cout << b;
  }

  // Print the buffer as we empty it
  for (auto i = 0U ; i < 10 ; ++i) {
    b.pop();
    std::cout << b;
  }

}
