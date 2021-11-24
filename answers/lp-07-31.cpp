// 18/02/10 = Sat

// Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.

#include <iostream>

using std::cout;
using std::endl;

class X;
class Y;

class X
{
	Y * y;
};

class Y
{
	X x;
};

int main()
{
	X x;
	Y y;
	cout << sizeof x << endl;	// 8
	cout << sizeof y << endl;	// 8
	return 0;
}