// 18/03/28 = Wed

// Exercise 16.58: Write the emplace_back function for your StrVec class and for the Vec class that you wrote for the exercises in § 16.1.2 (p. 668).

// Exercise 16.59: Assuming s is a string, explain svec.emplace_back(s).

// Answer: Construct a string from s and insert it at the back of the StrVec.

// To turn on debug info: g++ lp-16-58-59.cpp -D DEBUG
// To turn it off: compile as usual

#include "include\StrVec.h"
#include "source\StrVec.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	StrVec svec;
	string s = "Hello";
	const char * cs = "World";
	svec.emplace_back(s);								// Hello
	svec.emplace_back(s.cbegin(), s.cend());			// Hello
	svec.emplace_back(cs);								// World
	svec.emplace_back("World");							// World
	svec.emplace_back(s + ", World!");					// Hello, World!
	svec.emplace_back(svec[svec.size()-1].size(), '-');	// -------------
	for (const auto & s : svec)
		cout << s << endl;
	return 0;
}