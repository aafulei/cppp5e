// 18/01/28 = Sun

// Exercise 3.43: Write three different versions of a program to print the elements of ia. One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, auto, or decltype to simplify the code.

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
	for (int const (& row)[4] : ia) {
		for (int elem : row)
			cout << elem << " ";
		cout << endl;
	}
	// traditional for: subscripts
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j)
			cout << ia[i][j] << " ";
		cout << endl;
	}
	// traditional for: pointers
	// std::cbegin() and std::cend() has been introduced since C++14
	for (int const (*p)[4] = cbegin(ia); p != cend(ia); ++p) {
		for (int const *q = cbegin(*p); q != cend(*p); ++q)
			cout << *q << " ";
		cout << endl;
	}
	return 0;
}