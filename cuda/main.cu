#include <cstdio>

#include "cuda_runtime.h"


#include "main.cuh"

#define gpuCheck(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess) 
   {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}

__global__
void fn(int n, const float* v1, const float* v2, float* out) {
  // Each kernel call processes one element
  // idx = blockIdx.x * blockDim.x + threadIdx
  auto idx = blockIdx.x * blockDim.x + threadIdx.x;
  if (idx >= n) {
    return;
  }
  out[idx] = v1[idx] + v2[idx];
}

namespace wrapper {
void wrapper(const std::vector<float>& v1,
             const std::vector<float>& v2,
             std::vector<float>& out) {
  const auto n = v1.size();
  float *d_v1, *d_v2, *d_out;

  gpuCheck(cudaMalloc(&d_v1, sizeof(float) * n));
  gpuCheck(cudaMalloc(&d_v2, sizeof(float) * n));
  gpuCheck(cudaMalloc(&d_out, sizeof(float) * n));
  gpuCheck(cudaMemcpy(d_v1, v1.data(), sizeof(float) * n, cudaMemcpyHostToDevice));
  gpuCheck(cudaMemcpy(d_v2, v2.data(), sizeof(float) * n, cudaMemcpyHostToDevice));
  const auto threads = 32;
  const auto blocks = (n + threads - 1) / threads;
  fn<<<blocks,threads>>>(v1.size(), d_v1, d_v2, d_out);
  cudaDeviceSynchronize();
  
  gpuCheck(cudaMemcpy(out.data(), d_out, sizeof(float) * n, cudaMemcpyDeviceToHost));
  gpuCheck(cudaFree(d_v1));
  gpuCheck(cudaFree(d_v2));
  gpuCheck(cudaFree(d_out));
}
}