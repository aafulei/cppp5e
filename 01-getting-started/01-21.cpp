// 21/12/19 = Sun
// 18/01/15 = Mon

// Exercise 1.21: Write a program that reads two Sales_item objects that have
// the same ISBN and produces their sum.

// Note: This program assumes valid input: two books with the same ISBN.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-21-sum-two-books.cpp && \
./a.out <../data/two-books.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-21-sum-two-books.cpp && ^
a <..\data\two-books.txt

=== Input ===
(two-books.txt)
0-201-88954-4 2 15.00
0-201-88954-4 5 12.00

=== Output ===
(two-books.txt)
0-201-88954-4 7 90 12.8571
*/

#include "Sales_item.h"
#include <iostream>

int main() {
  Sales_item item1, item2;
  std::cin >> item1 >> item2;
  std::cout << item1 + item2 << std::endl;
  return 0;
}
