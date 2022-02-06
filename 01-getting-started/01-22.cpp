// 21/12/19 = Sun
// 18/01/15 = Mon

// Exercise 1.22: Write a program that reads several transactions for the same
// ISBN. Write the sum of all the transactions that were read.

// Note: This program assumes valid input: several books with the same ISBN.

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
