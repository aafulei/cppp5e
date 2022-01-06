// 18/02/21 = Wed

// Exercise 10.17: Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a lambda in the call to sort instead of the compareIsbn function.

// Exercise 10.12: Write a function named compareIsbn that compares the isbn() members of two Sales_data objects. Use that function to sort a vector that holds Sales_data objects.

// Modified from lp-10-12.cpp

// To run, enter "a <data\records" in command prompt.

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

class Sales_data
{
	string book_number;
	unsigned quantity = 0u;
	double revenue = 0.0;
public:
	string isbn() const;
	Sales_data & combine(const Sales_data &);
	static istream & read(istream &, Sales_data &);
	static ostream & print(ostream &, const Sales_data &);
private:
	double avg_price() const;
};

inline string Sales_data::isbn() const
{
	return book_number;
}

Sales_data & Sales_data::combine(const Sales_data & data)
{
	if (book_number != data.book_number)
		throw invalid_argument("ISBNs differ!");
	quantity += data.quantity;
	revenue += data.revenue;
	return *this;
}

istream & Sales_data::read(istream & is, Sales_data & data)
{
	double price;
	is >> data.book_number >> data.quantity >> price;
	data.revenue = data.quantity * price;
	return is;
}

ostream & Sales_data::print(ostream & os, Sales_data const& data)
{
	return os << data.isbn()	<< " " << data.quantity << " "
			  << data.revenue	<< " " << data.avg_price();
}

inline double Sales_data::avg_price() const
{
	return revenue / quantity;
}

// delete compareIsbn()

void print(const vector<Sales_data> & v)
{
	cout << string(30, '-') << endl;
	for (const auto & e : v)
		Sales_data::print(cout, e) << endl;
}

void process(vector<Sales_data> & v)
{
	for (Sales_data data; Sales_data::read(cin, data); v.push_back(data))
		;
	print(v);
	sort(v.begin(), v.end(),
		[](const Sales_data & d1, const Sales_data & d2)	// lambda
		{	return d1.isbn() < d2.isbn(); });
	print(v);
}

int main()
{
	vector<Sales_data> records;
	process(records);
	return 0;
}