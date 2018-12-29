#include <iostream>
#include "template.hpp"

int main(int argc, char** argv) {

  Julio<int> int_instantiation{3};
  std::cout << int_instantiation.data() << std::endl;

  Julio<float> float_instantiation{3.8};
  std::cout << float_instantiation.data() << std::endl;
}
