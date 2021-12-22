// 21/12/22 = Wed
// 18/01/26 = Fri

// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to
// 100.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-sum-from-50-to-100.cpp && \
./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-sum-from-50-to-100.cpp && a

=== Output ===
3825
*/

// Modified from 01-09-sum-from-50-to-100.cpp

#include <iostream>

using std::cout;
using std::endl;

int main() {
  int sum = 0, val = 50;
  while (val <= 100) {
    sum += val;
    ++val;
  }
  cout << sum << endl;
  return 0;
}
