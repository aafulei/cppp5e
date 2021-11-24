// 18/01/15 = Mon
// 18/02/12 = Mon: minor changes for consistency

// Exercise 8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read its transactions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218).

// Exercise 7.1: Write a version of the transaction-processing program from § 1.6 (p. 24) using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).

// To run, enter "a data\records" or "a data\empty" in command prompt.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::invalid_argument;
using std::istream;
using std::ostream;
using std::string;

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

bool report(string filename)
{
	ifstream ifs(filename);
	if (ifs.fail()) {
		cerr << "Error: Cannot open file!" << endl;
		return false;
	}
	Sales_data trans;
	bool has_data;
	if (Sales_data::read(ifs, trans)) {
		has_data = true;
		Sales_data total = trans;
		while (Sales_data::read(ifs, trans)) {
			if (trans.isbn() == total.isbn()) {
				total.combine(trans);
			}
			else {
				Sales_data::print(cout, total) << endl;
				total = trans;
			}
		}
		Sales_data::print(cout, total) << endl;
	}
	else {
		has_data = false;
		cerr << "Error: No data?!" << endl;
	}
	ifs.close();
	return has_data;
}

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return EXIT_FAILURE;
	}
	return report(argv[1]) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/* ---------- postscript ----------

> Discussion: Should we make read()/print() a friend function or a static member functions?

The only difference between a friend function and a static member function is that a friend function is not in the class scope while a static member function is.

The reason that Lippman wrote "IO Operators Must Be Nonmember Functions" is that we conform to the library conventions that put istream & and ostream & on the left-hand side, so that it is cin >> data and cout << data.

At this point, we have not overloaded << and >> operators. Just for read() and print() functions, it is perfectly legal, and even desirable, to make them (static) member functions.

----------------------------------- */