// 21/12/21 = Tue
// 18/02/02 = Fri

// Exercise 2.40: Write your own version of the Sales_data class.

#include <iostream>
#include <string>

struct SalesData {
  std::string bookNo;
  unsigned quantity;
  double revenue;
};

int main() {
  SalesData data;
  if (double price; std::cin >> data.bookNo >> data.quantity >> price) {
    data.revenue = price * data.quantity;
    std::cout << "Book number = " << data.bookNo << std::endl;
    std::cout << "Units sold = " << data.quantity << std::endl;
    std::cout << "Revenue = " << data.revenue << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
  }
  return 0;
}
