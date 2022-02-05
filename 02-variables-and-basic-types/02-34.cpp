// 21/12/21 = Tue
// 18/02/01 = Thu

// Exercise 2.34 Write a program containing the variables and assignments from
// the previous exercise. Print the variables before and after the assignments
// to check whether your predictions in the previous exercise were correct. If
// not, study the examples until you can convince yourself you know what led you
// to the wrong conclusion.

// Exercise 2.33: Using the variable definitions from this section, determine
// what happens in each of these assignments:

// int i = 0, &r = i;
// auto a = r;
// const int ci = i, &cr = ci;
// auto b = ci;
// auto c = cr;
// auto d = &i;
// auto e = &ci;
// const auto f = ci;
// auto &g = ci;

// a = 42; b = 42; c = 42;
// d = 42; e = 42; g = 42;

#include <iostream>

int main() {
  int i = 0, &r = i;
  auto a = r;
  const int ci = i, &cr = ci;
  auto b = ci;
  auto c = cr;
  auto d = &i;
  auto e = &ci;
  const auto f = ci;
  auto &g = ci;
  std::cout << "a = " << a << std::endl; // a = 0
  a = 42;
  std::cout << "a = " << a << std::endl; // a = 42
  std::cout << "b = " << b << std::endl; // b = 0
  b = 42;
  std::cout << "b = " << b << std::endl; // b = 42
  std::cout << "c = " << c << std::endl; // c = 0
  c = 42;
  std::cout << "c = " << c << std::endl;                    // c = 42
  std::cout << "d = " << d << ", *d = " << *d << std::endl; // d = 0x..., *d = 0
  // d = 42;  // won't compile
  std::cout << "e = " << e << ", *e = " << *e << std::endl; // e = 0x..., *e = 0
  // e = 42;  // won't compile
  std::cout << "g = " << g << std::endl; // g = 0
  // g = 42;  // won't compile
  return 0;
}
