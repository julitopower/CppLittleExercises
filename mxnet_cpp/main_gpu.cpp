#include <vector>

#include <mxnet-cpp/MxNetCpp.h>

mxnet::cpp::NDArray init_array_gpu(const mxnet::cpp::Shape& s, const mx_float init_value) {
  auto cols = s[0];
  auto rows = s[1];

  std::vector<mx_float> v(cols * rows, init_value);
  mxnet::cpp::NDArray arr{v.data(), s, mxnet::cpp::Context::gpu()};
  arr.WaitAll();
  return arr;
}

void print_shape(const mxnet::cpp::NDArray& nd) {
  for (auto& v : nd.GetShape()) {
    std::cout << v << " --" << std::endl;
  }
}

int main(int argc, char** argv) {
  auto iters = (1 << 12);
  std::cout << "MxNet GPU test program" << std::endl;
  auto nd = init_array_gpu(mxnet::cpp::Shape{10000,20}, 3.1);
  for (auto i = 0U ; i < iters ; ++i) {
    nd *= nd;
    nd.WaitAll();
    nd /= nd;
    nd.WaitAll();    
  }
  
  auto nd2 = nd.Copy(mxnet::cpp::Context::gpu());
  for (auto i = 0U ; i < iters ; ++i) {
    nd2 *= 3.2f;
    nd2.WaitAll();      
  }

  return 0;
  auto op = mxnet::cpp::Operator("transpose");
  auto res = op.PushInput(nd2).Invoke();
  std::cout << res.size() << std::endl;
  res.at(0).WaitAll();
  print_shape(nd);
  print_shape(nd2);
  print_shape(res.at(0));

  auto op2 = mxnet::cpp::Operator("dot");
  auto aux1 = init_array_gpu(mxnet::cpp::Shape{1, 10}, 12.0f);
  auto aux2 = init_array_gpu(mxnet::cpp::Shape{1, 10}, 12.0f);
  auto aux3 = init_array_gpu(mxnet::cpp::Shape{1, 10}, 12.0f);  
  op2.PushInput(aux1).PushInput(aux2).Invoke(aux3);
  aux3.WaitAll();

  print_shape(aux1);
  print_shape(aux2);
  print_shape(aux3);

  auto bla = aux3.Copy(mxnet::cpp::Context::cpu());
  bla.WaitAll();
  std::cout << bla << std::endl;
}
