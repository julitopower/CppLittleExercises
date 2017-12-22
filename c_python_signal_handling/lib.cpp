#include <signal.h>
#include <iostream>

extern "C" void register_signal_handlers() {
  std::set_terminate([]() {
      auto ex = std::current_exception();
      if (ex != nullptr) {
	try {
	  if (ex) {
	    std::rethrow_exception(ex);
	  }
	} catch(const std::exception& e) {
	  std::cout << "Caught exception \"" << e.what() << "\"\n";
	  abort();
	}
      }
    });
}

extern "C" void generate_terminate() {
  auto x = new int[(1 << 31)];
  delete[] x;
}
