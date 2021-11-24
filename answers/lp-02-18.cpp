// 18/01/31 = Wed

// Exercise 2.18: Write code to change the value of a pointer. Write code to change the value to which the pointer points.

#include <iostream>

int main()
{
	int a = 3, *p = &a, b = 4, *q = &b;
	std::cout << *p << std::endl;		// 3
	p = q;
	std::cout << *p << std::endl;		// 4
	*p = 5;
	std::cout << *p << std::endl;		// 5
	return 0;
}