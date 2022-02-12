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

// Modified based on 07-06.hpp

#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0; // Add in-class initializer
  double revenue = 0.0;    // Add in-class initializer

  Sales_data();                                      // Add to 07-06.hpp
  Sales_data(const std::string &);                   // Add to 07-06.hpp
  Sales_data(const std::string &, unsigned, double); // Add to 07-06.hpp
  Sales_data(std::istream &is) {                     // Add to 07-06.hpp
    double price = 0;                         // I prefer to put definition in
    is >> bookNo >> units_sold >> price; // cpp file, but Ex 7.12 requires
    revenue = price * units_sold;             // it be put here. If fwd-declare
  }                                           // is allowed, read() can be used.
  std::string isbn() const;
  Sales_data &combine(const Sales_data &);
};

std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
