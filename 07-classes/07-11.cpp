// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.11: Add constructors to your Sales_data class and write a program
// to use each of the constructors.

// Exercise 7.12: Move the definition of the Sales_data constructor that takes
// an istream into the body of the Sales_data class.

// Exercise 7.13: Rewrite the program from page 255 to use the istream
// constructor.

// Exercise 7.14: Write a version of the default constructor that explicitly
// initializes the members to the values we have provided as in-class
// initializers.

// Modified based on 07-06.cpp

// (Linux/macOS) clang++ -std=c++11 07-11.cpp && ./a.out <../data/records
// (Windows) clang++ -std=c++11 07-11.cpp && a <../data/records

#include "07-11.hpp"
#include <iostream>
#include <string>

// --- impl --------------------------------------------------------------------

// Sales_data::Sales_data() = default;
Sales_data::Sales_data() : units_sold(0), revenue(0.0){}; // requried by Ex 7.14

Sales_data::Sales_data(const std::string &s) : bookNo(s) {}

Sales_data::Sales_data(const std::string &s, unsigned n, double p)
    : bookNo(s), units_sold(n), revenue(p * n) {}

std::string Sales_data::isbn() const { return bookNo; }

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
  is >> data.bookNo >> data.units_sold >> price;
  data.revenue = price * data.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &data) {
  return os << data.bookNo << " " << data.units_sold << " " << data.revenue
            << " " << data.revenue / data.units_sold << std::endl;
}

// --- main --------------------------------------------------------------------

int main() {
  Sales_data total(std::cin);     // Change to 07-06.cpp
  if (std::cin) {                 // Change to 07-06.cpp
    while (true) {                // Change to 07-06.cpp
      Sales_data trans(std::cin); // Change to 07-06.cpp
      if (!std::cin)              // Change to 07-06.cpp
        break;                    // Change to 07-06.cpp
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(std::cout, total);
        total = trans;
      }
    }
    print(std::cout, total);
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}
