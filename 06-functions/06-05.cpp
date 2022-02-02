// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.5: Write a function to return the absolute value of its argument.

#include <iostream>

double abs(double x) { return x >= 0 ? x : -x; }

void test() {
  std::cout << "abs(3.14) = " << abs(3.14) << std::endl;
  std::cout << "abs(-3.14) = " << abs(-3.14) << std::endl;
  std::cout << "abs(0) = " << abs(0) << std::endl;
}

int main() {
  test();
  return 0;
}
