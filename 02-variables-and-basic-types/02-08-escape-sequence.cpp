// 21/12/20 = Mon
// 18/01/30 = Tue

// Exercise 2.8: Using escape sequences, write a program to print 2M followed by
// a newline. Modify the program to print 2, then a tab, then an M, followed by
// a newline.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-08-escape-sequence.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-08-escape-sequence.cpp && a

=== Output ===
2M
2       M
*/

#include <iostream>

int main() {
  std::cout << "\062\115\n";
  std::cout << "\062\t\115\n";
  return 0;
}
