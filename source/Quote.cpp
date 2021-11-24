// 18/03/16 = Fri
// 18/03/18 = Sun: copy-control members

// Source code for Quote class hierarchy

// for lp-15-03.cpp, lp-15-05-07.cpp, lp-15-11.cpp, lp-15-15-17.cpp, lp-15-26.cpp, lp-15-27.cpp, lp-15-30.cpp

#include "..\include\Quote.h"
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

// Ex 15.26
Quote::Quote()
{
#ifdef DEBUG
	clog << "Quote::Quote()" << endl;
#endif
}

// Ex 15.26
Quote::Quote(const string & b, double p) : book_number(b), price(p)
{
#ifdef DEBUG
	clog << "Quote::Quote(const string &, double)" << endl;
#endif
}

// Ex 15.26
Quote::Quote(const Quote & q) : book_number(q.book_number), price(q.price)
{
#ifdef DEBUG
	clog << "Quote::Quote(const Quote &)" << endl;
#endif
}

// Ex 15.26
Quote::Quote(Quote && q) noexcept
	: book_number(std::move(q.book_number)), price(std::move(q.price))
{
#ifdef DEBUG
	clog << "Quote::Quote(Quote &&)" << endl;
#endif
}

// Ex 15.26
Quote & Quote::operator=(const Quote & q)
{
#ifdef DEBUG
	clog << "Quote::operator=(const Quote &)" << endl;
#endif
	book_number = q.book_number;
	price = q.price;
	return *this;
}

// Ex 15.26
Quote & Quote::operator=(Quote && q) noexcept
{
#ifdef DEBUG
	clog << "Quote::operator=(Quote &&)" << endl;
#endif
	if (this != &q) {
		book_number = std::move(q.book_number);
		price = std::move(q.price);
	}
	return *this;
}

// Ex 15.26
Quote::~Quote()
{
#ifdef DEBUG
	clog << "virtual Quote::~Quote()" << endl;
#endif
}

// Ex 15.3
// It's a bad design (as in the textbook) for a print function to return double. If you want to print, just print. Don't return a value.
void print_total(const Quote & q, size_t n, ostream & os = cout)
{
	cout << "ISBN\t\t" << q.isbn() << endl
		 << "Quantity\t" << n << endl
		 << "Total Price\t" << q.total_price(n) << endl;
}

void Quote::print_total(size_t n, ostream & os) const
{
	::print_total(*this, n, os);
}

// Ex 15.27
Disc_quote::Disc_quote(const string & b, double p, size_t q, double d)
	: Quote(b, p), quantity(q), discount(d)
{
#ifdef DEBUG
	clog << "Disc_quote::Disc_quote(const string &, double, size_t, double)" << endl;
#endif
}

// Ex 15.26
Bulk_quote::Bulk_quote()
{
#ifdef DEBUG
	clog << "Bulk_quote::Bulk_quote()" << endl;
#endif
}

// Ex 15.26
Bulk_quote::Bulk_quote(const string & b, double p, size_t q, double d)
	: Disc_quote(b, p, q, d)
{
	#ifdef DEBUG
		clog << "Bulk_quote::Bulk_quote(const string &, double, size_t, double)" << endl;
	#endif
}

// Ex 15.26
Bulk_quote::Bulk_quote(const Bulk_quote & bq) : Disc_quote(bq)
{
	#ifdef DEBUG
		clog << "Bulk_quote::Bulk_quote(const Bulk_quote &)" << endl;
	#endif
}

// Ex 15.26
Bulk_quote::Bulk_quote(Bulk_quote && bq) noexcept : Disc_quote(std::move(bq))
{
	#ifdef DEBUG
		clog << "Bulk_quote::Bulk_quote(Bulk_quote &&)" << endl;
	#endif
}

// Ex 15.26
Bulk_quote & Bulk_quote::operator=(const Bulk_quote & bq)
{
	#ifdef DEBUG
		clog << "Bulk_quote & Bulk_quote::operator=(const Bulk_quote &)" << endl;
	#endif
	Disc_quote::operator=(bq);				// bq is sliced down
	return *this;
}

// Ex 15.26
Bulk_quote & Bulk_quote::operator=(Bulk_quote && bq) noexcept
{
	#ifdef DEBUG
		clog << "Bulk_quote & Bulk_quote::operator=(Bulk_quote &&)" << endl;
	#endif
	if (this != &bq)
		Disc_quote::operator=(std::move(bq));// std::move(bq) is sliced down
	return *this;
}

// Ex 15.26
Bulk_quote::~Bulk_quote()
{
#ifdef DEBUG
	clog << "virtual Bulk_quote::~Bulk_quote() override" << endl;
#endif
}

// Ex 15.5
// refactored in Ex 15.15: min_quantity => quantity, in Disc_quote
double Bulk_quote::total_price(size_t n) const
{
	return price * n * (n >= quantity ? (1 - discount) : 1);
}

// Ex 15.7
// refactored in Ex 15.16: lim_quantity => quantity, in Disc_quote
double Limited_quote::total_price(size_t n) const
{
	if (n <= quantity)
		return price * n * (1 - discount);
	else
		return price * (quantity * (1 - discount) + (n - quantity));
}

// Ex 15.11
void Quote::debug() const
{
	clog << "ISBN\t\t" << isbn() << endl
		 << "Price\t\t" << price << endl;
}

void Disc_quote::debug() const
{
	clog << "ISBN\t\t" << isbn() << endl
		 << "Price\t\t" << price << endl
		 << "Quantity\t" << quantity << endl
		 << "Discount\t" << discount << endl;
}

// Ex 15.11
// refactored in Ex 15.15: => Disc_quote
// void Bulk_quote::debug() const
// {
// 	clog << "min_quantity = " << min_quantity << endl
// 		 << "discount = " << discount << endl;
// }

// Ex 15.11
// refactored in Ex 15.15: => Disc_quote
// void Limited_quote::debug() const
// {
// 	clog << "lim_quantity = " << lim_quantity << endl
// 		 << "discount = " << discount << endl;
// }