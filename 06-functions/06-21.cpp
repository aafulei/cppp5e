// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.21: Write a function that takes an int and a pointer to an int and
// returns the larger of the int value or the value to which the pointer points.
// What type should you use for the pointer?

// Answer: Should use const int * for the pointer.

#include <iostream>

int larger_of(int a, const int *const p) { return a >= *p ? a : *p; }

void test() {
  int a = 3, b = 4;
  std::cout << "larger of " << a << " and " << b << " is " << larger_of(a, &b)
            << std::endl;
  std::cout << "larger of " << b << " and " << a << " is " << larger_of(b, &a)
            << std::endl;
}

int main() {
  test();
  return 0;
}
