#include <iostream>
#include <vector>

#include "matrix2d.hpp"

int main(int argc, char** argv) {
  constexpr std::size_t size = 1 << 8;
  constexpr std::size_t cols = 4;
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

  // Test random matrix generation routine
  auto random_matrix = matrix::Matrix2d<double>::random(rows, cols);
  std::cout << random_matrix << std::endl;

  // Test ones
  auto ones_matrix = matrix::Matrix2d<double>::ones(rows, cols);
  std::cout << ones_matrix << std::endl;

  // Test zeros
  auto zeros_matrix = matrix::Matrix2d<double>::zeros(rows, cols);
  std::cout << zeros_matrix << std::endl;

  // Test Matrix multiplication
  using T = double;
  auto ones_1 = matrix::Matrix2d<T>::ones(2000, 300);
  auto ones_2 = matrix::Matrix2d<T>::ones(300, 1000);
  std::cout << ones_2.shape()[1] << std::endl;
  auto tmp = ones_1 * ones_2;

  for (auto i = 0 ; i < 20 ; ++i) {
      auto tmp2 = ones_1 * ones_2;      
  }
  return 0;
}
