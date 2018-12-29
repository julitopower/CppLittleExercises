#ifndef TEMPLATE_DEF_H
#define TEMPLATE_DEF_H

#include "template.hpp"

template <typename T>
T Julio<T>::data() {
  return data_;
}

template <typename T>
Julio<T>::Julio(T value) : data_{value} {}

#endif /* TEMPLATE_DEF_H */
