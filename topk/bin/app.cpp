#include <iostream>
#include <vector>

#include "topk.hpp"

int main(int argc, char** argv) {
  std::cout << "Hi there" << std::endl;

  std::vector<int> v{3, 2, 5, 4, 1};
  auto fn = [](const int& i) {
              return (i < 3) ? (i + 2) : -i;
            };
  
  auto t = topk::buildTopK(v.begin(), v.end(), fn);

  for (auto& v : t.topk(5)) {
    std::cout << v << std::endl;
  }
  
}
