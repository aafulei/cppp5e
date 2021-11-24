// 18/03/14 = Wed

// Exercise 14.45: Write conversion operators to convert a Sales_data to string and to double. What values do you think these operators should return?

// Answer:
// 1. to string: returns ISBN;
// 2. to double: returns revenue.

// Exercise 14.46: Explain whether defining these Sales_data conversion operators is a good idea and whether they should be explicit.

// Answer: No, because there is not a single, natural mapping from a Sales_data to either a string or a double. We must declare the conversion as explicit so as to avoid unwanted implicit conversion. A better approach would be to define ordinary member functions to extract the information in these forms.

#include "include\Sales_data.h"
#include "source\Sales_data.cpp"
#include <iostream>

using namespace std;

int main()
{
	for (Sales_data sd; cin >> sd;
		cout << static_cast<string>(sd) << " "
			 << static_cast<double>(sd) << endl)
		;
	return 0;
}