// 18/03/18 = Sun

// Exercise 15.27: Redefine your Bulk_quote class to inherit its constructors.

// Note that default, copy, and move constructors cannot be inherited. Thus the only constructor for Bulk_quote to inherit is the one that takes 4 parameters. We have done this in lp-15-26.cpp, which is

// Bulk_quote::Bulk_quote(const string & b, double p, size_t q, double d) : Disc_quote(b, p, q, d)

// To compile:
// g++ lp-15-27.cpp -D DEBUG

#include "include\Quote.h"
#include "source\Quote.cpp"

int main()
{
	Bulk_quote bq("978-7-121-20038-0", 100, 5, 0.1);
	return 0;
}