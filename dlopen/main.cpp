#include <dlfcn.h>
#include <iostream>

using Fn = int (*)();

namespace {
[[noreturn]] void error()  {
  std::cout << dlerror() << std::endl;
  exit(1);
}
}

int main(int argc, char** argv) {
  void* lib_handler = dlopen("./libl2.so", RTLD_NOW | RTLD_GLOBAL);
  if (lib_handler == nullptr) {
    error();
  }
  void* fn_handler = dlsym(lib_handler, "fn2");
  if (fn_handler == nullptr){
    error();
  }
  std::cout << ((Fn)fn_handler)() << std::endl;
  exit(0);
}
