// 18/03/28 = Wed

// Exercise 16.62: Define your own version of hash<Sales_data> and define an unordered_multiset of Sales_data objects. Put several transactions into the container and print its contents.

// To turn on debug info on hash: g++ lp-16-62.cpp -D DEBUG_HASH
// To turn it off: compile as usual

// To run, enter "a <data\records" or "a <data\corders" in command prompt.

#include "include\Sales_data.h"
#include "source\Sales_data.cpp"

#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_multiset<Sales_data> ums;
	for (Sales_data sd; cin >> sd; ums.insert(sd))
		;
	for (const auto & e : ums)
		cout << e << endl;
	return 0;
}
