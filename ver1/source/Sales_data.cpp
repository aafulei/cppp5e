// 18/03/12 = Mon: overloaded operators
// 18/03/13 = Tue: additional assignment operator
// 18/03/28 = Wed: operator==, operator!=

// Source code for Sales_data class

#include "..\include\Sales_data.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

bool operator==(const Sales_data & sd1, const Sales_data & sd2)
{
	return sd1.book_number == sd2.book_number &&
		   sd1.quantity == sd2.quantity &&
		   sd1.revenue == sd2.revenue;
}

bool operator!=(const Sales_data & sd1, const Sales_data & sd2)
{
	return !(sd1 == sd2);
}

Sales_data & Sales_data::operator+=(const Sales_data & sd)
{
	if (book_number != sd.book_number)
		throw invalid_argument("ISBNs differ!");
	quantity += sd.quantity;
	revenue += sd.revenue;
	return *this;
}

// for Exercise 14.13
Sales_data & Sales_data::operator-=(const Sales_data & sd)
{
	if (book_number != sd.book_number)
		throw invalid_argument("ISBNs differ!");
	if (quantity < sd.quantity)
		throw invalid_argument("Negative quantity!");
	quantity -= sd.quantity;
	revenue -= sd.revenue;
	return *this;
}

// for Exercise 14.22
Sales_data & Sales_data::operator=(const string & s)
{
	book_number = s;
	return *this;
}

Sales_data operator+(const Sales_data & sd1, const Sales_data & sd2)
{
	Sales_data sum(sd1);
	return sum += sd2;
}

// for Exercise 14.13
Sales_data operator-(const Sales_data & sd1, const Sales_data & sd2)
{
	Sales_data dif(sd1);
	return dif -= sd2;
}

istream & operator>>(istream & is, Sales_data & sd)
{
	double price;
	is >> sd.book_number >> sd.quantity >> price;
	if (is)
		sd.revenue = sd.quantity * price;
	else
		sd = Sales_data();
	return is;
}

ostream & operator<<(ostream & os, const Sales_data & sd)
{
	return os << sd.isbn()  << " " << sd.quantity << " " 
			  << sd.revenue << " " << sd.avg_price();
}
