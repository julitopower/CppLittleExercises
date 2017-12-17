#include <iostream>
#include <mxnet/base.h>
#include <mxnet/storage.h>
#include <mxnet/ndarray.h>
#include <mxnet/engine.h>
#include <csignal>
#include <vector>

#define AT(nd, row, col, val)			\
  {						\
    auto blob = nd.At(row).At(col).data();	\
    val = static_cast<float*>(blob.dptr_);	\
  }

void init_ndarray(mxnet::NDArray& nd, float value) {
  auto data = nd.data();
  auto data_ptr = data.dptr<float>();
  
  for (auto i = 0U ; i < data.Size() ; ++i) {
    *data_ptr = value;
    ++data_ptr;
  }
}

void print_ndarray(mxnet::NDArray& nd) {
  auto shape = static_cast<nnvm::TShape>(nd.shape());

  unsigned int count = 0;
  for (auto it = shape.begin() ; it != shape.end() ; ++it) {
    ++count;
  }

  if (count != 2) {
    return;
  }
  
  float* val;
  for (auto i = 0U ; i < shape[0] ; ++i) {
    for (auto j = 0U ; j < shape[1] ; ++j) {
      AT(nd, i, j, val);
      std::cout << *val << ", ";
    }
    std::cout << std::endl;
  }
}
  
int main(int argc, char **argv)
{
  // Generate matrix on the cpu memory. All this code only works on CPU
  mxnet::NDArray nd{mxnet::TShape{5, 10}, mxnet::Context::CPU()};

  // Initialize with a particular value, and set the vale of (0,0)
  // element. This is to show how to read/write inidividual values.
  init_ndarray(nd, 3.0f);
  float* val;
  AT(nd, 0, 3, val);
  *val = 34;

  AT(nd, 0, 0, val)
  std::cout << *val << std::endl;

  print_ndarray(nd);
  return 0;
}
