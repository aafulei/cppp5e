// 18/03/07 = Wed
// 18/03/08 = Thu: rewrite DEBUG_ macros to disable or enable move
 
// Exercise 13.47: Give the copy constructor and copy-assignment operator in your String class from exercise 13.44 in § 13.5 (p. 531) a statement that prints a message each time the function is executed.

// Answer: The following statements have been added to String.cpp:

// #ifdef DEBUG_COPY
// 	clog << "Call: constructor on (const char *) \"" << cs << "\"" << endl;
// #endif

// #ifdef DEBUG_COPY
// 	clog << "Call: copy constructor on (const String &) \"" << s << "\"" << endl;
// #endif

// #ifdef DEBUG_COPY
// 	clog << "Call: copy-assignment operator on (const String &) \"" << s << "\"" << endl;
// #endif

// Exercise 13.48: Define a vector<String> and call push_back several times on that vector. Run your program and see how often Strings are copied.

// Answer:

// To compile:
// g++ lp-13-47-48.cpp -D DEBUG_COPY

// Note:

// Adding a move constructor later will change the output.

// To see how the output differs with a move constructor, compile with:
// g++ lp-13-47-48.cpp -D DEBUG_MOVE

#include "include\String.h"
#include "source\String.cpp"
#include <iostream>
#include <vector>

#ifdef DEBUG_COPY
#define DEBUG_LINE
#endif

#ifdef DEBUG_MOVE
#define DEBUG_LINE
#endif

using namespace std;

String get_a_String(String s)
{
	return s;
}

int main()
{
	vector<String> v;
	for (char a[2] = "A"; a[0] != 'Z' + 1; ++a[0]) {
#ifdef DEBUG_LINE
		cout << string(50, '-') << endl;
		cout << "capacity = " << v.capacity() << endl;
#endif
		// call String's copy constructor ifdef DEBUG_COPY
		// call String's move constructor ifdef DEBUG_MOVE
		v.push_back(a);
#ifdef DEBUG_LINE
		cout << "capacity = " << v.capacity() << endl;
#endif
	}
#ifdef DEBUG_LINE
	cout << string(50, '-') << endl;
#endif
	vector<String> v2;
	v2 = v;							// call String's copy constructor
#ifdef DEBUG_LINE
	cout << string(50, '-') << endl;
#endif
	vector<String> v3(26);
	v3 = v2;						// call String's copy-assignment operator
#ifdef DEBUG_LINE
	cout << string(50, '-') << endl;
#endif
	// call String's copy constructor ifdef DEBUG_COPY
	// call String's move constructor ifdef DEBUG_MOVE
	String s = get_a_String("Hello, World!"), t;
	// call String's copy-assignment operator ifdef DEBUG_COPY
	// call String's move-assignment operator ifdef DEBUG_MOVE
	t = get_a_String("C++ Primer");
	return 0;
}