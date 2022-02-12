// 22/02/12 = Sat
// 18/02/10 = Sat

// Exercise 7.26: Define Sales_data::avg_price as an inline function.

// Modified from 07-21.cpp

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
  double avg_price() const; // Add
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

Sales_data::Sales_data() = default;

Sales_data::Sales_data(const std::string &bookNo) : bookNo(bookNo) {}

Sales_data::Sales_data(const std::string &bookNo, unsigned units_sold,
                       double price)
    : bookNo(bookNo), units_sold(units_sold), revenue(price * units_sold) {}

Sales_data::Sales_data(std::istream &is) { read(is, *this); }

std::string Sales_data::isbn() const { return bookNo; }

// Add
inline double Sales_data::avg_price() const {
  if (units_sold == 0) {
    return 0;
  }
  return revenue / units_sold;
}

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
    os << data.avg_price() << std::endl;
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
  Sales_data total;
  if (read(std::cin, total)) {
    Sales_data trans;
    while (read(std::cin, trans)) {
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
