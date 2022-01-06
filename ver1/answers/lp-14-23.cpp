// 18/03/13 = Tue
 
// Exercise 14.23: Define an initializer_list assignment operator for your version of the StrVec class.

// To turn on debug info to see whether allocation takes place:
// g++ lp-14-23.cpp -D DEBUG_ALLOC_OR_NOT

// To turn it off:
// compile as usual

#include "include\StrVec.h"
#include "source\StrVec.cpp"
#include <iostream>

using namespace std;

int main()
{
	StrVec sv = {"a", "an", "the"};
	cout << sv << endl;
	sv = {"am", "is", "are"};
	cout << sv << endl;
	sv = {"a", "e", "i", "o", "u"};
	cout << sv << endl;
	return 0;
}