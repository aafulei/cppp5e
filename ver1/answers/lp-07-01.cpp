// 18/02/09 = Fri
// 18/02/12 = Mon: print average price

// Exercise 7.1: Write a version of the transaction-processing program from § 1.6 (p. 24) using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).

// Exercise 2.40: Write your own version of the Sales_data class.

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25).

// Exercise 2.42: Write your own version of the Sales_data.h header and use it to rewrite the exercise from § 2.6.2 (p. 76).

// Almost the same as lp-02-42.cpp

// To run, enter "a <data\records" in command prompt.

#include <iostream>
#include <string>
#include "include\struct\Sales_data.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

bool read(Sales_data & data)
{
	double price;
	cin >> data.book_number >> data.quantity >> price;
	data.revenue = price * data.quantity;
	// Cannot write return cin.good(); Why?
	return !cin.fail();
}

void print(const Sales_data & data)
{
	cout << data.book_number << " "
		 << data.quantity << " "
		 << data.revenue << " "
		 << data.revenue / data.quantity << endl;
}

// combine data2 with data1
void combine(Sales_data & data1, const Sales_data & data2)
{
	if (data1.book_number == data2.book_number) {
		data1.quantity += data2.quantity;
		data1.revenue += data2.revenue;
	}
	else
		cerr << "Error: ISBNs differ!" << endl;
}

// assign data2 to data1
void assign(Sales_data & data1, const Sales_data & data2)
{
	data1.book_number = data2.book_number;
	data1.quantity = data2.quantity;
	data1.revenue = data2.revenue;
}

int main()
{
	Sales_data total;
	if (read(total)) {
		Sales_data trans;
		while (read(trans)) {
			if (total.book_number == trans.book_number)
				combine(total, trans);
			else {
				print(total);
				assign(total, trans);
			}
		}
		print(total);
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
