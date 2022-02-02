// 22/02/02 = Wed
// 18/02/07 = Wed

// Exercise 6.36: Write the declaration for a function that returns a reference
// to an array of ten strings, without using either a trailing return, decltype,
// or a type alias.

#include <string>

std::string (&foo(std::string (&a)[10]))[10] { return a; }

#include <iostream>
#include <type_traits>

void test() {
  std::string a[10];
  // warning: comparison between two arrays is deprecated; to compare array
  // addresses, use unary '+' to decay operands to pointers
  // [-Wdeprecated-array-compare]
  std::cout << (+a == foo(a)) << std::endl; // 1
  // C++17
  std::cout << std::is_same_v<
                   decltype(a),
                   std::remove_reference_t<decltype(foo(a))>> << std::endl; // 1
}

int main() {
  test();
  return 0;
}
