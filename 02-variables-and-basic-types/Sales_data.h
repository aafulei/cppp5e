// 21/12/21 = Tue

// Exercise 2.42: Write your own version of the Sales_data.h header and use it
// to rewrite the exercise from § 2.6.2 (p. 76).

// Exercise 2.40: Write your own version of the Sales_data class.

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold;
  double revenue;
};

#endif
