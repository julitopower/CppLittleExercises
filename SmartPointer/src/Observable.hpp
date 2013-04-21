#ifndef OBSERVABLE_HPP_INCLUDED
#define OBSERVABLE_HPP_INCLUDED
#include <list>
#include "Observer.hpp"
#include <memory>
class Observer;

class Observable {
    private:
        std::list<std::shared_ptr<Observer> > observers;
    public:
        void addObserver(Observer *);
        Observable();
        void fire();
        ~Observable();
};


#endif // OBSERVABLE_HPP_INCLUDED
