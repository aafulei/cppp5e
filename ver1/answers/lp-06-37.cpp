// 18/02/07 = Wed

// Exercise 6.37: Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?

// Exercise 6.36: Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.

// Answer: I prefer "using new-type-S = type-T;" introduced in C++11. Modern and readable.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

using U = string [10];
using R = string (&)[10];
typedef string S[10];
typedef string (&T)[10];

// A function can be declared many times, so long as the declarations are consistent themselves. In what follows, we declare foo() several times using different forms, and rely on the compiler to check their consistency.

string (& foo(string (&)[10]))[10];
U & foo(U &);
R & foo(R);
S & foo(S &);
T foo(T);
auto foo(string (&)[10]) -> string (&)[10];

// The same as lp-06-36.cpp below

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