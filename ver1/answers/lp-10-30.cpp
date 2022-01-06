// 18/02/23 = Fri

// Exercise 10.30: Use stream iterators, sort, and copy to read a sequence of integers from the standard input, sort them, and then write them back to the standard output.

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
	copy(v.cbegin(), v.cend(), osit);
	return 0;
}
