// 21/12/22 = Wed
// 18/01/26 = Fri

// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

// Exercise 1.20: http://www.informit.com/title/032174113 contains a copy of
// Sales_item.h in the Chapter 1 code directory. Copy that file to your working
// directory. Use it to write a program that reads a set of book sales
// transactions, writing each transaction to the standard output.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-read-books.cpp && \
./a.out <../data/many-books.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-read-books.cpp && ^
a <..\data\many-books.txt

=== Input ===
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

=== Output ===
(many-books.txt)
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 2 30 15
0-201-88954-4 5 60 12
0-201-88954-4 7 84 12
0-201-88954-4 2 24 12
0-399-82477-1 2 90.78 45.39
0-399-82477-1 3 136.17 45.39
0-201-78345-X 3 60 20
0-201-78345-X 2 50 25
*/

// Modified from 02-41-read-books.cpp

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
  while (cin >> data.book_number >> data.units_sold >> price) {
    data.revenue = data.units_sold * price;
    cout << data.book_number << " " << data.units_sold << " " << data.revenue
         << " " << price << endl;
  }
  return 0;
}
