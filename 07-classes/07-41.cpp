// 22/02/12 = Sat
// 18/02/10 = Sat

// Exercise 7.41: Rewrite your own version of the Sales_data class to use
// delegating constructors. Add a statement to the body of each of the
// constructors that prints a message whenever it is executed. Write
// declarations to construct a Sales_data object in every way possible. Study
// the output until you are certain you understand the order of execution among
// delegating constructors.

// Modified from 07-11.cpp and 07-21.cpp

#include <iostream>
#include <string>

class Sales_data {
  friend std::istream &read(std::istream &is, Sales_data &data);
  friend std::ostream &print(std::ostream &os, const Sales_data &data);
  friend Sales_data add(const Sales_data &data1, const Sales_data &data2);

public:
  Sales_data();
  Sales_data(const std::string &bookNo);
  Sales_data(const std::string &bookNo, unsigned units_sold, double price);
  Sales_data(std::istream &is);

  std::string isbn() const;
  Sales_data &combine(const Sales_data &data);

private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &data);
std::ostream &print(std::ostream &os, const Sales_data &data);
Sales_data add(const Sales_data &data1, const Sales_data &data2);

// --- impl --------------------------------------------------------------------

Sales_data::Sales_data() : Sales_data("", 0, 0) {
  std::clog << "[TRACE] Sales_data()" << std::endl;
}

Sales_data::Sales_data(const std::string &bookNo) : Sales_data(bookNo, 0, 0) {
  std::clog << "[TRACE] Sales_data(const std::string &)" << std::endl;
}

Sales_data::Sales_data(const std::string &bookNo, unsigned units_sold,
                       double price)
    : bookNo(bookNo), units_sold(units_sold), revenue(price * units_sold) {
  std::clog << "[TRACE] Sales_data(const std::string &, unsigned, double)"
            << std::endl;
}

Sales_data::Sales_data(std::istream &is) : Sales_data() {
  std::clog << "[TRACE] Sales_data(std::istream &is)" << std::endl;
  read(is, *this);
}

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

void test() {
  std::string bookNo = "978-7-121-20038-0";
  std::clog << "[TRACE] Sales_data sd0;" << std::endl;
  Sales_data sd0;
  print(std::cout, sd0);
  std::clog << "[TRACE] Sales_data sd1(bookNo);" << std::endl;
  Sales_data sd1(bookNo);
  print(std::cout, sd1);
  std::clog << "[TRACE] Sales_data sd2(bookNo, 1, 105);" << std::endl;
  Sales_data sd2(bookNo, 1, 105);
  print(std::cout, sd2);
  std::clog << "[TRACE] Sales_data sd3(std::cin);" << std::endl;
  Sales_data sd3(std::cin);
  print(std::cout, sd3);
}

int main() {
  test();
  return 0;
}
