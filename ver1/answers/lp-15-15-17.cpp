// 18/03/16 = Fri

// Exercise 15.15: Define your own versions of Disc_quote and Bulk_quote.

// Exercise 15.16: Rewrite the class representing a limited discount strategy, which you wrote for the exercises in § 15.2.2 (p. 601), to inherit from Disc_quote.

// Exercise 15.17: Try to define an object of type Disc_quote and see what errors you get from the compiler.

#include "include\Quote.h"
#include "source\Quote.cpp"
#include <iostream>

using namespace std;

int main()
{
	Quote q("978-7-121-20038-0", 100), & r = q;
	Bulk_quote bq("978-7-121-20038-0", 100, 5, 0.1), & rb = bq;
	Limited_quote lq("978-7-121-20038-0", 100, 2, 0.25), & rl = lq;
	print_total(r, 1);
	print_total(rb, 5);
	print_total(rl, 10);
	// Ex 15.17
	// Disc_quote dq("978-7-121-20038-0", 100, 5, 0.1);
	// error: cannot declare variable 'dq' to be of abstract type 'Disc_quote'
	// note: because the following virtual functions are pure within 'Disc_quote':
	return 0;
}