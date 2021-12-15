// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.1: Write a version of the transaction-processing program from
// § 1.6 (p. 24) using the Sales_data class you defined for the exercises in
// § 2.6.1 (p. 72).

/* (Linux/macOS) clang++ -std=c++11 -pedantic -Wall -Wextra \
07-01-sales-data.cpp 07-01-proc.cpp && ./a.out <../data/trans.txt

(Windows) clang++ -std=c++11 -pedantic -Wall -Wextra ^
07-01-sales-data.cpp 07-01-proc.cpp && a <../data/trans.txt */

#include "07-01-sales-data.hpp"
#include <iostream>

int main() {
  Sales_data total;
  if (read(std::cin, total)) {
    Sales_data trans;
    while (read(std::cin, trans)) {
      if (total.book_number == trans.book_number) {
        combine(total, trans);
      } else {
        print(std::cout, total);
        total = trans;
      }
    }
    print(std::cout, total);
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}
