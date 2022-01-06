// 21/12/22 = Wed
// 18/01/26 = Fri

// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

// Exercise 1.22: Write a program that reads several transactions for the same
// ISBN. Write the sum of all the transactions that were read.

// Note: This program assumes valid input: several books with the same ISBNs.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-sum-several-books.cpp && \
./a.out <../data/several-books.txt && \
./a.out <../data/several-books-no-sales.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-sum-several-books.cpp && ^
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

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data {
  string book_number;
  unsigned units_sold;
  double revenue;
};

int main() {
  Sales_data data;
  double price = 0;
  unsigned total_units_sold = 0;
  double total_revenue = 0;
  while (cin >> data.book_number >> data.units_sold >> price) {
    data.revenue = data.units_sold * price;
    total_units_sold += data.units_sold;
    total_revenue += data.revenue;
  }
  cout << data.book_number << " " << total_units_sold << " " << total_revenue
       << " ";
  if (total_revenue != 0) {
    cout << (total_revenue / total_units_sold) << endl;
  } else {
    cout << "(no sales)" << endl;
  }
  return 0;
}
