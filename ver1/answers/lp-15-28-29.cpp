// 18/03/18 = Sun

// Exercise 15.28: Define a vector to hold Quote objects but put Bulk_quote objects into that vector. Compute the total net_price of all the elements in the vector.

// Exercise 15.29: Repeat your program, but this time store shared_ptrs to objects of type Quote. Explain any discrepancy in the sum generated by the this version and the previous program. If there is no discrepancy, explain why there isn’t one.

// Answer: In Ex 15.28, Bulk_quote objects are sliced down when they are pushed back to the vector. The function called is the Quote version. To the contrary, in Ex 15.29, the virtual function is called on pointers to Quote. This invokes dynamic binding. The version called is the Bulk_quote version, which correctly yields the sum.

#include "include\Quote.h"
#include "source\Quote.cpp"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main()
{
	// Ex 15.28
	vector<Quote> vq;
	Bulk_quote bq1("978-7-121-20038-0", 100, 5, 0.1);
	Bulk_quote bq2("978-7-121-12332-0", 60, 2, 0.05);
	vq.push_back(bq1);
	vq.push_back(bq2);
	decltype(Bulk_quote().total_price(10)) sum {};
	// buy 10 items for each book:
	// 10 * (1-0.1) * 100 + 10 * (1-0.05) * 60 = 900 + 570 = 1470
	for (const auto & e : vq)
		sum += e.total_price(10);
	cout << sum << endl;	// 1,600; should be 1,470 for a Bulk_quote

	// Ex 15.29
	vector<shared_ptr<Quote>> vs;
	// Important: make_shared<Bulk_quote>, not make_shared<Quote>.
	vs.push_back(make_shared<Bulk_quote>(bq1));
	vs.push_back(make_shared<Bulk_quote>(bq2));
	sum = 0;
	for (const auto & e : vs)
		sum += e->total_price(10);
	cout << sum << endl;	// 1,470

	return 0;
}