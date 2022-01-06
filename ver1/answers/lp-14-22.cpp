// 18/03/13 = Tue
 
// Exercise 14.22: Define a version of the assignment operator that can assign a string representing an ISBN to a Sales_data.

#include "include\Sales_data.h"
#include "source\Sales_data.cpp"
#include <iostream>

using namespace std;

int main()
{
	Sales_data data("978-7-121-20038-0", 1, 100);
	cout << data << endl;
	data = "XXX-X-XXX-XXXXX-X";
	cout << data << endl;
	return 0;
}