// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.6: Define your own versions of the add, read, and print functions.

// Exercise 7.7: Rewrite the transaction-processing program you wrote for the
// exercises in § 7.1.2 (p. 260) to use these new functions.

// (Linux/macOS) clang++ -std=c++11 07-06.cpp && ./a.out <../data/records
// (Windows) clang++ -std=c++11 07-06.cpp && a <../data/records

#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  std::string isbn() const;
  Sales_data &combine(const Sales_data &);
};

// --- impl --------------------------------------------------------------------

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

// record example: 978-7-121-20038-0 1 105
std::istream &read(std::istream &is, Sales_data &data) {
  double price = 0;
  is >> data.bookNo >> data.units_sold >> price;
  data.revenue = price * data.units_sold;
  return is;
}

// output example: 978-7-121-20038-0 10 1000 100
std::ostream &print(std::ostream &os, const Sales_data &data) {
  return os << data.bookNo << " " << data.units_sold << " " << data.revenue
            << " " << data.revenue / data.units_sold << std::endl;
}

// add data1 and data2
Sales_data add(const Sales_data &data1, const Sales_data &data2) {
  Sales_data sum = data1;
  return sum.combine(data2);
}

// --- main --------------------------------------------------------------------

int main() {
  Sales_data total;
  if (read(std::cin, total)) {
    Sales_data trans;
    while (read(std::cin, trans)) {
      if (total.isbn() == trans.isbn()) {
        total = add(total, trans); // Change to 07-02.cpp
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
