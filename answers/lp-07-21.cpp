// 18/02/10 = Sat
// 18/02/12 = Mon: print average price

// Exercise 7.21: Update your Sales_data class to hide its implementation. The programs you’ve written to use Sales_data operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.

// Modified from lp-07-11-13.cpp

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

struct Sales_data;
Sales_data add(Sales_data &, Sales_data &);
istream & read(istream &, Sales_data &);
ostream & print(ostream &, const Sales_data &);

class Sales_data			// change from struct to class
{
	friend istream & read(istream &, Sales_data &);			// add friend
	friend ostream & print(ostream &, const Sales_data &);	// add friend

	string book_number;
	unsigned quantity = 0u;
	double revenue = 0.0;
public:						// add public access specifier
	Sales_data() = default;
	Sales_data(const string & b) : book_number(b) {}
	Sales_data(const string & b, unsigned q, double p) : 
		book_number(b), quantity(q), revenue(q * p) {}
	Sales_data(istream & is) { read(is, *this); }
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

Sales_data add(Sales_data & data1, Sales_data & data2)
{
	Sales_data data = data1;
	data.combine(data2);
	return data;
}

istream & read(istream & is, Sales_data & data)
{
	double price;
	is >> data.book_number >> data.quantity >> price;
	data.revenue = price * data.quantity;
	return is;
}

ostream & print(ostream & os, const Sales_data & data)
{
	return os << data.isbn() << " "
			  << data.quantity << " "
			  << data.revenue << " "
		 	  << data.revenue / data.quantity;
}

int main()
{
	// Exercise 7.13
	Sales_data total(cin);
	if (cin) {
		while (cin) {
			Sales_data trans(cin);
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		if (!total.isbn().empty())
			print(cout, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}