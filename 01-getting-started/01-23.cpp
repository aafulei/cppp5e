// 21/12/19 = Sun
// 18/01/15 = Mon

// Exercise 1.23: Write a program that reads several transactions and counts how
// many transactions occur for each ISBN.

// Note: This program assumes valid input. The records for each ISBN should be
// grouped together.

// Modified from 01-17.cpp

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
