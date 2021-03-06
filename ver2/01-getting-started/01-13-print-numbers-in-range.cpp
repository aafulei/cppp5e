// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.13: Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

// Exercise 1.11: Write a program that prompts the user for two integers. Print
// each number in the range specified by those two integers.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-13-print-numbers-in-range.cpp && \
./a.out <../data/two-numbers.txt && ./a.out <../data/two-numbers-reversed.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-13-print-numbers-in-range.cpp && ^
a <..\data\two-numbers.txt && a <..\data\two-numbers-reversed.txt

=== Input ====
(two-numbers.txt)
3 5

(two-numbers-reversed.txt)
5 3

=== Output ===
(two-numbers.txt)
Enter two numbers:
3
4
5

(two-numbers-reversed.txt)
Enter two numbers:
*/

// Modified from 01-11-print-numbers-in-range.cpp

#include <iostream>

int main() {
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  for (; v1 <= v2; ++v1) {
    std::cout << v1 << std::endl;
  }
  return 0;
}
