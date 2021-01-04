#pragma once

#include <vector>
#include <memory>

class Observer;

class Observable {
private:
  using ObserverPtr = std::shared_ptr<Observer>;
  std::vector<ObserverPtr> observers;

public:
  void addObserver(ObserverPtr);
  Observable();
  void fire();
  ~Observable();
};
