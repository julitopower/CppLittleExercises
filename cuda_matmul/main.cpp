#include <iostream>
#include <vector>

#include "main.cuh"

namespace {
void init(std::vector<float>& v, float value) {
  for (auto it = v.begin() ; it != v.end() ; ++it) {
    *it = value;
  }
}

template <typename T>
void print(const T& v) {
  for (auto value : v) {
    std::cout << value << ", ";
  }
  std::cout << std::endl << std::endl;;
}
}

int main(int argc, char *argv[])
{
  if (argc < 5) {
    std::cerr << "Please provive Matrices input sizes (4 args)" << std::endl;
    exit(1);
  }
  const auto row_1 = std::stoi(argv[1]);
  const auto col_1 = std::stoi(argv[2]);
  const auto row_2 = std::stoi(argv[3]);
  const auto col_2 = std::stoi(argv[4]);
  
  if (col_1 != row_2) {
    std::cerr << "Invalid dimensions for matrix multiplication" << std::endl;
  }
  
  std::vector<float> a(row_1 * col_1);
  init(a, 1.0);
  std::vector<float> b(row_2 * col_2);
  init(b, 2.0);  
  std::vector<float> c(row_1 * col_2);
  init(c, -1.0);
  
  wrapper::print_cuda_properties();
  wrapper::matMulV1(a, b, c, row_1, col_1, col_2);
  print(a);
  print(b);
  print(c);
  return 0;
}

