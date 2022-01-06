// 18/03/12 = Mon

// Exercise 14.9: Define an input operator for your Sales_data class.

// To run, enter "a <data\records" in commmand prompt.

#include "include\Sales_data.h"
#include "source\Sales_data.cpp"

using namespace std;

int main()
{
	for (Sales_data data; cin >> data; cout << data << endl)
		;
	return 0;
}