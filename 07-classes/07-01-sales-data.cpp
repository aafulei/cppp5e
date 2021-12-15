// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.1: Write a version of the transaction-processing program from
// § 1.6 (p. 24) using the Sales_data class you defined for the exercises in
// § 2.6.1 (p. 72).

#include "07-01-sales-data.hpp"
#include <iostream>
#include <string>

// record example: 978-7-121-20038-0 1 105
std::istream &read(std::istream &is, Sales_data &data) {
  double price = 0;
  is >> data.book_number >> data.units_sold >> price;
  data.revenue = price * data.units_sold;
  return is;
}

// output example: 978-7-121-20038-0 10 1000 100
std::ostream &print(std::ostream &os, const Sales_data &data) {
  return os << data.book_number << " " << data.units_sold << " " << data.revenue
            << " " << data.revenue / data.units_sold << std::endl;
}

// add new_data to total_data, like operator+=
Sales_data &combine(Sales_data &total_data, const Sales_data &new_data) {
  if (total_data.book_number == new_data.book_number) {
    total_data.units_sold += new_data.units_sold;
    total_data.revenue += new_data.revenue;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
  }
  return total_data;
}
