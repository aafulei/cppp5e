// 18/03/12 = Mon

// Exercise 14.6: Define an output operator for your Sales_data class.

#include "include\Sales_data.h"
#include "source\Sales_data.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << Sales_data("978-7-121-20038-0", 4, 100) << endl;
	return 0;
}