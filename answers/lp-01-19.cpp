// 18/01/29 = Mon

// Exercise 1.19: Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

// Exercise 1.11: Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

// This has already been dealt with in Exercise 1.11. Here we try a new way.

#include <iostream>

void print(int a, int b)
{
	if (a > b)
		print(b, a);
	else {
		while (a != b)
			std::cout << a++ << " ";
		std::cout << b << std::endl;
	}
}

int main()
{
	int a, b;
	std::cout << "Enter two integers: ";
	std::cin >> a >> b;
	print(a, b);
	return 0;
}