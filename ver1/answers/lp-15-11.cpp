// 18/03/16 = Fri

// Exercise 15.11: Add a virtual debug function to your Quote class hierarchy that displays the data members of the respective classes.

#include "include\Quote.h"
#include "source\Quote.cpp"
#include <iostream>

using namespace std;

int main()
{
	Quote q("978-7-121-20038-0", 100), & r = q;
	Bulk_quote bq("978-7-121-20038-0", 100, 5, 0.1), & rb = bq;
	Limited_quote lq("978-7-121-20038-0", 100, 2, 0.25), & rl = lq;
	r.debug();
	rb.debug();
	rl.debug();
	return 0;
}