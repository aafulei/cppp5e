// 18/02/10 = Sat

// Exercise 7.41: Rewrite your own version of the Sales_data class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a Sales_data object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.

// Modified from lp-07-26.cpp

// To run, enter "a <data\records" in command prompt.

#include <iostream>
#include <stdexcept>
#include <string>

using std::cerr;
using std::cin;
using std::clog;
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

class Sales_data
{
	friend istream & read(istream &, Sales_data &);
	friend ostream & print(ostream &, const Sales_data &);

	string book_number;
	unsigned quantity = 0u;
	double revenue = 0.0;
public:
	Sales_data() : Sales_data("", 0, 0)						// delegated
	{	clog << "LOG: constructor() called" << endl; }				
	Sales_data(const string & b) : Sales_data(b, 0, 0)		// delegated
	{	clog << "LOG: constructor(const string &) called" << endl; }	
	Sales_data(const string & b, unsigned q, double p) : 
		book_number(b), quantity(q), revenue(q * p)
	{
		clog << "LOG: constructor(const string &, unsigned, double) called" << endl;
	}
	Sales_data(istream & is) : Sales_data()					// delegated
	{
		read(is, *this); 
		clog << "LOG: constructor(istream &) called" << endl;
	}
	Sales_data & combine (const Sales_data &);
	string isbn() const { return book_number; }
private:
	double avg_price() const { return revenue / quantity; }
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
		 	  << data.avg_price();
}

int main()
{
	cout << "Case 1" << endl;
	Sales_data empty;
	cout << "Case 2" << endl;
	Sales_data primer("978-7-121-20038-0");
	cout << "Case 3" << endl;
	Sales_data bundle("978-7-560-92699-5", 2, 55);
	cout << "Case 4" << endl;
	Sales_data record(cin);
	return 0;
}