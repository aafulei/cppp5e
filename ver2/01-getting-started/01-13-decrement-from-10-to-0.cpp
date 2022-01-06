// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.13: Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

// Exercise 1.10: In addition to the ++ operator that adds 1 to its operand,
// there is a decrement operator (--) that subtracts 1. Use the decrement
// operator to write a while that prints the numbers from ten down to zero.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-13-decrement-from-10-to-0.cpp && \
./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-13-decrement-from-10-to-0.cpp && a

=== Output ===
10
9
8
7
6
5
4
3
2
1
0
*/

// Modified from 01-10-decrement-from-10-to-0.cpp

#include <iostream>

int main() {
  for (int n = 10; n >= 0; --n) {
    std::cout << n << std::endl;
  }
  return 0;
}
