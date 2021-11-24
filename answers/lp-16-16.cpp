// 18/03/24 = Sat
 
// Exercise 16.16: Rewrite the StrVec class (§ 13.5, p. 526) as a template named Vec.

// Modified from lp-14-16.cpp, lp-14-18.cpp, lp-14-26.cpp

#include "include\Vec.h"
#include <iostream>
#include <string>

using namespace std;
using StrVec = Vec<string>;

int main()
{
	// lp-14-16.cpp
	StrVec sv1 = {"a", "an", "the"};
	StrVec sv2 = {"a", "an", "the"};
	StrVec sv3 = {"a", "an"};
	StrVec sv4 = {"a", "and"};
	cout << (sv1 == sv2) << ends;	// 1
	cout << (sv2 == sv3) << ends;	// 0
	cout << (sv3 == sv4) << endl;	// 0

	// lp-14-18.cpp
	// 0011 0101
	cout << (sv1 < sv2)	 << (sv1 > sv2)
		 << (sv1 <= sv2) << (sv1 >= sv2) << " "
		 << (sv2 < sv3)	 << (sv2 > sv3)
		 << (sv2 <= sv3) << (sv2 >= sv3) << endl;

	// lp-14-26.cpp
	StrVec sv = {"a", "an", "the"};
	const StrVec csv = sv;
	cout << sv << endl;		// a an the
	cout << sv[0] << endl;	// a
	cout << csv[1] << endl;	// an
	cout << endl;

	return 0;
}