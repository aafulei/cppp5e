// 18/03/13 = Tue

// Exercise 14.20: Define the addition and compound-assignment operators for your Sales_data class.

// Answer: Both +/- and +=/-= have been defined for Exercise 14.13.

// Exercise 14.13: Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think Sales_data ought to support? Define any you think the class should include.

// Almost the same as lp-14-13.cpp, using +=/-= instead of +/-.

#include "include\Sales_data.h"
#include "source\Sales_data.cpp"
#include <iostream>

using namespace std;

int main()
{
	Sales_data data1("978-7-121-20038-0", 2, 100);
	Sales_data data2("978-7-121-20038-0", 2, 110);
	Sales_data sum(data1);
	cout << "Sold\t: " << data1 << endl;
	cout << "Sold\t: " << data2 << endl;
	cout << "Total\t: " << (sum += data2) << endl;
	cout << "Return\t: " << data2 << endl;
	cout << "Total\t: " << (sum -= data2) << endl;
	return 0;
}
