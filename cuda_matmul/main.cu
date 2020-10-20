#include <cstdio>

#include <cuda_runtime.h>

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

namespace {

__global__
void matmulV1(const float* a, const float* b, float* c, int i, int j, int k) {
  // Figure out the output element I am writing to
  int col = blockIdx.x * blockDim.x + threadIdx.x;
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  if (row > i || col > k) {
    return;
  }

  float dotp = 0.0;
  for (auto idx = 0U ; idx < j ; ++idx) {
    dotp += (a[row * j + idx] * b[col + idx * j]);
  }

  c[row * k + col] = dotp;
  
}

template <typename T>
void kernelRunner(const std::vector<float>& a,
              const std::vector<float>& b,
              std::vector<float>& c,              
              int i,
              int j,
            int k,
            T fn) {
  const auto a_n = a.size() * sizeof(float);
  const auto b_n = b.size() * sizeof(float);
  const auto c_n = c.size() * sizeof(float);
  float* d_a;
  float* d_b;
  float* d_c;
  gpuCheck(cudaMalloc(&d_a, a_n));
  gpuCheck(cudaMalloc(&d_b, b_n));
  gpuCheck(cudaMalloc(&d_c, c_n));

  gpuCheck(cudaMemcpy(d_a, a.data(), a_n, cudaMemcpyHostToDevice));
  gpuCheck(cudaMemcpy(d_b, b.data(), b_n, cudaMemcpyHostToDevice));
  gpuCheck(cudaMemcpy(d_c, c.data(), c_n, cudaMemcpyHostToDevice));  

  dim3 dimGrid(ceil(i/4.0), ceil(k/4.0), 1);
  dim3 dimBlock(4, 4, 1);

  printf("Grid %d, %d, %d\n", dimGrid.x, dimGrid.y, dimGrid.z);
  
  fn<<<dimGrid, dimBlock>>>(d_a, d_b, d_c, i, j, k);
  cudaDeviceSynchronize();

  gpuCheck(cudaMemcpy(c.data(), d_c, c_n, cudaMemcpyDeviceToHost));
  gpuCheck(cudaFree(d_a));
  gpuCheck(cudaFree(d_b));
  gpuCheck(cudaFree(d_c));  
}

} // unnamed namespace

namespace wrapper {

void matMulV1(const std::vector<float>& a,
              const std::vector<float>& b,
              std::vector<float>& c,              
              int i,
              int j,
              int k) {
  kernelRunner(a, b, c, i, j, k, ::matmulV1);
}

// TODO: hook it up with the kernel that uses shared memory
void matMulV2(const std::vector<float>& a,
              const std::vector<float>& b,
              std::vector<float>& c,              
              int i,
              int j,
              int k) {
  kernelRunner(a, b, c, i, j, k, ::matmulV1);
}

void print_cuda_properties() {
  cudaDeviceProp props;
  cudaGetDeviceProperties(&props, 0);
  fprintf(stdout, "Warp size: %d\n", props.warpSize);
  fprintf(stdout, "Max grid size: %d, %d, %d\n", props.maxGridSize[0], props.maxGridSize[1], props.maxGridSize[2]);  
}
}
