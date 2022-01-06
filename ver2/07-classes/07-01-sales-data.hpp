// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.1: Write a version of the transaction-processing program from
// § 1.6 (p. 24) using the Sales_data class you defined for the exercises in
// § 2.6.1 (p. 72).

#include <iostream>
#include <string>

struct Sales_data {
  std::string book_number;
  unsigned units_sold;
  double revenue;
};

std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
Sales_data &combine(Sales_data &, const Sales_data &);
