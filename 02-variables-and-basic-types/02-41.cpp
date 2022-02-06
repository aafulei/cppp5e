// 21/12/21 = Tue

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

struct Sales_data {
  std::string bookNo;
  unsigned units_sold;
  double revenue;
};

int main() {
  Sales_data d1, d2;
  double price;
  std::cin >> d1.bookNo >> d1.units_sold >> price;
  if (std::cin) {
    d1.revenue = d1.units_sold * price;
  } else {
    std::cerr << "No data?!" << std::endl;
    return 1;
  }
  std::cin >> d2.bookNo >> d2.units_sold >> price;
  if (std::cin) {
    d2.revenue = d2.units_sold * price;
  } else {
    std::cerr << "No data?!" << std::endl;
    return 1;
  }
  if (d1.bookNo == d2.bookNo) {
    unsigned total_units = d1.units_sold + d2.units_sold;
    double total_revenue = d1.revenue + d2.revenue;
    std::cout << d1.bookNo << " " << total_units << " " << total_revenue << " ";
    if (total_revenue != 0) {
      std::cout << (total_revenue / total_units) << std::endl;
    } else {
      std::cout << "(no sales)" << std::endl;
    }
    return 0;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
    return 1;
  }
}
