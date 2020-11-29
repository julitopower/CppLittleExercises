#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

#include "topk.hpp"

#define T_START { \
  auto t0 = std::chrono::high_resolution_clock::now();

#define T_END \
  auto t1 = std::chrono::high_resolution_clock::now(); \
  auto span = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count(); \
  std::cout << "Time [ms]: " << span << std::endl; \
}

namespace {
std::vector<int> generate_test_data(std::size_t n, std::size_t seed = 42) {
  std::srand(seed);
  std::vector<int> data(n, 0);
  for (auto i = 0U ; i < n ; ++i) {
    data[i] = std::rand();
  }
  return data;
}
}

int main(int argc, char** argv) {
  std::cout << "Hi there" << std::endl;

  const auto size = 10000000;
  std::vector<int> v = generate_test_data(size, 42);
  auto fn = [](const int& i) {
              return -i;
            };


  auto t = topk::buildTopK(v.begin(), v.end(), fn);

  T_START;
  t.topkmem(10);
  T_END;
    
  for (auto k = 1 ; k < 30 ; ++k) {
    std::cout << "k: " << k << " - ";
    T_START;
    t.topk(k);
    T_END;
  }
  
}
