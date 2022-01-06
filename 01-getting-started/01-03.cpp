// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.3: Write a program to print Hello, World on the standard output.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-03-hello-world.cpp && ./a.out

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-03-hello-world.cpp && a

=== Output ===
Hello, World
*/

#include <iostream>

int main() {
  std::cout << "Hello, World" << std::endl;
  return 0;
}
