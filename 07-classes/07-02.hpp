// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.2: Add the combine and isbn members to the Sales_data class you
// wrote for the exercises in § 2.6.2 (p. 76).

// Exercise 7.3: Revise your transaction-processing program from § 7.1.1 (p.
// 256) to use these members.

// Modified from 07-01-sales-data.hpp

#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold;
  double revenue;

  std::string isbn() const;                // Add
  Sales_data &combine(const Sales_data &); // Add
};

std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
