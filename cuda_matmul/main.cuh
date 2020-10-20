#pragma once

#include <vector>

namespace wrapper {

static const size_t TILE_WIDTH = 2;
static const size_t TILE_HEIGHT = 2;

void matMulV1(const std::vector<float>& a,
              const std::vector<float>& b,
              std::vector<float>& c,              
              int i,
              int j,
              int k);

void matMulV2(const std::vector<float>& a,
              const std::vector<float>& b,
              std::vector<float>& c,              
              int i,
              int j,
              int k);


void print_cuda_properties();
}
