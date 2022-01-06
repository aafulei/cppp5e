// 18/01/29 = Mon

// Exercise 1.13: Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

// Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to 100.

// Exercise 1.10: Use the decrement operator to write a while that prints the numbers from ten down to zero.

// Exercise 1.11: Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

#include <iostream>

int main()
{
	// redo Exercise 1.9
	int sum = 0;
	for (int i = 50; i <= 100; ++i)
		sum += i;
	// alternatively:
	// for (int i = 50; i <= 100; sum += i++)
	// 	;
	std::cout << sum << std::endl;
	sum = 0;

	// redo Exercise 1.10
	for (int i = 10; i >= 0; --i)
		std::cout << i << " ";
	std::cout << std::endl;

	// redo Exercise 1.11
	int a, b;
	std::cout << "Enter two integers: ";
	std::cin >> a >> b;
	if (a > b)
		a += b, b = a - b, a -= b;
	for (; a <= b; ++a)
		std::cout << a << " ";
	std::cout << std::endl;

	return 0;
}