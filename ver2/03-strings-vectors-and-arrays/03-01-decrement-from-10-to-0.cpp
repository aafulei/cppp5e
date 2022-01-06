// 21/12/22 = Wed
// 18/01/26 = Fri

// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Exercise 1.10: In addition to the ++ operator that adds 1 to its operand,
// there is a decrement operator (--) that subtracts 1. Use the decrement
// operator to write a while that prints the numbers from ten down to zero.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-decrement-from-10-to-0.cpp && \
./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-decrement-from-10-to-0.cpp && a

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

using std::cout;
using std::endl;

int main() {
  int n = 10;
  while (n >= 0) {
    cout << n << endl;
    --n;
  }
  return 0;
}
