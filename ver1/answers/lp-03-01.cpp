// 18/01/26 = Fri
// 18/02/02 = Fri: Exercise 2.41 (1.25)
// 18/02/12 = Mon: print average price

// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appropriate using declarations.

#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
// alternatively (since -std=c++17):
// using std::cerr, std::cin, std::cout, std::endl;
using std::string;

struct Sales_data
{
	string book_number;
	unsigned quantity;
	double revenue;
};

bool read(Sales_data & data)
{
	double price;
	cin >> data.book_number >> data.quantity >> price;
	data.revenue = price * data.quantity;
	// Cannot write return cin.good(); Why?
	return !cin.fail();
}

void print(const Sales_data & data)
{
	cout << data.book_number << " "
		 << data.quantity << " "
		 << data.revenue << " "
		 << data.revenue / data.quantity << endl;
}


// combine data2 with data1
void combine(Sales_data & data1, const Sales_data & data2)
{
	if (data1.book_number == data2.book_number) {
		data1.quantity += data2.quantity;
		data1.revenue += data2.revenue;
	}
	else
		cerr << "Error: ISBNs differ!" << endl;
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
	// Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to 100.
	cout << "Exercise 1.9: Sum from 50 to 100 = ";
	int n = 50, s = 0;
	while (n <= 100)
		s += n++;	// postfix increment is much higher in precedence than compound assignment
	cout << s << endl;

	// Exercise 1.10: Use the decrement operator to write a while that prints the numbers from ten down to zero.
	cout << "Exercise 1.10: Count down from 10 to 0: ";
	n = 10;
	while (n >= 0)
		cout << n-- << " ";
	cout << endl;

	// Exercise 1.11: Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.
	cout << "Exercise 1.11: Print numbers in range. ";
	int a, b;
	cout << "Enter two integers: ";
	cin >> a >> b;
	if (a > b)
		a += b, b = a - b, a -= b;
	while (a != b)
		cout << a++ << " ";
	cout << b << endl;

	// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25).
	// Exercise 1.20, ..., Exercise 1.24: ...
	// Exercise 1.25: Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section.
	// We redo only Exercise 2.41 (1.25) here.
	cout << "Exercise 2.41 (1.25): Bookstore Program.\n"
		"Enter records like\n"
		"978-7-121-20038-0 4 100\n"
		"978-7-121-20038-0 1 105\n"
		"978-7-121-20038-0 5 99\n"
		"978-7-560-92699-5 1 60\n"
		"978-7-560-92699-5 1 50\n"
		"978-7-568-03329-9 1 35\n"
		"978-7-121-12332-0 2 65\n"
		"978-7-121-12332-0 2 55\n" << endl;
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
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}