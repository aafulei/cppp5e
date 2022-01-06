// 21/12/22 = Wed
// 18/01/26 = Fri

// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

// Exercise 1.21: Write a program that reads two Sales_item objects that have
// the same ISBN and produces their sum.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-sum-two-books.cpp && \
./a.out <../data/two-books.txt && \
./a.out <../data/two-books-no-sales.txt && \
./a.out <../data/two-books-different.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-sum-two-books.cpp && ^
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

// Modified from 02-41-sum-two-books.cpp

#include <iostream>
#include <string>

using std::cerr;
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
  Sales_data data1, data2;
  double price = 0;
  cin >> data1.book_number >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;
  cin >> data2.book_number >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;
  if (data1.book_number == data2.book_number) {
    unsigned total_units_sold = data1.units_sold + data2.units_sold;
    double total_revenue = data1.revenue + data2.revenue;
    cout << data1.book_number << " " << total_units_sold << " " << total_revenue
         << " ";
    if (total_revenue != 0) {
      cout << (total_revenue / total_units_sold) << endl;
    } else {
      cout << "(no sales)" << endl;
    }
    return 0;
  } else {
    cerr << "Data must refer to the same ISBN" << endl;
    return -1;
  }
}
