// 21/12/18 = Sat
// 18/01/26 = Fri

// Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to
// 100.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-09-sum-from-50-to-100.cpp && \
./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-09-sum-from-50-to-100.cpp && a

=== Output ===
3825
*/

#include <iostream>

int main() {
  int sum = 0, val = 50;
  while (val <= 100) {
    sum += val;
    ++val;
  }
  std::cout << sum << std::endl;
  return 0;
}
