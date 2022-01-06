// 18/03/21 = Wed

// Header for compare function template

// for lp-16-02.cpp, lp-16-03.cpp

#ifndef COMPARE_H
#define COMPARE_H

#include <functional>	// for std::less

// A specialization of std::less for any pointer type yields a strict total order, even if the built-in operator< does not.

template<typename T>
int compare(const T & a, const T & b)
{
	if (std::less<T>()(a, b))
		return -1;
	else if (std::less<T>()(b, a))
		return 1;
	else
		return 0;
}

#endif