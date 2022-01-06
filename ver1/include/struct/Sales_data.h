// 18/02/02 = Fri

// The Sales_data class is designed to be more concrete than the Sales_item class.
// 1. Users can access all the data elements.
// 2. Users must implement all the operations for themselves.

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data
{
	std::string book_number;
	unsigned quantity;
	double revenue;
};
#endif