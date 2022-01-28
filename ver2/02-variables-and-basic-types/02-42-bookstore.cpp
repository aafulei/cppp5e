// 21/12/21 = Tue
// 18/02/02 = Fri

// Exercise 2.42: Write your own version of the Sales_data.h header and use it
// to rewrite the exercise from § 2.6.2 (p. 76).

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

// Exercise 1.25: Using the Sales_item.h header from the Web site, compile and
// execute the bookstore program presented in this section.

// Note: This program assumes valid input. The records for each ISBN should be
// grouped together.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-42-bookstore.cpp && \
./a.out <../data/many-books.txt && \
./a.out <../data/many-books-no-sales.txt && \
./a.out <../data/empty.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-42-bookstore.cpp && ^
a <..\data\many-books.txt && ^
a <..\data\many-books-no-sales.txt && ^
a <..\data\empty.txt

=== Input ====
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

(many-books-no-sales.txt)
0-201-70353-X 0 24.99
0-201-82470-1 0 45.39
0-201-88954-4 0 15.00
0-201-88954-4 0 12.00
0-201-88954-4 0 12.00
0-201-88954-4 0 12.00
0-399-82477-1 0 45.39
0-399-82477-1 0 45.39
0-201-78345-X 0 20.00
0-201-78345-X 0 25.00

(empty.txt)

=== Output ===
(many-books.txt)
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22

(two-books-no-sales.txt)
0-201-70353-X 0 0 (no sales)
0-201-82470-1 0 0 (no sales)
0-201-88954-4 0 0 (no sales)
0-399-82477-1 0 0 (no sales)
0-201-78345-X 0 0 (no sales)

(empty.txt)
No data?!
*/

// Modified from 02-41-bookstore.cpp

#include "Sales_data.h"
#include <iostream>

int main() {
  Sales_data total;
  double price = 0;
  if (std::cin >> total.book_number >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    Sales_data trans;
    while (std::cin >> trans.book_number >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;
      if (total.book_number == trans.book_number) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        std::cout << total.book_number << " " << total.units_sold << " "
                  << total.revenue << " ";
        if (total.revenue != 0) {
          std::cout << (total.revenue / total.units_sold) << std::endl;
        } else {
          std::cout << "(no sales)" << std::endl;
        }
        total = trans;
        total.units_sold = total.units_sold;
        total.revenue = total.revenue;
      }
    }
    std::cout << total.book_number << " " << total.units_sold << " "
              << total.revenue << " ";
    if (total.revenue != 0) {
      std::cout << (total.revenue / total.units_sold) << std::endl;
    } else {
      std::cout << "(no sales)" << std::endl;
    }
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}