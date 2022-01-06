// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.2: Add the combine and isbn members to the Sales_data class you
// wrote for the exercises in § 2.6.2 (p. 76).

// Exercise 7.3: Revise your transaction-processing program from § 7.1.1 (p.
// 256) to use these members.

/* (Linux/macOS) clang++ -std=c++11 -pedantic -Wall -Wextra \
07-02-sales-data.cpp 07-02-proc.cpp && ./a.out <../data/trans.txt

(Windows) clang++ -std=c++11 -pedantic -Wall -Wextra ^
07-02-sales-data.cpp 07-02-proc.cpp && a <../data/trans.txt */

// Modified from 07-01-proc.cpp

#include "07-02-sales-data.hpp"
#include <iostream>

int main() {
  Sales_data total;
  if (read(std::cin, total)) {
    Sales_data trans;
    while (read(std::cin, trans)) {
      if (total.isbn() == trans.isbn()) { // Change
        total.combine(trans);             // Change
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
