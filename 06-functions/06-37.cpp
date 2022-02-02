// 22/02/02 = Wed
// 18/02/07 = Wed

// Exercise 6.37: Write three additional declarations for the function in the
// previous exercise. One should use a type alias, one should use a trailing
// return, and the third should use decltype. Which form do you prefer and why?

// Exercise 6.36: Write the declaration for a function that returns a reference
// to an array of ten strings, without using either a trailing return, decltype,
// or a type alias.

// Answer: I prefer the using type declaration introduced in C++11. Modern and
// readable.

#include <iostream>
#include <string>

using T = std::string (&)[10];
std::string _[10];

// A function can be declared many times, so long as the declarations are
// consistent themselves. In what follows, we declare foo() several times using
// different forms, and rely on the compiler to check their consistency.
std::string (&foo(std::string (&)[10]))[10];          // 0. original
T foo(T);                                             // 1. type alias
auto foo(std::string (&)[10]) -> std::string (&)[10]; // 2. trailing return
decltype(_) &foo(decltype(_) &a);                     // 3. decltype

T foo(T a) { return a; }

// X
// XX
// XXX
// XXXX
// XXXXX
// XXXXXX
// XXXXXXX
// XXXXXXXX
// XXXXXXXXX
// XXXXXXXXXX
int main() {
  std::string a[10];
  // C++20
  for (int i = 0; auto &s : foo(a)) {
    s = std::string(++i, 'X');
  }
  for (auto s : a) {
    std::cout << s << std::endl;
  }
  return 0;
}
