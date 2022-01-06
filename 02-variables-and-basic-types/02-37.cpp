// 21/12/21 = Tue

// Exercise 2.36: Assignment is an example of an expression that yields a
// reference type. The type is a reference to the type of the left-hand operand.
// That is, if i is an int, then the type of the expression i = x is int&. Using
// that knowledge, determine the type and value of each variable in this code:

// int a = 3, b = 4;
// decltype(a) c = a;
// decltype(a = b) d = a;

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-37-decltype.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-37-decltype.cpp && a

=== Compiler Warning ===
warning: expression with side effects has no effect in an unevaluated context

=== Output ===
a = 3
b = 4
c = 3
d = 3
*/

// Answer:
//
// | Variable | Type    | Finishing Value |
// | -------- | ------- | --------------- |
// | a        | int     | 3               |
// | b        | int     | 4               |
// | c        | int     | 3               |
// | d        | int &   | 3               |

#include <iostream>

int main() {
  int a = 3, b = 4;
  decltype(a) c = a;
  decltype(a = b) d = a;
  std::cout << "a = " << a << std::endl; // a = 3
  std::cout << "b = " << b << std::endl; // b = 4
  std::cout << "c = " << c << std::endl; // c = 3
  std::cout << "d = " << d << std::endl; // d = 3
  return 0;
}
