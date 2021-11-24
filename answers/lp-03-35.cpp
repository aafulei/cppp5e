// 18/01/28 = Sun

// Exercise 3.35: Using pointers, write a program to set the elements in an array to zero.

#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;
using std::size_t;

int main()
{
	constexpr size_t N = 10;
	int a[N];
	// (a + N) is defined, but cannot be dereferenced
	for (int * p = a; p != a + N; ++p) 
		*p = 0;
	for (auto e : a)
		cout << e << " ";
	cout << endl;
	return 0;
}