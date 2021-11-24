// 18/03/21 = Wed

// Exercise 16.7: Write a constexpr template that returns the size of a given array.

#include <cstddef>
#include <iostream>
#include <iterator>		// for std::size
#include <string>

using namespace std;

template<typename T, size_t N>
size_t size(T (&)[N])
{
	return N;
}

int main()
{
	int a[] = {1, 2, 3};
	string b[] = {"a", "e", "i", "o", "u"};
	cout << ::size(a) << endl;		// 3
	cout << ::size(b) << endl;		// 5
	// To compile: g++ lp-16-07.cpp -std=c++17
	// std::size(), since C++17, defined in <iterator>
	// cout << std::size(a) << endl;	// 3
	// cout << std::size(b) << endl;	// 5
	return 0;
}