#include <iostream>
#include <vector>

#include "matrix2d.hpp"

int main(int argc, char** argv) {
  constexpr std::size_t size = 1 << 24;
  constexpr std::size_t cols = 2000;
  constexpr std::size_t rows = size / cols;
  
  std::vector<float> data (size, 1.0f);
  // The matrix doesn't own the data 
  matrix::Matrix2d<float> matrix{data.data(), rows, cols};

  const auto& matrix_end = matrix.end();
  std::size_t idx = 1;
  for (auto it = matrix.begin() ; it != matrix_end ; ++it) {
    const auto& vector_end = it.get().end();
    for (auto itv = it.get().begin() ; itv != vector_end ; ++itv) {
      *itv += 3.2f / idx;
    }
  }

  std::cout << matrix << std::endl;
  
  return 0;
}
