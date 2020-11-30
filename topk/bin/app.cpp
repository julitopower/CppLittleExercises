#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <cassert>

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
  std::cout << "Topk algorithm" << std::endl;

  const auto size = 10000000;
  std::vector<int> data = generate_test_data(size, 42);
  auto fn = [](const int& i) {
              return -i;
            };


  auto t = topk::buildTopK(data.begin(), data.end(), fn);

  const auto maxk = 30;
  std::vector<int> mem;
  T_START;
  mem = t.topkmem(maxk);
  T_END;
    
  for (auto k = 1 ; k <= maxk ; ++k) {
    std::cout << "k: " << k << " - ";
    T_START;
    const auto buff = t.topkbuffer(k);
    // Check that results are the same
    for (auto i = 0U ; i < k ; ++i) {
      assert(buff[i] == mem[i]);
    }
    T_END;
  }
  
}
