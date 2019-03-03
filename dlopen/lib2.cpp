#include "lib2.hpp"
#include "lib1.hpp"

extern "C" int fn2() {
  return fn1() * 2;
}

