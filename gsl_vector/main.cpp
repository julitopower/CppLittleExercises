#include <iostream>

#include <gsl/gsl_blas.h>
#include <gsl/gsl_vector.h>

std::ostream& operator<<(std::ostream& os, gsl_vector* v) {
  for(auto i = 0U ; i < v->size ; ++i) {
    os << gsl_vector_get(v, i) << " ";
  }
  os << std::endl;
  return os;
}

int main(int argc, char** argv)
{
  std::cout << "GSL vector test" << std::endl;

  if (argc != 2) {
    std::cerr << "please provide a size" << std::endl;
  }

  const std::size_t size = std::atoi(argv[1]);
  
  // Let's create a vector of a particular size
  auto v1 = gsl_vector_alloc(size);
  auto v2 = gsl_vector_alloc(size);

  // Make one vector of zeros and one of ones
  gsl_vector_set_zero(v1);
  gsl_vector_set_all(v2, 1.0d);
  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;  

  std::cout << "v1 = v1 + v2" << std::endl;
  gsl_vector_add(v1, v2);

  std::cout << "v1: " << v1 << std::endl;
  std::cout << "v2 :" << v2 << std::endl;    

  // Perform dot product using gsl_blas
  double dot;
  gsl_blas_ddot(v1, v2, &dot);
  std::cout << "v1 dot v2:" << dot << std::endl;  
  
  gsl_vector_free(v1);
  gsl_vector_free(v2);  
  return 0;
}
