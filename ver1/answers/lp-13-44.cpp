// 18/03/06 = Tue

// Exercise 13.44: Write a class named String that is a simplified version of the library string class. Your class should have at least a default constructor and a constructor that takes a pointer to a C-style string. Use an allocator to allocate memory that your String class uses.

// Modified from StrVec.cpp for lp-13-39-40.cpp

// To turn on debug information against self-assignment: g++ lp-13-49.cpp -D DEBUG_SELF_ASSIGN
// To turn it off: compile as usual

#include "include\String.h"
#include "source\String.cpp"
#include <iostream>

using namespace std;

int main()
{
	String s("Hello, World!");
	String t = s = s;	// check against self-assignment
	String u;
	u = u = t = t;
	cout  << s << endl;
	cout  << t << endl;
	cout  << u << endl;
	return 0;
}