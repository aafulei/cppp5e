// 18/02/02 = Fri
// 18/02/12 = Mon: print average price

// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your Sales_data class in the same file as your main function.

// Exercise 1.20: ... write a program that reads a set of book sales transactions, writing each transaction to the standard output.

// Exercise 1.21: Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

// Exercise 1.22: Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

// Exercise 1.23: Write a program that reads several transactions and counts how many transactions occur for each ISBN.

// Exercise 1.24: Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

// Exercise 1.25: Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section.

// We redo only Exercise 1.25 here.

// Modified from lp-01-25.cpp

// To run, enter "a <data\records" in command prompt.

#include <iostream>
#include <string>

struct Sales_data
{
	std::string book_number;
	unsigned quantity;
	double revenue;
};

bool read(Sales_data & data)
{
	double price;
	std::cin >> data.book_number >> data.quantity >> price;
	data.revenue = price * data.quantity;
	// Cannot write return std::cin.good(); Why?
	return !std::cin.fail();
}

void print(const Sales_data & data)
{
	std::cout << data.book_number << " "
			  << data.quantity << " "
			  << data.revenue << " "
			  << data.revenue / data.quantity << std::endl;
}

// combine data2 with data1
void combine(Sales_data & data1, const Sales_data & data2)
{
	if (data1.book_number == data2.book_number) {
		data1.quantity += data2.quantity;
		data1.revenue += data2.revenue;
	}
	else
		std::cerr << "Error: ISBNs differ!" << std::endl;
}

// assign data2 to data1
void assign(Sales_data & data1, const Sales_data & data2)
{
	data1.book_number = data2.book_number;
	data1.quantity = data2.quantity;
	data1.revenue = data2.revenue;
}

int main()
{
	Sales_data total;
	if (read(total)) {
		Sales_data trans;
		while (read(trans)) {
			if (total.book_number == trans.book_number)
				combine(total, trans);
			else {
				print(total);
				assign(total, trans);
			}
		}
		print(total);
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
