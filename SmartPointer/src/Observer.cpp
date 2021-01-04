#include <iostream>
#include <memory>

#include "Event.hpp"
#include "Observer.hpp"

void Observer::notify(const Event &event) {
  std::cout << "Event notified to me " << this << ": " << event << std::endl;
}

Observer::~Observer() {
  std::cout << "Calling my destructor " << this << std::endl;
}

Observer::ObserverPtr Observer::newPtr() {
  return std::make_shared<Observer>();
}
