// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.21: Write a function that takes an int and a pointer to an int and returns the larger of the int value or the value to which the pointer points. What type should you use for the pointer?

// Answer: At least const int *. const int * const is also possible.

#include <iostream>

using std::cout;
using std::endl;

int larger_of(int a, const int * const p)
{
	return a >= *p ? a : *p;
}

int main()
{
	int a = 42, b = 24;
	cout << "Larger of " << a << " and " << b << ": " << larger_of(a, &b) << endl;
	cout << "Larger of " << b << " and " << a << ": " << larger_of(b, &a) << endl;
	return 0;
}
