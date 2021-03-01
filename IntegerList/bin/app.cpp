#include <cassert>
#include <iostream>

#include "IntegerList.hpp"

int main(int, char **) {
  constexpr auto N = 100;
  IntegerList list{};

  for (auto i = 0; i < N; ++i) {
    assert(list.size() == i);
    // Check the size invariant
    list.addValue(i);
  }
  assert(list.size() == N);

  list.traverse([](auto val) { std::cout << val << " "; });

  return 0;
}
