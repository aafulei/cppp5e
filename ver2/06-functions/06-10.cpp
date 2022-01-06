// 21/12/26 = Sun
// 18/02/06 = Tue

// Exercise 6.10: Using pointers, write a function to swap the values of two ints. Test the function by calling it and printing the swapped values.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// XOR swap
void swap(int * p, int * q)
{
	*p ^= *q, *q ^= *p, *p ^= *q;
}

int main()
{
	int a, b;
	cout << "Enter two integers: ";
	cin >> a >> b;
	cout << "a = " << a << "," << " b = " << b << endl;
	swap(&a, &b);
	cout << "a = " << a << "," << " b = " << b << endl;
	return 0;
}
