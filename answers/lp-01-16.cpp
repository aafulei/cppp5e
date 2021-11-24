// 18/01/29 = Mon

// Exercise 1.16: Write your own version of a program that prints the sum of a set of integers read from cin.

// To run, enter, for example, "a <data\digits" in command prompt.

#include <iostream>

int main()
{
	int sum = 0;
	for (int num; std::cin >> num; sum += num)
		;
	std::cout << ("Sum is: ") << sum << std::endl;
	return 0;
}