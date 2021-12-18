// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.4: Our program used the addition operator, +, to add two numbers.
// Write a program that uses the multiplication operator, *, to print the
// product instead.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra \
01-04-multiplication-operator.cpp && ./a.out <../data/two-numbers.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra ^
01-04-multiplication-operator.cpp && a <..\data\two-numbers.txt

=== Input ====
(two-numbers.txt)
3 5

=== Output ===
(two-numbers.txt)
Enter two numbers:
The product of 3 and 5 is 15
*/

#include <iostream>

int main() {
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2
            << std::endl;
  return 0;
}
