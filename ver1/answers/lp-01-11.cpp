// 18/01/26 = Fri

// Exercise 1.11: Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

// Note: Print integers in [a, b], where a is the smaller of the two integers.

#include <iostream>

int main()
{
	int a, b;
	std::cout << "Enter two integers: ";
	std::cin >> a >> b;
	if (a > b) {
		int t = a;
		a = b;
		b = t;
		// alternatively: 
		// a = a + b, b = a - b, a = a - b;
	}
	while (a != b) {
		std::cout << a << " ";
		++a;
		// alternatively:
		// std::cout << a++ << " ";
	}
	std::cout << b << std::endl;
	return 0;
}