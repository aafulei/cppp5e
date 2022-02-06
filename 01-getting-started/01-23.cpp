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
  Sales_item currVal, val;
  if (std::cin >> currVal) {
    int cnt = 1;
    while (std::cin >> val) {
      if (val.isbn() == currVal.isbn()) {
        ++cnt;
      } else {
        std::cout << currVal.isbn() << " occurs " << cnt << " times"
                  << std::endl;
        currVal = val;
        cnt = 1;
      }
    }
    std::cout << currVal.isbn() << " occurs " << cnt << " times" << std::endl;
  }
  return 0;
}
