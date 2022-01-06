// 21/12/21 = Tue

// Exercise 2.42: Write your own version of the Sales_data.h header and use it
// to rewrite the exercise from § 2.6.2 (p. 76).

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

// Exercise 1.22: Write a program that reads several transactions for the same
// ISBN. Write the sum of all the transactions that were read.

// Note: This program assumes valid input: several books with the same ISBNs.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-42-sum-several-books.cpp && \
./a.out <../data/several-books.txt && \
./a.out <../data/several-books-no-sales.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-42-sum-several-books.cpp && ^
a <..\data\several-books.txt && ^
a <..\data\several-books-no-sales.txt

=== Input ====
(several-books.txt)
0-201-88954-4 2 15.00
0-201-88954-4 5 12.00
0-201-88954-4 7 12.00
0-201-88954-4 2 12.00

(several-books-no-sales.txt)
0-201-88954-4 0 15.00
0-201-88954-4 0 12.00
0-201-88954-4 0 12.00
0-201-88954-4 0 12.00

=== Output ===
(several-books.txt)
0-201-88954-4 16 198 12.375

(several-books-no-sales.txt)
0-201-88954-4 0 0 (no sales)
*/

// Modified from 02-41-sum-several-books.cpp

#include "Sales_data.h"
#include <iostream>

int main() {
  Sales_data data;
  double price = 0;
  unsigned total_units_sold = 0;
  double total_revenue = 0;
  while (std::cin >> data.book_number >> data.units_sold >> price) {
    data.revenue = data.units_sold * price;
    total_units_sold += data.units_sold;
    total_revenue += data.revenue;
  }
  std::cout << data.book_number << " " << total_units_sold << " "
            << total_revenue << " ";
  if (total_revenue != 0) {
    std::cout << (total_revenue / total_units_sold) << std::endl;
  } else {
    std::cout << "(no sales)" << std::endl;
  }
  return 0;
}
