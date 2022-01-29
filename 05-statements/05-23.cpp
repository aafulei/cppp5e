// 22/01/29 = Sat
// 21/12/25 = Sat
// 18/02/05 = Mon

// Exercise 5.23: Write a program that reads two integers from the standard
// input and prints the result of dividing the first number by the second.

#include <iostream>

int main() {
  int a, b;
  if (std::cin >> a >> b) {
    std::cout << a / b << std::endl;
  }
  return 0;
}
