// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.12: Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to
// use references instead of pointers to swap the value of two ints. Which
// version do you think would be easier to use and why?

// Exercise 6.10: Using pointers, write a function to swap the values of two
// ints. Test the function by calling it and printing the swapped values.

// Answer: Using a reference is easier, becasue
// 1.	it is less error-prone;
// 2.	it avoids copying, which, in some cases, might be expensive or impossible.

// Modified from 06-10.cpp

#include <iostream>

void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

void test() {
  int a = 3, b = 4;
  std::cout << a << " " << b << std::endl;
  swap(a, b);
  std::cout << a << " " << b << std::endl;
}

int main() {
  test();
  return 0;
}
