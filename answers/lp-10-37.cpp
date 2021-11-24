// 18/02/23 = Fri

// Exercise 10.37: Given a vector that has ten elements, copy the elements from positions 3 through 7 in reverse order to a list.

// Suppose the vector is:
// number	: 2 0 1 8 0 1 2 3 1 1
// in range	:       ^ ^ ^ ^ ^
// position : 0 1 2 3 4 5 6 7 8 9
// Should copy:
// 3 2 1 0 8

// To run, enter, for example, "a <data\digits" in command prompt.

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	// prepare vector and list
	istream_iterator<int> isit(cin), isend;
	ostream_iterator<int> osit(cout, " ");
	vector<int> v;
	list<int> l;
	for (unsigned i = 0; i != 10 && isit != isend; ++i)
		v.push_back(*isit++);
	// print vector
	copy(v.cbegin(), v.cend(), osit);
	cout << endl;
	// use reverse_iterator
	copy(v.crbegin() + 2, v.crbegin() + 7, back_inserter(l));
	copy(l.cbegin(), l.cend(), osit);
	cout << endl;
	// alternative 1: use front_inserter
	l.clear();
	copy(v.cbegin() + 3, v.cbegin() + 8, front_inserter(l));
	copy(l.cbegin(), l.cend(), osit);
	cout << endl;
	// alternative 2: use reverse_copy
	l.clear();
	reverse_copy(v.cbegin() + 3, v.cbegin() + 8, back_inserter(l));
	copy(l.cbegin(), l.cend(), osit);
	return 0;
}
