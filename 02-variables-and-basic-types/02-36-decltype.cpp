// 21/12/21 = Tue

// Exercise 2.36: In the following code, determine the type of each variable and
// the value each variable has when the code finishes:

// int a = 3, b = 4;
// decltype(a) c = a;
// decltype((b)) d = a;
// ++c;
// ++d;

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-36-decltype.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-36-decltype.cpp && a

=== Output ===
a = 4
b = 4
c = 4
d = 4
*/

// Answer:
//
// | Variable | Type  | Finishing Value |
// | -------- | ----- | --------------- |
// | a        | int   | 4               |
// | b        | int   | 4               |
// | c        | int   | 4               |
// | d        | int & | 4               |

#include <iostream>

int main() {
  int a = 3, b = 4;
  decltype(a) c = a;
  decltype((b)) d = a;
  ++c;
  ++d;
  std::cout << "a = " << a << std::endl; // a = 4
  std::cout << "b = " << b << std::endl; // b = 4
  std::cout << "c = " << c << std::endl; // c = 4
  std::cout << "d = " << d << std::endl; // d = 4
  return 0;
}
