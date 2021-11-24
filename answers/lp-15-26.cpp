// 18/03/18 = Sun

// Exercise 15.26: Define the Quote and Bulk_quote copy-control members to do the same job as the synthesized versions. Give them and the other constructors print statements that identify which function is running. Write programs using these classes and predict what objects will be created and destroyed. Compare your predictions with the output and continue experimenting until your predictions are reliably correct.

// To compile:
// g++ lp-15-26.cpp -D DEBUG

#include "include\Quote.h"
#include "source\Quote.cpp"
#include <iostream>

using namespace std;

void line()
{
#ifdef DEBUG_COPY_CONTROL
	cout << string(50, '-') << endl;
#endif
}

int main()
{
	{
		Quote q0;										line();
		Quote q1(q0);									line();
		Quote q2(std::move(q0));						line();
		Quote q("978-7-121-20038-0", 100);				line();
		q0 = q;											line();
		q = std::move(q0);								line();
	}													line();
	Bulk_quote b0;										line();
	Bulk_quote b1(b0);									line();
	Bulk_quote b2(std::move(b0));						line();
	Bulk_quote bq("978-7-121-20038-0", 100, 5, 0.1);	line();
	b0 = bq;											line();
	bq = std::move(b0);									line();
	return 0;
}