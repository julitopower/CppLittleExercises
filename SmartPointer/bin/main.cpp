#include <iostream>
#include <string>
#include <memory>

#include "Observable.hpp"
#include "Observer.hpp"

int main() {
  Observer::ObserverPtr obs1 = Observer::newPtr();
  Observer::ObserverPtr obs2 = Observer::newPtr();
  Observable generator;
  generator.addObserver(obs1);
  generator.addObserver(obs2);
  generator.fire();
}
