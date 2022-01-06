// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.2: Add the combine and isbn members to the Sales_data class you
// wrote for the exercises in § 2.6.2 (p. 76).

// Exercise 7.3: Revise your transaction-processing program from § 7.1.1 (p.
// 256) to use these members.

// Modified from 07-01-sales-data.cpp

#include "07-02-sales-data.hpp"
#include <iostream>
#include <string>

std::string Sales_data::isbn() const { return book_number; }

Sales_data &Sales_data::combine(const Sales_data &data) {
  if (isbn() == data.isbn()) {
    units_sold += data.units_sold;
    revenue += data.revenue;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
  }
  return *this;
}

std::istream &read(std::istream &is, Sales_data &data) {
  double price = 0;
  is >> data.book_number >> data.units_sold >> price;
  data.revenue = price * data.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &data) {
  return os << data.book_number << " " << data.units_sold << " " << data.revenue
            << " " << data.revenue / data.units_sold << std::endl;
}
