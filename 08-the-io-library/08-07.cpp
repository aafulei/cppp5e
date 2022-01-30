// 22/01/30 = Sun
// 18/02/12 = Mon
// 18/01/16 = Tue

// Exercise 8.7: Revise the bookstore program from the previous section to write
// its output to a file. Pass the name of that file as a second argument to
// main.

// Exercise 8.6: Rewrite the bookstore program from Section 7.1.1 (p. 256) to
// read its transactions from a file. Pass the name of the file as an argument
// to main (Section 6.2.5, p. 218).

// Exercise 7.1: Write a version of the transaction-processing program from
// § 1.6 (p. 24) using the Sales_data class you defined for the exercises in
// § 2.6.1 (p. 72).

// Exercise 2.40: Write your own version of the Sales_data class.

// Modified from 08-06.cpp

#include <fstream>
#include <iostream>
#include <string>

struct SalesData {
  std::string bookNo;
  unsigned quantity = 0;
  double revenue = 0.0;
};

// record example: 978-7-121-20038-0 1 105
std::istream &read(std::istream &is, SalesData &data) {
  double price = 0;
  is >> data.bookNo >> data.quantity >> price;
  data.revenue = price * data.quantity;
  return is;
}

// output example: 978-7-121-20038-0 10 1000 100
std::ostream &print(std::ostream &os, const SalesData &data) {
  return os << data.bookNo << " " << data.quantity << " " << data.revenue << " "
            << data.revenue / data.quantity << std::endl;
}

// add data to total, like operator+=
SalesData &combine(SalesData &total, const SalesData &trans) {
  if (total.bookNo == trans.bookNo) {
    total.quantity += trans.quantity;
    total.revenue += trans.revenue;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
  }
  return total;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " inFile outFile" << std::endl;
    return 1;
  }
  std::ofstream ofs(argv[2]);
  if (!ofs) {
    std::cerr << "Can't open " << argv[2] << std::endl;
    return 1;
  }
  std::ifstream ifs(argv[1]);
  SalesData total;
  if (read(ifs, total)) {
    SalesData trans;
    while (read(ifs, trans)) {
      if (total.bookNo == trans.bookNo) {
        combine(total, trans);
      } else {
        print(ofs, total);
        total = trans;
      }
    }
    print(ofs, total);
  } else {
    std::cerr << "No data?!" << std::endl;
    return 1;
  }
  return 0;
}
