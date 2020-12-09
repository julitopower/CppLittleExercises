#include <iostream>

#include "IntegerList.hpp"

int main(int argc, char *argv[])
{
  IntegerList list;
  for (auto i = 0U ; i < 100 ; ++i) {
    list.addValue(i);
  }

  list.traverse([](auto val) { std::cout << val << "\n"; });

  return 0;
}
