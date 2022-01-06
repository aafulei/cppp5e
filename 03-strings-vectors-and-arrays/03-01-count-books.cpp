// 21/12/22 = Wed
// 18/01/26 = Fri

// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

// Exercise 1.23: Write a program that reads several transactions and counts how
// many transactions occur for each ISBN.

// Exercise 1.24: Test the previous program by giving multiple transactions
// representing multiple ISBNs. The records for each ISBN should be grouped
// together.

// Note: This program assumes valid input. The records for each ISBN should be
// grouped together.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-count-books.cpp && \
./a.out <../data/many-books.txt

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 03-01-count-books.cpp && ^
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
0-201-70353-X occurs 1 times
0-201-82470-1 occurs 1 times
0-201-88954-4 occurs 4 times
0-399-82477-1 occurs 2 times
0-201-78345-X occurs 2 times
*/

// Modified from 02-41-count-books.cpp

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
  Sales_data curr, next;
  double price = 0;
  if (cin >> curr.book_number >> curr.units_sold >> price) {
    int cnt = 1;
    while (cin >> next.book_number >> next.units_sold >> price) {
      if (curr.book_number == next.book_number) {
        ++cnt;
      } else {
        cout << curr.book_number << " occurs " << cnt << " times" << endl;
        curr = next;
        cnt = 1;
      }
    }
    cout << curr.book_number << " occurs " << cnt << " times" << endl;
  }
  return 0;
}
