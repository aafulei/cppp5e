// 18/02/02 = Fri
// 18/02/12 = Mon: print average price

// Exercise 2.42: Write your own version of the Sales_data.h header and use it to rewrite the exercise from § 2.6.2 (p. 76).

// Modified from lp-02-41.cpp

// To run, enter "a <data\records" in command prompt.

#include <iostream>
#include <string>
#include "include\struct\Sales_data.h"

bool read(Sales_data & data)
{
	double price;
	std::cin >> data.book_number >> data.quantity >> price;
	data.revenue = price * data.quantity;
	// Cannot write return std::cin.good(); Why?
	return !std::cin.fail();
}

void print(const Sales_data & data)
{
	std::cout << data.book_number << " "
			  << data.quantity << " "
			  << data.revenue << " "
			  << data.revenue / data.quantity << std::endl;
}

// combine data2 with data1
void combine(Sales_data & data1, const Sales_data & data2)
{
	if (data1.book_number == data2.book_number) {
		data1.quantity += data2.quantity;
		data1.revenue += data2.revenue;
	}
	else
		std::cerr << "Error: ISBNs differ!" << std::endl;
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
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
