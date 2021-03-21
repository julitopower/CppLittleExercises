#include <chrono>
#include <iostream>
#include <thread>

#include "command.hpp"

int main(int argc, char *argv[]) {
  std::cout << "starting command demo application" << std::endl;

  Command cmd1([]() {
    for (int i = 0; i < 10; ++i) {
      std::cout << i << " ";
    }
  });

  Command cmd2([]() { std::cout << "Another command" << std::endl; });

  CommandQueue cq;

  std::thread producer1{[&cq]() {
    std::this_thread::sleep_for(std::chrono::milliseconds{1000});
    for (auto i = 0; i < 100; ++i) {
      cq.add(Command{[i]() { std::cout << "Item" << i << std::endl; }});
      std::this_thread::sleep_for(std::chrono::milliseconds{100});
    }
  }};

  std::thread producer2{[&cq]() {
    std::this_thread::sleep_for(std::chrono::milliseconds{2000});
    for (auto i = 0; i < 100; ++i) {
      cq.add(Command{[i]() { std::cout << "Item" << i << std::endl; }});
      std::this_thread::sleep_for(std::chrono::milliseconds{100});
    }
  }};

  auto t1 = std::chrono::high_resolution_clock::now();
  while (true) {
    cq.get().exec();
    const auto t2 = std::chrono::high_resolution_clock::now();
    const auto diff = t2 - t1;
    if (std::chrono::duration_cast<std::chrono::seconds>(diff).count() > 5) {
      break;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds{100});
  }

  producer1.join();
  producer2.join();
  return 0;
}
