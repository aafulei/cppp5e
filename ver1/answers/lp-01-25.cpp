// 18/01/15 = Mon

// Exercise 1.25: Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section.

// Important: Assume items with the same ISBN are grouped together.

// Exactly the same as the program in the textbook.

// To run, enter "a <data\records" in command prompt.

#include <iostream>
#include "include\Sales_item.h"

int main() 
{
	Sales_item total;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn())
				total += trans;
			else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}