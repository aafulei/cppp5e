// 18/02/23 = Fri

// Exercise 10.36: Use find to find the last element in a list of ints with value 0.

// To run, enter, for example, "a <data\digits" or "a <data\empty" in command prompt.

#include <algorithm>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	istream_iterator<int> isit(cin), isend;
	ostream_iterator<int> osit(cout, " ");
	// An easy way is to construct a vector from the list.
	// Here, we directly work on a list on purpose.
	list<int> l(isit, isend);
	copy(l.cbegin(), l.cend(), osit);
	cout << endl;
	auto it = find(l.crbegin(), l.crend(), 0);
	if (it == l.crend())
		cout << "0 is not found in the list." << endl;
	else
		cout << "The last 0 is found at position "
			 // Cannot use (l.crbegin() - it). Why?
			 << (l.size() - 1) - distance(l.crbegin(), it)
			 << "." << endl;
	return 0;
}