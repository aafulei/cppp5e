// 18/03/21 = Wed

// Exercise 16.2: Write and test your own versions of the compare functions.

#include "include\compare.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using svec = std::vector<string>;

int main()
{
	cout << compare(3, 21) << endl;									// -1
	cout << compare(string("Hello"), string("Hello")) << endl;		// 0
	cout << compare(svec{"Hello", "World"}, svec{"Hello"}) << endl;	// 1
	return 0;
}