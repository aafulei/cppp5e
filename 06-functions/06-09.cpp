// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.9: Write your own versions of the fact.cc and factMain.cc files. These files should include your Chapter6.h from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

// This correspond to fact.cc

// To compile, use either one of the two ways:
// 1. 	g++ lp-06-09-fact.cpp lp-06-09-generate.cpp
// 2. 	g++ lp-06-09-fact.cpp -c
// 		g++ lp-06-09-generate.cpp -c
// 		g++ lp-06-09-generate.o lp-06-09-fact.o

#include "include\Chapter6.h"

unsigned long long fact(unsigned short n)
{
	return n == 0 ? 1ULL : n * fact(n-1);
}
