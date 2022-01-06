// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.13: Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

// Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to
// 100.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-13-sum-from-50-to-100.cpp && \
./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-13-sum-from-50-to-100.cpp && a

=== Output ===
3825
*/

// Modified from 01-09-sum-from-50-to-100.cpp

#include <iostream>

int main() {
  int sum = 0;
  for (int val = 50; val <= 100; ++val) {
    sum += val;
  }
  std::cout << sum << std::endl;
  return 0;
}
