// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.16: Write your own version of a program that prints the sum of a
// set of integers read from cin.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-16-sum-numbers-in-range.cpp && \
./a.out <../data/several-numbers.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-16-sum-numbers-in-range.cpp && ^
a <..\data\several-numbers.txt

=== Input ===
(several-numbers.txt)
12 34 56 78

=== Output ===
(several-numbers.txt)
Enter several numbers:
Sum is: 180
*/

#include <iostream>

int main() {
  std::cout << "Enter several numbers:" << std::endl;
  int sum = 0, value = 0;
  while (std::cin >> value) {
    sum += value;
  }
  std::cout << "Sum is: " << sum << std::endl;
  return 0;
}
