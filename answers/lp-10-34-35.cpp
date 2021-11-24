// 18/02/23 = Fri

// Exercise 10.34: Use reverse_iterators to print a vector in reverse order.

// Exercise 10.35: Now print the elements in reverse order using ordinary iterators.

// To run, enter, for example, "a <data\digits" or "a <data\empty" in command prompt.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	// Exercise 10.34: print with reverse iterators
	istream_iterator<int> isit(cin), isend;
	ostream_iterator<int> osit(cout, " ");
	vector<int> v(isit, isend);
	copy(v.cbegin(), v.cend(), osit);
	cout << endl;
	copy(v.crbegin(), v.crend(), osit);
	cout << endl;

	// Exercise 10.35: print with ordinary iterators
	// Must make sure v is non-empty. Why?
	if (!v.empty()) {
		auto it = v.cend() - 1;
		while (it != v.cbegin())
			cout << *it-- << " ";
		cout << *it << endl;
	}
	
	return 0;
}