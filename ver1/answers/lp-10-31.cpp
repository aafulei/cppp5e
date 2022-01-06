// 18/02/23 = Fri

// Exercise 10.31: Update the program from the previous exercise so that it prints only the unique elements. Your program should use unqiue_copy (§ 10.4.1, p. 403).

// Exercise 10.30: Use stream iterators, sort, and copy to read a sequence of integers from the standard input, sort them, and then write them back to the standard output.

// Modified from lp-10-30.cpp

// To run, enter, for example, "a data\digits" in command prompt.

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	istream_iterator<int> isit(cin), isend;
	ostream_iterator<int> osit(cout, " ");
	vector<int> v(isit, isend);
	copy(v.cbegin(), v.cend(), osit);
	cout << endl;
	sort(v.begin(), v.end());
	using cit = vector<int>::const_iterator;
	auto uend = static_cast<cit>(unique(v.begin(), v.end()));
	// cannot mix const_iterator and iterator in copy()
	copy(v.cbegin(), uend, osit);
	return 0;
}
