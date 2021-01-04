#pragma once

#include <list>
#include <memory>

class Event;

class Observer {
 public:
  using ObserverPtr = std::shared_ptr<Observer>;
  
public:
  Observer() = default;
  void notify(const Event &event);
  ~Observer();
  static ObserverPtr newPtr();
};
