// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.16: Write your own version of a program that prints the sum of a
// set of integers read from cin.

#include <iostream>

int main() {
  std::cout << "Enter several numbers:" << std::endl;
  int sum = 0, value = 0;
  while (std::cin >> value) {
    sum += value;
  }
  std::cout << "Sum is: " << sum << std::endl;
  return 0;
}
