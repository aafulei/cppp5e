// 21/12/19 = Sun
// 18/01/15 = Mon

// Exercise 1.23: Write a program that reads several transactions and counts how
// many transactions occur for each ISBN.

// Note: This program assumes valid input. The records for each ISBN should be
// grouped together.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-23-count-books.cpp && \
./a.out <../data/many-books.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-23-count-books.cpp && ^
a <..\data\many-books.txt

=== Input ===
(many-books.txt)
0-201-70353-X 4 24.99
0-201-82470-1 4 45.39
0-201-88954-4 2 15.00
0-201-88954-4 5 12.00
0-201-88954-4 7 12.00
0-201-88954-4 2 12.00
0-399-82477-1 2 45.39
0-399-82477-1 3 45.39
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00

=== Output ===
(many-books.txt)
0-201-70353-X occurs 1 times
0-201-82470-1 occurs 1 times
0-201-88954-4 occurs 4 times
0-399-82477-1 occurs 2 times
0-201-78345-X occurs 2 times
*/

// Modified from 01-17-count-numbers.cpp

#include "Sales_item.h"
#include <iostream>

int main() {
  Sales_item curr_book, book;
  if (std::cin >> curr_book) {
    int cnt = 1;
    while (std::cin >> book) {
      if (book.isbn() == curr_book.isbn()) {
        ++cnt;
      } else {
        std::cout << curr_book.isbn() << " occurs " << cnt << " times"
                  << std::endl;
        curr_book = book;
        cnt = 1;
      }
    }
    std::cout << curr_book.isbn() << " occurs " << cnt << " times" << std::endl;
  }
  return 0;
}
