// 18/03/16 = Fri

// Exercise 15.5: Define your own version of the Bulk_quote class.

#include "include\Quote.h"
#include "source\Quote.cpp"
#include <iostream>

using namespace std;

int main()
{
	Quote q("978-7-121-20038-0", 100);
	Bulk_quote bq("978-7-121-20038-0", 100, 5, 0.1);
	Limited_quote lq("978-7-121-20038-0", 100, 2, 0.25);
	print_total(q, 1);	// total price: 100
	print_total(bq, 5);	// total price: 450 (10% discount for >= 5 copies)
	print_total(lq, 10);// total price: 950 (25% discount for first 2 copies)
	return 0;
}