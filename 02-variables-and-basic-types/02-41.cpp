// 21/12/21 = Tue

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

// Exercise 1.21: Write a program that reads two Sales_item objects that have
// the same ISBN and produces their sum.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-41-sum-two-books.cpp && \
./a.out <../data/two-books.txt && \
./a.out <../data/two-books-no-sales.txt && \
./a.out <../data/two-books-different.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-41-sum-two-books.cpp && ^
a <..\data\two-books.txt && ^
a <..\data\two-books-no-sales.txt && ^
a <..\data\two-books-different.txt

=== Input ===
(two-books.txt)
0-201-88954-4 2 15.00
0-201-88954-4 5 12.00

(two-books-no-sales.txt)
0-201-88954-4 0 15.00
0-201-88954-4 0 12.00

(two-books-different.txt)
0-201-70353-X 4 24.99
0-201-82470-1 4 45.39

=== Output ===
(two-books.txt)
0-201-88954-4 7 90 12.8571

(two-books-no-sales.txt)
0-201-88954-4 0 0 (no sales)

(two-books-different.txt)
Data must refer to the same ISBN
*/

// Modified from 01-21-sum-two-books.cpp

#include <iostream>
#include <string>

struct Sales_data {
  std::string book_number;
  unsigned units_sold;
  double revenue;
};

int main() {
  Sales_data data1, data2;
  double price = 0;
  std::cin >> data1.book_number >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;
  std::cin >> data2.book_number >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;
  if (data1.book_number == data2.book_number) {
    unsigned total_units_sold = data1.units_sold + data2.units_sold;
    double total_revenue = data1.revenue + data2.revenue;
    std::cout << data1.book_number << " " << total_units_sold << " "
              << total_revenue << " ";
    if (total_revenue != 0) {
      std::cout << (total_revenue / total_units_sold) << std::endl;
    } else {
      std::cout << "(no sales)" << std::endl;
    }
    return 0;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
    return -1;
  }
}
