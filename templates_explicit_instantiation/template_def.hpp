#ifndef TEMPLATE_DEF_H
#define TEMPLATE_DEF_H

#include "template.hpp"

template <typename T>
T Julio<T>::data() {
  return _data;
}

template <typename T>
Julio<T>::Julio(T value) : _data{value} {}

#endif /* TEMPLATE_DEF_H */
