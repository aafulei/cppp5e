// 18/01/24 = Wed

// Exercise 10.15: Write a lambda that captures an int from its enclosing function and takes an int parameter. The lambda should return the sum of the captured int and the int parameter.

#include <iostream>

using std::cout;
using std::endl;

void foo(int a)
{
	auto f = [a](int b) -> int { return a + b; };
	cout << f(42) << endl;
}

int main()
{
	foo(24);
	return 0;
}