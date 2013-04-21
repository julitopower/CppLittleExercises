#include <iostream>

using namespace std;

int main()
{
    Observable generator();
    Observer obs1();
    Observer obs2();
    generator.addObserver(&obs1);
    generator.addObserver(&obs2);
    generator.fire();
}
