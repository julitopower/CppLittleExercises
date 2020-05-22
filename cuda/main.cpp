#include <iostream>
#include <vector>

#include "main.cuh"

int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cerr << "Please provive input vector size" << std::endl;
    exit(1);
  }
  const auto N = std::stoi(argv[1]);
  std::cout << "Hi there" << std::endl;
  std::vector<float> v1 {};
  std::vector<float> v2 {};
  for (auto i = 0U ; i <= N ; ++i) {
    v1.push_back(i);
    v2.push_back(i);
  }
  std::vector<float> out(v1.size());
  wrapper::wrapper(v1, v2, out);

  std::cout << out[N] << std::endl;
  return 0;
}

