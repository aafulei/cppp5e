// 18/03/18 = Sun

// Exercise 15.30: Write your own version of the Basket class and use it to compute prices for the same transactions as you used in the previous exercises.

#include "include\Basket.h"
#include "include\Quote.h"
#include "source\Basket.cpp"
#include "source\Quote.cpp"

int main()
{
	Basket b;
	for (auto i = 0; i != 10; ++i)
		b.add_item(Bulk_quote("978-7-121-20038-0", 100, 5, 0.1));
	for (auto i = 0; i != 10; ++i)
		b.add_item(Bulk_quote("978-7-121-12332-0", 60, 2, 0.05));
	b.print_total();
	return 0;
}