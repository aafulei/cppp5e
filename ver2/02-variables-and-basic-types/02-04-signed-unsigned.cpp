// 21/12/20 = Mon
// 18/01/30 = Tue

// Exercise 2.4: Write a program to check whether your predictions were correct.
// If not, study this section until you understand what the problem is.

// Exercise 2.3: What output will the following code produce?

// unsigned u = 10, u2 = 42;
// std::cout << u2 - u << std::endl;
// std::cout << u - u2 << std::endl;
// int i = 10, i2 = 42;
// std::cout << i2 - i << std::endl;
// std::cout << i - i2 << std::endl;
// std::cout << i - u << std::endl;
// std::cout << u - i << std::endl;

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-04-signed-unsigned.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-04-signed-unsigned.cpp && a

=== Output ===
32
4294967264
32
-32
0
0
*/

#include <iostream>

int main() {
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl; // 32
  std::cout << u - u2 << std::endl; // 4294967264
  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl; // 32
  std::cout << i - i2 << std::endl; // -32
  std::cout << i - u << std::endl;  // 0
  std::cout << u - i << std::endl;  // 0
  return 0;
}
