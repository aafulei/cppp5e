// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.9: Write your own versions of the fact.cc and factMain.cc files. These files should include your Chapter6.h from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

// This correspond to factMain.cc

// To compile, use either one of the two ways:
// 1. 	g++ lp-06-09-fact.cpp lp-06-09-generate.cpp
// 2. 	g++ lp-06-09-fact.cpp -c
// 		g++ lp-06-09-generate.cpp -c
// 		g++ lp-06-09-generate.o lp-06-09-fact.o

#include <iostream>
#include <stdexcept>
#include "include\Chapter6.h"

using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;

void generate()
{
	for (unsigned short n; cout << "Enter an integer n: ", cin >> n; ) {
		// Note: Curly braces cannot be omitted following try and catch.
		try {
			if (n > 20)
				throw invalid_argument("Invalid argument: n must be in [0, 20].");
			else
				cout << n << "! = " << fact(n) << endl;
		}
		catch (invalid_argument err) {
			cout << err.what() << endl;
		}
	}
}

int main()
{
	generate();
	return 0;
}
