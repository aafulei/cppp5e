// 21/12/21 = Tue
// 18/01/31 = Wed

// Exercise 2.18: Write code to change the value of a pointer. Write code to
// change the value to which the pointer points.

// i = 3, p = 0
// i = 3, p = 0xc13ddffd18, *p = 3
// i = 4, p = 0xc13ddffd18, *p = 4

#include <iostream>

int main() {
  int i = 3, *p = nullptr;
  std::cout << "i = " << i << ", p = " << p << std::endl;
  p = &i; // change value of a pointer
  std::cout << "i = " << i << ", p = " << p << ", *p = " << *p << std::endl;
  *p = 4; // change value to which the pointer points
  std::cout << "i = " << i << ", p = " << p << ", *p = " << *p << std::endl;
  return 0;
}
