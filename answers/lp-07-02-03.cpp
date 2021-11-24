// 18/02/09 = Fri
// 18/02/12 = Mon: print average price

// Exercise 7.2: Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).

// Exercise 7.3: Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members.

// Modified from lp-07-01.cpp

// To run, enter "a <data\records" in command prompt.

#include <iostream>
#include <stdexcept>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::string;

struct Sales_data
{
	string book_number;
	unsigned quantity;
	double revenue;

	Sales_data & combine (const Sales_data &);
	string isbn() const { return book_number; }
};

Sales_data & Sales_data::combine(const Sales_data & data)
{
	if (data.book_number != book_number)
		throw invalid_argument("ISBNs differ!");
	quantity += data.quantity;
	revenue += data.revenue;
	return *this;
}

bool read(Sales_data & data)
{
	double price;
	cin >> data.book_number >> data.quantity >> price;
	data.revenue = price * data.quantity;
	return !cin.fail();
}

void print(const Sales_data & data)
{
	cout << data.book_number << " "
		 << data.quantity << " "
		 << data.revenue << " "
		 << data.revenue / data.quantity << endl;
}

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
			if (total.isbn() == trans.isbn())	// modified from lp-07-01.cpp
				total.combine(trans);			// modified from lp-07-01.cpp
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
