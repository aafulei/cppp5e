// 21/12/21 = Tue
// 18/02/02 = Fri

// Exercise 2.40: Write your own version of the Sales_data class.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-40-sales-data.cpp && \
./a.out <../data/one-book.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 02-40-sales-data.cpp && ^
a <../data/one-book.txt

=== Input ===
(one-book.txt)
0-201-88954-4 2 15.00

=== Output ===
(one-book.txt)
Book number = 0-201-88954-4
Units sold = 2
Revenue = 30
*/

#include <iostream>
#include <string>

struct Sales_data {
  std::string book_number;
  unsigned units_sold;
  double revenue;
};

int main() {
  Sales_data data;
  double price = 0;
  std::cin >> data.book_number >> data.units_sold >> price;
  data.revenue = price * data.units_sold;
  std::cout << "Book number = " << data.book_number << std::endl;
  std::cout << "Units sold = " << data.units_sold << std::endl;
  std::cout << "Revenue = " << data.revenue << std::endl;
  return 0;
}
