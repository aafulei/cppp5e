// 18/01/24 = Wed
// 18/02/21 = Wed: lambda name omitted

// Exercise 10.14: Write a lambda that takes two ints and returns their sum.

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	// We don't even need to use "auto f = " to give the lambda a name.
	cout << [](int a, int b) -> int { return a + b; }(24, 42) << endl;
	return 0;
}