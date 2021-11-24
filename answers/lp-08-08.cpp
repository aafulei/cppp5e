// 18/01/16 = Tue
// 18/02/12 = Mon: minor changes for consistency

// Exercise 8.8: Revise the program from the previous exercise to append its output to its given file. Run the program on the same output file at least twice to ensure that the data are preserved.

// Exercise 8.7: Revise the bookstore program from the previous section to write its output to a file. Pass the name of that file as a second argument to main.

// Exercise 8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read its transactions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218).

// Exercise 7.1: Write a version of the transaction-processing program from § 1.6 (p. 24) using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).

// Modified from lp-08-07.cpp
// Merely:
// ofstream ofs(ofname, ofstream::app);

// To run, enter "a data\records output\summary" in command prompt twice.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ifstream;
using std::invalid_argument;
using std::istream;
using std::ofstream;
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

bool report(string ifname, string ofname)
{
	ifstream ifs(ifname);
	ofstream ofs(ofname, ofstream::app);	// modified
	if (ifs.fail() || ofs.fail()) {
		cerr << "Error: Cannot open file(s)!" << endl;
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
				Sales_data::print(ofs, total) << endl;
				total = trans;
			}
		}
		Sales_data::print(ofs, total) << endl;
	}
	else {
		has_data = false;
		cerr << "Error. No data?!" << endl;
	}
	ifs.close();
	ofs.close();
	return has_data;
}

int main(int argc, char ** argv)
{
	if (argc < 3) {
		cerr << "Error: Format is [command][input filename][output filename]!" << endl;
		return EXIT_FAILURE;
	}
	return report(argv[1], argv[2]) ? EXIT_SUCCESS : EXIT_FAILURE;
}