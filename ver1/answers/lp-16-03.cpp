// 18/03/21 = Wed

// Exercise 16.3: Call your compare function on two Sales_data objects to see how your compiler handles errors during instantiation.

// Note: This program won't compile.

// Error: no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data')

#include "include\compare.h"
#include "include\Sales_data.h"
#include <iostream>

int main()
{
	compare(Sales_data(), Sales_data());
	return 0;
}
