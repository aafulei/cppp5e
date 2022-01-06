// 21/12/19 = Sun
// 18/01/15 = Mon

// Exercise 1.22: Write a program that reads several transactions for the same
// ISBN. Write the sum of all the transactions that were read.

// Note: This program assumes valid input: several books with the same ISBN.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-22-sum-several-books.cpp && \
./a.out <../data/several-books.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-22-sum-several-books.cpp && ^
a <..\data\several-books.txt

=== Input ====
(several-books.txt)
0-201-88954-4 2 15.00
0-201-88954-4 5 12.00
0-201-88954-4 7 12.00
0-201-88954-4 2 12.00

=== Output ===
(several-books.txt)
0-201-88954-4 16 198 12.375
*/

#include "Sales_item.h"
#include <iostream>

int main() {
  Sales_item item, sum;
  if (std::cin >> item) {
    sum = item;
    while (std::cin >> item) {
      sum += item;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
