#ifndef OBSERVER_HPP_INCLUDED
#define OBSERVER_HPP_INCLUDED

#include <list>
#include "Event.hpp"
#include "Observable.hpp"
#include "Observer.hpp"
#include <memory>

class Observable;

class Observer {
    private:
        std::auto_ptr<Observable *> observable;
    public:
        void notify(Event & event);
        Observer();
        ~Observer();
};


#endif // OBSERVER_HPP_INCLUDED
