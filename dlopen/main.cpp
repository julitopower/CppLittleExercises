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
  // Load the library
  void* lib_handler = dlopen("./libl2.so", RTLD_NOW | RTLD_GLOBAL);

  // Check that things worked, otherwise exit after
  // printing the error message frm dlopen
  if (lib_handler == nullptr) {
    error();
  }

  // Get a handler to a method by name. Notice that
  // for this to work the names must be "extern C"
  void* fn_handler = dlsym(lib_handler, "fn2");
  if (fn_handler == nullptr){
    error();
  }

  // Call the method. For this to work, we need
  // to know beforehand the signature of the method
  // Python ctypes basically does all this
  std::cout << ((Fn)fn_handler)() << std::endl;
  exit(0);
}
