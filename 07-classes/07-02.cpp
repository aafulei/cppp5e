// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.2: Add the combine and isbn members to the Sales_data class you
// wrote for the exercises in § 2.6.2 (p. 76).

// Exercise 7.3: Revise your transaction-processing program from Section 7.1.1
// (p. 256) to use these members.

#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  std::string isbn() const;                    // Add
  Sales_data &combine(const Sales_data &data); // Add
};

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

int main() {
  Sales_data total;
  if (read(std::cin, total)) {
    Sales_data trans;
    while (read(std::cin, trans)) {
      if (total.isbn() == trans.isbn()) { // Change
        total.combine(trans);             // Change
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
