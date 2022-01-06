// 18/01/28 = Sun

// print a matrix represented by a 2-dimensional array

#ifndef LP_03_MPRINT_HPP
#define LP_03_MPRINT_HPP

#include <iostream>

template<typename T, size_t M, size_t N>
void mprint(T const (&m)[M][N])
{
	for (auto &row : m) {
		for (auto elem : row)
			std::cout << elem <<  " ";
		std::cout << std::endl;
	}
}

#endif