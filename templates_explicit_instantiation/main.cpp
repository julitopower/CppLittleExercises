#include <iostream>
#include "template.hpp"

int main(int argc, char** argv) {

  Julio<int> j{3};
  std::cout << j.data() << std::endl;
}
