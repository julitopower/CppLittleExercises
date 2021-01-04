#include <iostream>
#include <memory>

#include "Event.hpp"
#include "Observable.hpp"
#include "Observer.hpp"

void Observable::addObserver(Observable::ObserverPtr observer) {
  observers.push_back(observer);
}

Observable::Observable() : observers() {}

Observable::~Observable() {
  std::cout << "Calling my Observable destructor " << this << std::endl;
}

void Observable::fire() {
  for (auto &observer : observers) {
    Event event(1, "Message");
    observer->notify(event);
  }
}
