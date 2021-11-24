// 18/02/02 = Fri
// 18/02/12 = Mon: print average price

// Exercise 2.40: Write your own version of the Sales_data class.

// The Sales_data class is designed to be more concrete than the Sales_item class.
// 1. Users can access all the data elements.
// 2. Users must implement all the operations for themselves.

// To run, enter "a <data\records" in command prompt.

#include <iostream>
#include <string>

struct Sales_data
{
	std::string book_number;
	unsigned quantity;
	double revenue;
};

void print(const Sales_data & data)
{
	std::cout << data.book_number << " "
			  << data.quantity << " "
			  << data.revenue << " "
			  << data.revenue / data.quantity << std::endl;
}

int main()
{
	Sales_data data;
	double price;
	std::cin >> data.book_number >> data.quantity >> price;
	data.revenue = price * data.quantity;
	print(data);
	return 0;
}