#include "Observable.hpp"
#include "Observer.hpp"
#include <memory>
#include "Event.hpp"
#include <iostream>

void Observable::addObserver(Observer * observer) {
    observers.push_back(std::shared_ptr<Observer>(observer));
}

Observable::Observable():observers(){

}

Observable::~Observable() {
    std::cout << "Calling my Observable destructor " << this << std::endl;
}

void Observable::fire() {
    for(auto it = observers.begin(), et = observers.end() ; it != et ; it++) {
        Event event(1, "Message");
        (*it)->notify(event);
    }
}
