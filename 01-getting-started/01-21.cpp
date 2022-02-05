// 21/12/19 = Sun
// 18/01/15 = Mon

// Exercise 1.21: Write a program that reads two Sales_item objects that have
// the same ISBN and produces their sum.

// Note: This program assumes valid input: two books with the same ISBN.

#include "Sales_item.h"
#include <iostream>

int main() {
  Sales_item item1, item2;
  std::cin >> item1 >> item2;
  std::cout << item1 + item2 << std::endl;
  return 0;
}
