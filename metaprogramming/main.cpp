#include <iostream>
#include <utility>
#include <string>

// The generic template
template<class T, class U>
struct is_same : std::false_type {};

// The one that actually succeeds when both
// types are the same
template<class T>
struct is_same<T, T> : std::true_type {};

// This is the generic template. For enable_if to work
// we will only provide a partial instantiation for true;
template<bool B, class T = void>
struct enable_if {};

// This is the partial instantiation for true. For cases
// in which B is false, SFINAE will fail
template<class T>
struct enable_if<true, T> { typedef T type; };

// Let's implement function template  that doesn't support
// int32
template<typename T,
	 typename enable_if<!is_same<T, std::int32_t>::value, bool>::type = true>
void something(T val) {
  std::cout << val << std::endl;
}


// Template to detect that a type has a method len
template<typename T, typename L = decltype(std::declval<T>().len())>
struct has_len : std::true_type {};

// Let's implement a function that requires the argument to have
// a method len()
template<typename T,
	 typename enable_if<has_len<T>::value, bool>::type = true>
void fn(T& val) {
  std::cout << val.len() << std::endl;
}

class Julio {
public:
  std::size_t len() {
    return 23;
  }
};

class JulioStr {
public:
  std::string len() {
    return "JulioStr";
  }
};

int main(int argc, char** argv) {
  std::cout << "Starting application" << std::endl;
  std::int32_t i32 = 3;
  double i64 = 4.2;
  // something(i32); // This won't compile
  something(i64);
  something("what");
  //fn(23); // This won't compile
  Julio j{};
  fn(j);
  JulioStr jstr{};
  fn(jstr);
}
