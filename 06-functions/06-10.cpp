// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.10: Using pointers, write a function to swap the values of two
// ints. Test the function by calling it and printing the swapped values.

#include <iostream>

void swap(int *p, int *q) {
  int t = *p;
  *p = *q;
  *q = t;
}

void test() {
  int a = 3, b = 4;
  std::cout << a << " " << b << std::endl;
  swap(&a, &b);
  std::cout << a << " " << b << std::endl;
}

int main() {
  test();
  return 0;
}
