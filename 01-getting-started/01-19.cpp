// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.19: Revise the program you wrote for the exercises in § 1.4.1 (p.
// 13) that printed a range of numbers so that it handles input in which the
// first number is smaller than the second.

// Exercise 1.11: Write a program that prompts the user for two integers. Print
// each number in the range specified by those two integers.

// Note: The case where the first number is smaller than the second has already
// been dealt with in Exercise 1.11. Here we deal with the other way around as
// well.

// Modified from 01-11.cpp

#include <iostream>

int main() {
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  // Add to 01-11-print-numbers-in-range.cpp
  if (v1 > v2) {
    int t = v1;
    v1 = v2;
    v2 = t;
  }
  while (v1 <= v2) {
    std::cout << v1 << std::endl;
    ++v1;
  }
  return 0;
}
