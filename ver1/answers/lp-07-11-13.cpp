// 18/02/09 = Fri
// 18/02/12 = Mon: print average price

// Exercise 7.11: Add constructors to your Sales_data class and write a program to use each of the constructors.

// Exercise 7.12: Move the definition of the Sales_data constructor that takes an istream into the body of the Sales_data class.

// Exercise 7.13: Rewrite the program from page 255 to use the istream constructor.

// Modified from lp-07-06-07.cpp

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
Sales_data add(const Sales_data &, const Sales_data &);
istream & read(istream &, Sales_data &);
ostream & print(ostream &, const Sales_data &);

struct Sales_data
{
	string book_number;
	unsigned quantity = 0u;	// modified: add in-class initializer
	double revenue = 0.0;	// modified: add in-class initializer

	Sales_data() = default;	// modified: add synthesized default constructor
	Sales_data(const string & b) : book_number(b) {}	// modified
	Sales_data(const string & b, unsigned q, double p) :// modified 
		book_number(b), quantity(q), revenue(q * p) {}	// modified
	Sales_data(istream & is) { read(is, *this); }	// Exercise 7.12
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
	// Exercise 7.11
	cout << string(10, '-') <<"Exercise 7.11" << string(10, '-') << endl;
	Sales_data def;
	print(cout, def) << endl;
	Sales_data empty("EMPTY");
	print(cout, empty) << endl;
	Sales_data primer("978-7-121-20038-0", 4, 100);
	print(cout, primer) << endl;
	
	// Exercise 7.13
	cout << string(10, '-') <<"Exercise 7.13" << string(10, '-') << endl;
	Sales_data total(cin);			// modified: use constructor
	if (cin) {
		while (cin) {
			Sales_data trans(cin);	// modified: use constructor
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;		// modified: use synthesized assignment
			}
		}
		if (!total.isbn().empty())	// We need this line. Why?
			print(cout, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}