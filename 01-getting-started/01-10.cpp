// 21/12/18 = Sat
// 18/01/26 = Fri

// Exercise 1.10: In addition to the ++ operator that adds 1 to its operand,
// there is a decrement operator (--) that subtracts 1. Use the decrement
// operator to write a while that prints the numbers from ten down to zero.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-10-decrement-from-10-to-0.cpp && \
./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-10-decrement-from-10-to-0.cpp && a

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

#include <iostream>

int main() {
  int n = 10;
  while (n >= 0) {
    std::cout << n << std::endl;
    --n;
  }
  return 0;
}
