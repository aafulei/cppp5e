// 18/01/28 = Sun

// print a matrix represented by a 2-dimensional array

#include <iostream>
#include <string>
#include "lp-03-mprint.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
	int mi[2][2] = {{1, 2}, {3, 4}};
	double md[2][2] = {{3.14159}, {0, 2.71828}};
	string ms[5][5] = { {"H"},
						{"", "E"},
						{"","","L"},
						{"","","","L"},
						{"","","","","O"}};
	mprint(mi); cout << endl;
	mprint(md);	cout << endl;
	mprint(ms);	cout << endl;
	return 0;
}