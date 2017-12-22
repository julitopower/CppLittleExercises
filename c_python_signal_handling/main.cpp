#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <signal.h>
#include <exception>

template<class T>
class Julio {
public:
  void print(const T& elem) const {
    std::cout << elem << std::endl;
  }
};

int main(int argc, char** argv) {
  // Let's set a signal handler
  signal(SIGABRT, [](int signal) {
      std::cout << "Something went terribly wrong" << std::endl;
    });

  std::set_terminate([]() {
      auto ex = std::current_exception();
      if (ex != nullptr) {
	try {
	  if (ex) {
	    std::rethrow_exception(ex);
	  }
	} catch(const std::exception& e) {
	  std::cout << "Caught exception \"" << e.what() << "\"\n";
	}
      }
      std::cout << "Terminage got called" << std::endl;
    });

  auto x = new int[(1 << 31)];
  delete[] x;
}

