// 18/03/28 = Wed

// Exercise 16.60: Explain how make_shared (§ 12.1.1, p. 451) works.

// Answer: The template function make_shared<T>(A && ... a) dynamically allocates memory for an object of type T that is constructed from the variadic arguments forwarded by the function parameter pack a that has a template parameter pack A. It then constructs and returns a shared_ptr from the built-in pointer that points to the dynamically allocated object.
 
// Exercise 16.61: Define your own version of make_shared.

// To compile: compile as usual
// To compare: g++ lp-16-60-61.cpp -D DEBUG_COMPARE

#ifndef DEBUG_COMPARE
	#include "include\smart_ptr.h"
#endif
#ifdef DEBUG_COMPARE
	#include <memory>
#endif
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s = "Hello, Hello, World!";
	auto p = make_shared<string>(13, '-');
	auto q = make_shared<string>(s, 7);
	cout << *p << endl;			// -------------
	cout << *q << endl;			// Hello, World!
	cout << *p << endl;			// -------------
	using svec = vector<string>;
	using init = initializer_list<string>;
	auto r = make_shared<svec>(init({"a", "an", "the"}));
	for (const auto & s : *r)	// a
		cout << s << endl;		// an
	cout << *p << endl;			// the
	return 0;					// -------------
}