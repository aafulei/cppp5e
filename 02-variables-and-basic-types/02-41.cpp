// 21/12/21 = Tue

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

#include <iostream>
#include <string>

struct SalesData {
  std::string bookNo;
  unsigned quantity;
  double revenue;
};

int main() {
  SalesData d1, d2;
  double price;
  std::cin >> d1.bookNo >> d1.quantity >> price;
  if (std::cin) {
    d1.revenue = d1.quantity * price;
  } else {
    std::cerr << "No data?!" << std::endl;
    return 1;
  }
  std::cin >> d2.bookNo >> d2.quantity >> price;
  if (std::cin) {
    d2.revenue = d2.quantity * price;
  } else {
    std::cerr << "No data?!" << std::endl;
    return 1;
  }
  if (d1.bookNo == d2.bookNo) {
    unsigned total_quant = d1.quantity + d2.quantity;
    double total_revenue = d1.revenue + d2.revenue;
    std::cout << d1.bookNo << " " << total_quant << " " << total_revenue << " ";
    if (total_revenue != 0) {
      std::cout << (total_revenue / total_quant) << std::endl;
    } else {
      std::cout << "(no sales)" << std::endl;
    }
    return 0;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
    return 1;
  }
}
