// 22/02/06 = Sun
// 21/12/21 = Tue
// 18/02/02 = Fri

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
// Sales_data class in the same file as your main function.

// Exercise 1.20: http://www.informit.com/title/032174113 contains a copy of
// Sales_item.h in the Chapter 1 code directory. Copy that file to your working
// directory. Use it to write a program that reads a set of book sales
// transactions, writing each transaction to the standard output.

// Exercise 1.21: Write a program that reads two Sales_item objects that have
// the same ISBN and produces their sum.

// Exercise 1.22: Write a program that reads several transactions for the same
// ISBN. Write the sum of all the transactions that were read.

// Exercise 1.23: Write a program that reads several transactions and counts how
// many transactions occur for each ISBN.

// Exercise 1.24: Test the previous program by giving multiple transactions
// representing multiple ISBNs. The records for each ISBN should be grouped
// together.

// Exercise 1.25: Using the Sales_item.h header from the Web site, compile and
// execute the bookstore program presented in this section.

#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

// read multiple book transactions and print them out
int rewrite_exercise_1_20() {
  Sales_data data;
  double price = 0;
  while (std::cin >> data.bookNo >> data.units_sold >> price) {
    data.revenue = data.units_sold * price;
    std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue
              << " " << data.revenue / data.units_sold << std::endl;
  }
  return 0;
}

// sum two book transactions: assume two books have the same ISBN
int rewrite_exercise_1_21() {
  Sales_data data1, data2;
  double price = 0;
  std::cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;
  std::cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;
  if (data1.bookNo == data2.bookNo) {
    unsigned totalCnt = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;
    std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
    if (totalCnt != 0) {
      std::cout << totalRevenue / totalCnt << std::endl;
    } else {
      std::cout << "(no sales)" << std::endl;
    }
    return 0;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
    return -1;
  }
}

// sum multiple book transactions: assume multiple books have the same ISBN
int rewrite_exercise_1_22() {
  Sales_data data, sum;
  double price = 0;
  if (std::cin >> data.bookNo >> data.units_sold >> price) {
    data.revenue = data.units_sold * price;
    sum = data;
    while (std::cin >> data.bookNo >> data.units_sold >> price) {
      data.revenue = data.units_sold * price;
      sum.units_sold += data.units_sold;
      sum.revenue += sum.revenue;
    }
  }
  std::cout << sum.bookNo << " " << sum.units_sold << " " << sum.revenue << " "
            << sum.revenue / sum.units_sold << std::endl;
  return 0;
}

// count book transactions
int rewrite_exercise_1_23() {
  Sales_data currVal, val;
  double price = 0;
  if (std::cin >> currVal.bookNo >> currVal.units_sold >> price) {
    currVal.revenue = currVal.units_sold * price;
    int cnt = 1;
    while (std::cin >> val.bookNo >> val.units_sold >> price) {
      val.revenue = val.units_sold * price;
      if (val.bookNo == currVal.bookNo) {
        ++cnt;
      } else {
        std::cout << currVal.bookNo << " occurs " << cnt << " times"
                  << std::endl;
        currVal = val;
        cnt = 1;
      }
    }
    std::cout << currVal.bookNo << " occurs " << cnt << " times" << std::endl;
  }
  return 0;
}

// bookstore program
int rewrite_exercise_1_25() {
  Sales_data total;
  double price = 0;
  if (std::cin >> total.bookNo >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;
      if (total.bookNo == trans.bookNo) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        std::cout << total.bookNo << " " << total.units_sold << " "
                  << total.revenue << " " << total.revenue / total.units_sold
                  << std::endl;
        total = trans;
      }
    }
    std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue
              << " " << total.revenue / total.units_sold << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}

int main() {
#ifdef RE120
  return rewrite_exercise_1_20();
#elif RE121
  return rewrite_exercise_1_21();
#elif RE122
  return rewrite_exercise_1_22();
#elif RE123
  return rewrite_exercise_1_23();
#elif RE125
  return rewrite_exercise_1_25();
#else
  std::cerr << "Compile options:\n\t"
               "-DRE120 for rewrite of Exercise 1.20\n\t"
               "-DRE121 for rewrite of Exercise 1.21\n\t"
               "-DRE122 for rewrite of Exercise 1.22\n\t"
               "-DRE123 for rewrite of Exercise 1.23\n\t"
               "-DRE125 for rewrite of Exercise 1.25"
            << std::endl;
  return 0;
#endif
}
