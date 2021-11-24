// 18/01/28 = Sun

// Exercise 3.40: Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use strcpy and strcat to copy the two arrays into the third.

#include <cstddef>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;
using std::size_t;
using std::strcat;
using std::strcpy;
using std::strlen;

int main()
{
	constexpr size_t N = 100;
	char const ca1[N] = "Hello, ";
	char const ca2[N] = "World!";
	char ca3[N+N];
	strcpy(ca3, ca1);
	strcat(ca3, ca2);
	cout << ca1 << endl;
	cout << ca2 << endl;
	cout << ca3 << endl;
	return 0;
}