// 22/02/12 = Sat
// 21/12/17 = Fri
// 18/02/09 = Fri

// Exercise 7.13: Rewrite the program from page 255 to use the istream
// constructor.

// Modified from 07-11.cpp

#include <iostream>
#include <string>

struct Sales_data {
  Sales_data();
  Sales_data(const std::string &bookNo);
  Sales_data(const std::string &bookNo, unsigned units_sold, double price);
  Sales_data(std::istream &is);

  std::string isbn() const;
  Sales_data &combine(const Sales_data &data);

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &data);

// --- impl --------------------------------------------------------------------

Sales_data::Sales_data() = default;

Sales_data::Sales_data(const std::string &bookNo) : bookNo(bookNo) {}

Sales_data::Sales_data(const std::string &bookNo, unsigned units_sold,
                       double price)
    : bookNo(bookNo), units_sold(units_sold), revenue(price * units_sold) {}

Sales_data::Sales_data(std::istream &is) { read(is, *this); }

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
  os << data.bookNo << " " << data.units_sold << " " << data.revenue << " ";
  if (data.units_sold) {
    os << data.revenue / data.units_sold << std::endl;
  } else {
    os << "(no sales)" << std::endl;
  }
  return os;
}

// add data1 and data2
Sales_data add(const Sales_data &data1, const Sales_data &data2) {
  Sales_data sum = data1;
  return sum.combine(data2);
}

int main() {
  Sales_data total(std::cin);
  if (std::cin) {
    while (true) {
      Sales_data trans(std::cin);
      if (!std::cin) {
        break;
      }
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
