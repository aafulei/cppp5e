// 21/12/19 = Sun
// 18/01/15 = Mon

// Exercise 1.25: Using the Sales_item.h header from the Web site, compile and
// execute the bookstore program presented in this section.

// Note: This program is the same as the one in the textbook.

#include "Sales_item.h"
#include <iostream>

int main() {
  Sales_item total;
  if (std::cin >> total) {
    Sales_item trans;
    while (std::cin >> trans) {
      if (total.isbn() == trans.isbn()) {
        total += trans;
      } else {
        std::cout << total << std::endl;
        total = trans;
      }
    }
    std::cout << total << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}
