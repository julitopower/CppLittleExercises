#include <iostream>
#include <typeinfo>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "matrix2d.hpp"

namespace py = pybind11;

namespace {

  template<typename T>
  inline const matrix::Matrix2d<T> build_matrix(py::array& a) {
    return matrix::Matrix2d<T>{(T*)a.request().ptr,
	    static_cast<std::size_t>(a.shape(0)), static_cast<std::size_t>(a.shape(1))};
  }

  template<typename T>
  inline bool test(py::array& a) {
    return py::isinstance<py::array_t<T>>(a);
  }

  template<typename T>
  inline void process_request(py::array& a) {
    auto m = build_matrix<T>(a);
    std::cout << m << std::endl;
  }

  void f(py::array& a) {
    if (test<std::int32_t>(a)) {
      process_request<std::int32_t>(a);
    } else if (test<std::int64_t>(a)) {
      process_request<std::int64_t>(a);
    } else if (test<std::float_t>(a)) {
      process_request<std::float_t>(a);      
    } else if (test<std::double_t>(a)) {
      process_request<std::double_t>(a);            
    }
  }
}

PYBIND11_MODULE(cpp_matrix, m) {
  m.doc() = "Cpp matrix example module";
  m.def("info", []() { std::cout << "My module info" << std::endl; });
  m.def("array", &f);
}
