// 21/12/26 = Sun
// 18/02/06 = Tue

// Exercise 6.12: Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references instead of pointers to swap the value of two ints. Which version do you think would be easier to use and why?

// Exercise 6.10: Using pointers, write a function to swap the values of two ints. Test the function by calling it and printing the swapped values.

// Answer: Using a reference is easier, becasue
// 1.	it is less error-prone;
// 2.	it avoids copying, which may be expensive.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// XOR swap
void swap(int & a, int & b)
{
	a ^= b, b ^= a, a ^= b;
}

int main()
{
	int a, b;
	cout << "Enter two integers: ";
	cin >> a >> b;
	cout << "a = " << a << "," << " b = " << b << endl;
	swap(a, b);
	cout << "a = " << a << "," << " b = " << b << endl;
	return 0;
}
