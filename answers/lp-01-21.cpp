// 18/01/15 = Mon

// Exercise 1.21: Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

// To run, enter "a <data\records" in command prompt.

#include <cstdlib>
#include <iostream>
#include "include\Sales_item.h"

int main()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn() != item2.isbn()) {
		std::cerr << "Error: ISBNs differ!" << std::endl;
		return EXIT_FAILURE;
	}
	else
		std::cout << item1 + item2 << std::endl;
	return EXIT_SUCCESS;
}