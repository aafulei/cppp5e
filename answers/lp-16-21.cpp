// 18/03/25 = Sun

// Exercise 16.21: Write your own version of DebugDelete.

// A function object class that calls delete on a given pointer.
// Given a pointer p, DebugDelete(p) is equivalent to delete p.

// To compile: g++ lp-16-21.cpp -D DEBUG_DELETE

#include "include\DebugDelete.h"

int main()
{
	int * p = new int(42);
	DebugDelete()(p);
	return 0;
}
