#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>

class Runner {
public:
  void f() const {
    std::cout << "Runner::f() called" << std::endl;
  }
};

int main(int argc, char** argv)
{
  std::cout << "Starting funcional demo" << std::endl;
  Runner r{};
  // Using a lambda to wrap a member function
  std::function<void()> f{[r](){r.f();}};
  f();
  
  // We can wrap a member function, and later apply it
  // to arbitrary objects
  // This would allow us to call the same method on a
  // collection of Runners, for instance
  auto f_bad = std::mem_fn(&Runner::f);
  f_bad(r);

  // Transform is basically the map operation we typically
  // see in functional programming languages
  std::vector<int> v {1,2,3,4,5,6};
  std::vector<char> o;
  o.resize(v.size());

  // It maps the elements of v, which are int into chars, generating
  // a new vector. It can be applied to almost any container
  std::transform(v.begin(), v.end(), o.begin(), [](int x) {return 'a' + x;});

  return 0;
}
