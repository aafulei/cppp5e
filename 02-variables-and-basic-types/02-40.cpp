// 21/12/21 = Tue
// 18/02/02 = Fri

// Exercise 2.40: Write your own version of the Sales_data class.

#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold;
  double revenue;
};

int main() {
  Sales_data data;
  if (double price; std::cin >> data.bookNo >> data.units_sold >> price) {
    data.revenue = price * data.units_sold;
    std::cout << "Book number = " << data.bookNo << std::endl;
    std::cout << "Units sold = " << data.units_sold << std::endl;
    std::cout << "Revenue = " << data.revenue << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
  }
  return 0;
}
