// 18/02/23 = Fri

// Exercise 10.32: Rewrite the bookstore problem from § 1.6 (p. 24) using a vector to hold the transactions and various algorithms to do the processing. Use sort with your compareIsbn function from § 10.3.1 (p. 387) to arrange the transactions in order, and then use find and accumulate to do the sum.

// See lp-01-25.cpp for the original problem

// To run, enter "a <data\records" or "a <data\corders" in command prompt.
// In "records", items with the same ISBN are grouped together.
// In "corders", they are not.
// In fact, "corders" is a shuffle of the word "records".

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <functional>
#include <algorithm>
// Important: the compareIsbn() defined in Sales_item.h compares only the equality of two items' ISBNs, which is not a strict weak ordering and cannot be supplied to sort() as a binary predicate.
#include "include\Sales_item.h"

using namespace std;
using namespace std::placeholders;

int main() 
{
	istream_iterator<Sales_item> isit(cin), isend;
	ostream_iterator<Sales_item> osit(cout, "\n");
	vector<Sales_item> summary;
	// read transactions
	vector<Sales_item> records(isit, isend);
	// print transactions
	cout << "Transactions" << endl;
	copy(records.cbegin(), records.cend(), osit);
	// sort transactions
	sort(records.begin(), records.end(),
		[](const Sales_item & item1, const Sales_item & item2)
		{	
			return item1.isbn() < item2.isbn();
		});
	// print sorted transactions
	cout << "Sorted Transactions" << endl;
	auto rb = records.cbegin(), re = records.cend();
	copy(rb, re, osit);
	for (auto itb = rb; itb != re; ) {
		// find first item in range whose ISBN (not entire value) differs
		auto ite = find_if(itb, re,
							[itb](const Sales_item & item)
							{
								return item.isbn() != itb->isbn();
							});
		// alternatively:
		// auto ite = find_if_not(itb, re, bind(compareIsbn, *itb, _1));
		// Must write Sales_item(itb->isbn()) for initial value.
		// Cannot write Sales_item(). Why?
		summary.push_back(accumulate(itb, ite, Sales_item(itb->isbn())));
		itb = ite;
	}
	// print summary
	cout << "Summary" << endl;
	copy(summary.cbegin(), summary.cend(), osit);
	return 0;
}