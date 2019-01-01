#ifndef OBSERVER_HPP_INCLUDED
#define OBSERVER_HPP_INCLUDED

#include <list>
#include "Event.hpp"
#include "Observable.hpp"
#include "Observer.hpp"
#include <memory>

class Observable;

class Observer {
    public:
        void notify(Event & event);
        Observer();
        ~Observer();
    private:
        std::unique_ptr<Observable *> observable;  
};


#endif // OBSERVER_HPP_INCLUDED
