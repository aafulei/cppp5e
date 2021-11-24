// 18/01/26 = Fri

// Exercise 1.10: In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.

#include <iostream>

int main()
{
	int n = 10;
	while (n >= 0) {
		std::cout << n << " ";
		--n;
	}
	// alternatively:
	// while (n >= 0)
	// 	std::cout << n-- << " ";
	return 0;
}