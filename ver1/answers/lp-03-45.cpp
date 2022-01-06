// 18/01/28 = Sun

// Exercise 3.45: Rewrite the programs again, this time using auto.

// C++14 support required for std::cbegin() and std::cend();

#include <iostream>
#include <iterator>

using std::cbegin;
using std::cend;
using std::cout;
using std::endl;

int main()
{
	int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
	// range for
	for (auto const& row : ia) {
		for (auto elem : row)
			cout << elem << " ";
		cout << endl;
	}
	// traditional for: subscripts
	for (auto i = 0; i < 3; ++i) {
		for (auto j = 0; j < 4; ++j)
			cout << ia[i][j] << " ";
		cout << endl;
	}
	// traditional for: pointers
	// std::cbegin() and std::cend() has been introduced since C++14
	// auto const p = cbegin(ia) is incorrect, which makes p a const pointer, not a pointer to const
	for (auto p = cbegin(ia); p != cend(ia); ++p) {
		for (auto q = cbegin(*p); q != cend(*p); ++q)
			cout << *q << " ";
		cout << endl;
	}
	return 0;
}