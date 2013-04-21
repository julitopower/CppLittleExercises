#include "Observer.hpp"
#include <iostream>

Observer::Observer():observable(){}

void Observer::notify(Event & event) {
    std::cout << "Event notified to me " << this << std::endl;
}

Observer::~Observer() {
    std::cout << "Calling my destructor " << this << std::endl;
}
