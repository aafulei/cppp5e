// 18/02/07 = Wed

// Exercise 6.36: Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string (& foo(string (&)[10]))[10];

// pass and return a reference to an array of ten strings
string (&foo(string (& a)[10]))[10]
{
	return a;
}

// To assign to the array and print out:
// X
// XX
// XXX
// XXXX
// XXXXX
// XXXXXX
// XXXXXXX
// XXXXXXXX
// XXXXXXXXX
// XXXXXXXXXX

int main()
{
	string a[10] {};
	int i = 0;
	for (auto &s : foo(a))
		s = string(++i, 'X');
	for (auto s : a)
		cout << s << endl;
	return 0;
}