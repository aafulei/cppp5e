// 22/02/06 = Sun
// 21/12/22 = Wed
// 18/01/26 = Fri

// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to
// 100.

// Exercise 1.10: In addition to the ++ operator that adds 1 to its operand,
// there is a decrement operator (--) that subtracts 1. Use the decrement
// operator to write a while that prints the numbers from ten down to zero.

// Exercise 1.11: Write a program that prompts the user for two integers. Print
// each number in the range specified by those two integers.

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

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int rewriteExercise_1_9() {
  int sum = 0, val = 50;
  while (val <= 100) {
    sum += val;
    ++val;
  }
  cout << sum << endl;
  return 0;
}

int rewriteExercise_1_10() {
  int n = 10;
  while (n >= 0) {
    cout << n << endl;
    --n;
  }
  return 0;
}

int rewriteExercise_1_11() {
  cout << "Enter two numbers:" << endl;
  int v1 = 0, v2 = 0;
  cin >> v1 >> v2;
  while (v1 <= v2) {
    cout << v1 << endl;
    ++v1;
  }
  return 0;
}

// assume two books have the same ISBN
int rewriteExercise_1_21() {
  Sales_data data1, data2;
  double price = 0;
  cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;
  cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;
  if (data1.bookNo == data2.bookNo) {
    unsigned totalCnt = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;
    cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
    if (totalCnt != 0) {
      cout << totalRevenue / totalCnt << endl;
    } else {
      cout << "(no sales)" << endl;
    }
    return 0;
  } else {
    cerr << "Data must refer to the same ISBN" << endl;
    return -1;
  }
}

// assume multiple books have the same ISBN
int rewriteExercise_1_22() {
  Sales_data data, sum;
  double price = 0;
  if (cin >> data.bookNo >> data.units_sold >> price) {
    data.revenue = data.units_sold * price;
    sum = data;
    while (cin >> data.bookNo >> data.units_sold >> price) {
      data.revenue = data.units_sold * price;
      sum.units_sold += data.units_sold;
      sum.revenue += sum.revenue;
    }
  }
  cout << sum.bookNo << " " << sum.units_sold << " " << sum.revenue << " "
       << sum.revenue / sum.units_sold << endl;
  return 0;
}

int rewriteExercise_1_23() {
  Sales_data currVal, val;
  double price = 0;
  if (cin >> currVal.bookNo >> currVal.units_sold >> price) {
    currVal.revenue = currVal.units_sold * price;
    int cnt = 1;
    while (cin >> val.bookNo >> val.units_sold >> price) {
      val.revenue = val.units_sold * price;
      if (val.bookNo == currVal.bookNo) {
        ++cnt;
      } else {
        cout << currVal.bookNo << " occurs " << cnt << " times" << endl;
        currVal = val;
        cnt = 1;
      }
    }
    cout << currVal.bookNo << " occurs " << cnt << " times" << endl;
  }
  return 0;
}

int rewriteExercise_1_25() {
  Sales_data total;
  double price = 0;
  if (cin >> total.bookNo >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    Sales_data trans;
    while (cin >> trans.bookNo >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;
      if (total.bookNo == trans.bookNo) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue
             << " " << total.revenue / total.units_sold << endl;
        total = trans;
      }
    }
    cout << total.bookNo << " " << total.units_sold << " " << total.revenue
         << " " << total.revenue / total.units_sold << endl;
  } else {
    cerr << "No data?!" << endl;
    return -1;
  }
  return 0;
}

int main() {
#ifdef RE109
  return rewriteExercise_1_9();
#elif RE110
  return rewriteExercise_1_10();
#elif RE111
  return rewriteExercise_1_11();
#elif RE120
  return rewriteExercise_1_20();
#elif RE121
  return rewriteExercise_1_21();
#elif RE122
  return rewriteExercise_1_22();
#elif RE123
  return rewriteExercise_1_23();
#elif RE125
  return rewriteExercise_1_25();
#else
  cerr << "Compile options:\n\t"
          "-DRE109 for rewrite of Exercise 1.9\n\t"
          "-DRE110 for rewrite of Exercise 1.10\n\t"
          "-DRE111 for rewrite of Exercise 1.11\n\t"
          "-DRE120 for rewrite of Exercise 1.20\n\t"
          "-DRE121 for rewrite of Exercise 1.21\n\t"
          "-DRE122 for rewrite of Exercise 1.22\n\t"
          "-DRE123 for rewrite of Exercise 1.23\n\t"
          "-DRE125 for rewrite of Exercise 1.25"
       << endl;
  return 0;
#endif
}
