// 21/12/22 = Wed
// 18/01/26 = Fri

// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Exercise 1.11: Write a program that prompts the user for two integers. Print
// each number in the range specified by those two integers.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-print-numbers-in-range.cpp && \
./a.out <../data/two-numbers.txt && ./a.out <../data/two-numbers-reversed.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-print-numbers-in-range.cpp && ^
a <..\data\two-numbers.txt && a <..\data\two-numbers-reversed.txt

=== Input ===
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

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout << "Enter two numbers:" << endl;
  int v1 = 0, v2 = 0;
  cin >> v1 >> v2;
  while (v1 <= v2) {
    cout << v1 << endl;
    ++v1;
  }
  return 0;
}
