// 18/01/28 = Sun

// Exercise 3.44: Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.

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
	using const_int_arr_4 = int const [4];
	for (const_int_arr_4 & row : ia) {
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
	using ptr_const_int_arr_4 = int const (*)[4];
	using ptr_const_int = int const (*);
	for (ptr_const_int_arr_4 p = cbegin(ia); p != cend(ia); ++p) {
		for (ptr_const_int q = cbegin(*p); q != cend(*p); ++q)
			cout << *q << " ";
		cout << endl;
	}
	return 0;
}