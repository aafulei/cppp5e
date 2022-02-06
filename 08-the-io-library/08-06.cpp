// 22/01/30 = Sun
// 18/02/12 = Mon
// 18/01/15 = Mon

// Exercise 8.6: Rewrite the bookstore program from Section 7.1.1 (p. 256) to
// read its transactions from a file. Pass the name of the file as an argument
// to main (Section 6.2.5, p. 218).

// Exercise 7.1: Write a version of the transaction-processing program from
// § 1.6 (p. 24) using the Sales_data class you defined for the exercises in
// § 2.6.1 (p. 72).

// Exercise 2.40: Write your own version of the Sales_data class.

#include <fstream>
#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

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

// add data to total, like operator+=
Sales_data &combine(Sales_data &total, const Sales_data &trans) {
  if (total.bookNo == trans.bookNo) {
    total.units_sold += trans.units_sold;
    total.revenue += trans.revenue;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
  }
  return total;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " file" << std::endl;
    return 1;
  }
  std::ifstream ifs(argv[1]);
  Sales_data total;
  if (read(ifs, total)) {
    Sales_data trans;
    while (read(ifs, trans)) {
      if (total.bookNo == trans.bookNo) {
        combine(total, trans);
      } else {
        print(std::cout, total);
        total = trans;
      }
    }
    print(std::cout, total);
  } else {
    std::cerr << "No data?!" << std::endl;
    return 1;
  }
  return 0;
}
