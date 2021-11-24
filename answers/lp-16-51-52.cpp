// 18/03/28 = Wed

// Exercise 16.51: Determine what sizeof...(Args) and sizeof...(rest) return for each call to foo in this section.

// template<typename T, typename ... Args>
// void foo(const T &t, const Args & ... rest);
// int i = 0; double d = 3.14; string s = "how now brown cow";
// foo(i, s, 42, d);
// foo(s, 42, "hi");
// foo(d, s);
// foo("hi");

// Answer:

// foo(i, s, 42, d);	3
// foo(s, 42, "hi");	2
// foo(d, s);			1
// foo("hi");			0

// Exercise 16.52: Write a program to check your answer to the previous question.

#include <iostream>
#include <string>

using namespace std;

template<typename T, typename ... A>
void foo(const T &, const A & ...)
{
	// sizeof... is an operator
	clog << sizeof... (A) << endl;
}

int i = 0;
double d = 3.14;
string s = "how now brown cow";

int main()
{
	foo(i, s, 42, d);	// 3
	foo(s, 42, "hi");	// 2
	foo(d, s);			// 1
	foo("hi");			// 0
	return 0;
}
