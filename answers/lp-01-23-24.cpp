// 18/01/15 = Mon

// Exercise 1.23: Write a program that reads several transactions and counts how many transactions occur for each ISBN.

// Exercise 1.24: Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

// To run, enter "a <data\records" in command prompt.

// Important: Assume items with the same ISBN are grouped together.

#include <cstdlib>
#include <iostream>
#include "include\Sales_item.h"

int main()
{
	Sales_item item;
	if (std::cin >> item) {
		Sales_item sum = item;
		int count = 1;
		while (std::cin >> item) {
			if (item.isbn() == sum.isbn()) {
				count += 1;
			}
			else {
				std::cout << sum.isbn() << " # " << count << std::endl;
				sum = item;
				count = 1;
			}
		}
		std::cout << sum.isbn() << " # " <<  count << std::endl;
	}
	else {
		std::cerr << "No data ?!" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
