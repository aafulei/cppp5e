// 22/02/06 = Sun
// 21/12/22 = Wed
// 18/01/26 = Fri

// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to
// 100.

// Exercise 1.10: In addition to the ++ operator that adds 1 to its operand,
// there is a decrement operator (--) that subtracts 1. Use the decrement
// operator to write a while that prints the numbers from ten down to zero.

// Exercise 1.11: Write a program that prompts the user for two integers. Print
// each number in the range specified by those two integers.

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

// Exercise 1.20: http://www.informit.com/title/032174113 contains a copy of
// Sales_item.h in the Chapter 1 code directory. Copy that file to your working
// directory. Use it to write a program that reads a set of book sales
// transactions, writing each transaction to the standard output.

// Exercise 1.21: Write a program that reads two Sales_item objects that have
// the same ISBN and produces their sum.

// Exercise 1.22: Write a program that reads several transactions for the same
// ISBN. Write the sum of all the transactions that were read.

// Exercise 1.23: Write a program that reads several transactions and counts how
// many transactions occur for each ISBN.

// Exercise 1.24: Test the previous program by giving multiple transactions
// representing multiple ISBNs. The records for each ISBN should be grouped
// together.

// Exercise 1.25: Using the Sales_item.h header from the Web site, compile and
// execute the bookstore program presented in this section.

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
  Sales_data total;
  double price = 0;
  if (cin >> total.book_number >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    Sales_data trans;
    while (cin >> trans.book_number >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;
      if (total.book_number == trans.book_number) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        cout << total.book_number << " " << total.units_sold << " "
             << total.revenue << " ";
        if (total.revenue != 0) {
          cout << (total.revenue / total.units_sold) << endl;
        } else {
          cout << "(no sales)" << endl;
        }
        total = trans;
        total.units_sold = total.units_sold;
        total.revenue = total.revenue;
      }
    }
    cout << total.book_number << " " << total.units_sold << " " << total.revenue
         << " ";
    if (total.revenue != 0) {
      cout << (total.revenue / total.units_sold) << endl;
    } else {
      cout << "(no sales)" << endl;
    }
  } else {
    cerr << "No data?!" << endl;
    return -1;
  }
  return 0;
}
