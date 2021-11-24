// 18/03/27 = Tue

// Exercise 16.47: Write your own version of the flip function and test it by calling functions that have lvalue and rvalue reference parameters.

#include "include\move.h"
#include <iostream>
#include <utility>

using namespace std;

template<typename F, typename S, typename T>
void flip(F f, S && s, T && t)
{
	f(std::forward<T>(t), std::forward<S>(s));
}

void pp(int i, int j)
{
	cout << i << " " << j << endl;
}

void ll(int & i, int & j)
{
	cout << i << " " << j << endl;
}

void lr(int & i, int && j)
{
	cout << i << " " << j << endl;
}

void rl(int && i, int & j)
{
	cout << i << " " << j << endl;
}

void rr(int && i, int && j)
{
	cout << i << " " << j << endl;
}

int main()
{
	int i = 33, j = 42;
	flip(pp, j, i);		// 33 42
	flip(ll, j, i);		// 33 42
	flip(lr, 42, i);	// 33 42
	flip(rl, j, 33);	// 33 42
	flip(rr, 42, 33);	// 33 42
	return 0;
}