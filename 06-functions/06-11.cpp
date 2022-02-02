// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.11: Write and test your own version of reset that takes a
// reference.

#include <iostream>

void reset(int &i) { i = 0; }

void test() {
  int i = 42;
  std::cout << i << std::endl;
  reset(i);
  std::cout << i << std::endl;
}

int main() {
  test();
  return 0;
}
