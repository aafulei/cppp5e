// 18/03/13 = Tue

// Exercise 14.26: Define subscript operators for your StrVec, String, StrBlob, and StrBlobPtr classes.

// We refuse to define any subscript operator for StrBlobPtr. After all, what's the point to subscript a pointer? Though we could do so, since a StrBlobPtr holds the weak pointer to the whole string vector, it would be pointless to do so.

// To turn on debug info for const overloading:
// g++ lp-14-26.cpp -D DEBUG_CONST_OVERLOAD
// Note: String has operator[] defined inline in header and would not show it.

// To turn it off:
// compile as usual

#include "include\StrBlob.h"
#include "include\String.h"
#include "include\StrVec.h"
#include "source\StrBlob.cpp"
#include "source\String.cpp"
#include "source\StrVec.cpp"
#include <iostream>

using namespace std;

int main()
{
	StrVec sv = {"a", "an", "the"};
	const StrVec csv = sv;
	cout << sv << endl;
	cout << sv[0] << endl;
	cout << csv[1] << endl;
	cout << endl;

	String s = "Hello, World!";
	const String cs = s;
	cout << s << endl;
	cout << s[0] << endl;
	cout << cs[1] << endl;
	cout << endl;

	StrBlob sb = {"This", "That", "These", "Those"};
	const StrBlob csb = sb;
	cout << sb << endl;
	cout << sb[0] << endl;
	cout << csb[1] << endl;

	return 0;
}