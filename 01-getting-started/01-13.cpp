// 22/02/05 = Sat
// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.13: Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

// Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to
// 100.

// Exercise 1.10: In addition to the ++ operator that adds 1 to its operand,
// there is a decrement operator (--) that subtracts 1. Use the decrement
// operator to write a while that prints the numbers from ten down to zero.

// Exercise 1.11: Write a program that prompts the user for two integers. Print
// each number in the range specified by those two integers.

// Modified from 01-09.cpp, 01-10.cpp, 01-11.cpp

#include <iostream>

void forLoopEx01_09() {
  int sum = 0;
  for (int val = 50; val <= 100; ++val) {
    sum += val;
  }
  std::cout << sum << std::endl;
}

void forLoopEx01_10() {
  for (int n = 10; n >= 0; --n) {
    std::cout << n << std::endl;
  }
}

void forLoopEx01_11() {
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  for (; v1 <= v2; ++v1) {
    std::cout << v1 << std::endl;
  }
}

int main() {
  std::cout << "=== Exercise 1.9 ===" << std::endl;
  forLoopEx01_09();
  std::cout << "=== Exercise 1.10 ===" << std::endl;
  forLoopEx01_10();
  std::cout << "=== Exercise 1.11 ===" << std::endl;
  forLoopEx01_11();
  return 0;
}
