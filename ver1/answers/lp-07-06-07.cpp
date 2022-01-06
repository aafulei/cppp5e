// 18/02/09 = Fri
// 18/02/12 = Mon: print average price

// Exercise 7.6: Define your own versions of the add, read, and print functions.

// Exercise 7.7: Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new functions.

// Exercise 7.2: Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).

// Exercise 7.3: Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members.

// Modified from lp-07-02-03.cpp

// To run, enter "a <data\records" in command prompt.

#include <iostream>
#include <stdexcept>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::istream;
using std::ostream;
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

Sales_data add(const Sales_data & data1, const Sales_data & data2)
{
	Sales_data data = data1;
	data.combine(data2);
	return data;
}

istream & read(istream & is, Sales_data & data)
{
	double price;
	is >> data.book_number >> data.quantity >> price;
	// Cannot write:
	// if (!is) // equivalent to: if (is.fail())
	// 	throw runtime_error("Reading fails!");
	// Not to mention:
	// if (!is.good())
	// 	throw runtime_error("Reading fails!");
	// Why?
	data.revenue = price * data.quantity;
	return is;
}

ostream & print(ostream & os, const Sales_data & data)
{
	return os << data.isbn() << " "
			  << data.quantity << " "
			  << data.revenue << " "
		 	  << data.revenue / data.quantity;	// endl deleted
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
	if (read(cin, total)) {					// modified from lp-07-02-03.cpp
		Sales_data trans;
		while (read(cin, trans)) {			// modified from lp-07-02-03.cpp
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;	// modified from lp-07-02-03.cpp
				assign(total, trans);
			}
		}
		print(cout, total)  << endl;		// modified from lp-07-02-03.cpp
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}