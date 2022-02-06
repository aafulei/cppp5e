// 21/12/21 = Tue

// Exercise 2.42: Write your own version of the Sales_data.h header and use it
// to rewrite the exercise from § 2.6.2 (p. 76).

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

// Exercise 1.21: Write a program that reads two Sales_item objects that have
// the same ISBN and produces their sum.

// Modified from 02-41.cpp

#include "Sales_data.h"
#include <iostream>

int main() {
  Sales_data data1, data2;
  double price = 0;
  std::cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;
  std::cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;
  if (data1.bookNo == data2.bookNo) {
    unsigned total_units = data1.units_sold + data2.units_sold;
    double total_revenue = data1.revenue + data2.revenue;
    std::cout << data1.bookNo << " " << total_units << " " << total_revenue
              << " ";
    if (total_revenue != 0) {
      std::cout << (total_revenue / total_units) << std::endl;
    } else {
      std::cout << "(no sales)" << std::endl;
    }
    return 0;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
    return -1;
  }
}
