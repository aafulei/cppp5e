// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.6: Define your own versions of the add, read, and print functions.

// Exercise 7.7: Rewrite the transaction-processing program you wrote for the
// exercises in § 7.1.2 (p. 260) to use these new functions.

#include <iostream>
#include <string>

struct Sales_data {
  std::string book_number;
  unsigned units_sold;
  double revenue;

  std::string isbn() const;
  Sales_data &combine(const Sales_data &);
};

std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &); // Add to 07-02.hpp
