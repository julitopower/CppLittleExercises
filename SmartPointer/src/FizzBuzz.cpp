#include <iostream>
#include <string>
#include "FizzBuzz.hpp"
#include "Observable.hpp"
#include "Observer.hpp"
using namespace std;

#ifndef TEST
int main()
{
    Observable generator;
    Observer * obs1 = new Observer();
    Observer * obs2 = new Observer();
    generator.addObserver(obs1);
    generator.addObserver(obs2);
    generator.fire();
}
#endif
