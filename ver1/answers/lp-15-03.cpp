// 18/03/16 = Fri

// Exercise 15.3: Define your own versions of the Quote class and the print_total function.

#include "include\Quote.h"
#include "source\Quote.cpp"

using namespace std;

int main()
{
	print_total(Quote("978-7-121-20038-0", 100), 1);
	return 0;
}