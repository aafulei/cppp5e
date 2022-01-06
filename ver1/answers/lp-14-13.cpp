// 18/03/12 = Mon

// Exercise 14.13: Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think Sales_data ought to support? Define any you think the class should include.

// Answer: operator- to reverse a previous addition. This could be useful. Consider a return of books and a refund.

#include "include\Sales_data.h"
#include "source\Sales_data.cpp"
#include <iostream>

using namespace std;

int main()
{
	Sales_data data1("978-7-121-20038-0", 2, 100);
	Sales_data data2("978-7-121-20038-0", 2, 110);
	Sales_data sum;
	cout << "Sold\t: " << data1 << endl;
	cout << "Sold\t: " << data2 << endl;
	cout << "Total\t: " << (sum = data1 + data2) << endl;
	cout << "Return\t: " << data2 << endl;
	cout << "Total\t: " << (sum = sum - data2) << endl;
	return 0;
}
