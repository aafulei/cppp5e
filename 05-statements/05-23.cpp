// 21/12/25 = Sat
// 18/02/05 = Mon

// Exercise 5.23: Write a program that reads two integers from the standard
// input and prints the result of dividing the first number by the second.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-23-divide.cpp && \
./a.out <../data/two-numbers.txt && \
./a.out <../data/two-numbers-2.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 05-23-divide.cpp && ^
a <..\data\two-numbers.txt && ^
a <..\data\two-numbers-2.txt

=== Input ===
(two-numbers.txt)
3 5

(two-numbers-2.txt)
72 8

=== Output ===
(two-numbers.txt)
0

(two-numbers-2.txt)
9
*/

#include <iostream>

int main() {
  int a = 0, b = 0;
  if (std::cin >> a >> b) {
    std::cout << a / b << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
  }
  return 0;
}
