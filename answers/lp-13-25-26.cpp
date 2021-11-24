// 18/03/04 = Sun

// Exercise 13.25: Assume we want to define a version of StrBlob that acts like a value. Also assume that we want to continue to use a shared_ptr so that our StrBlobPtr class can still use a weak_ptr to the vector. Your revised class will need a copy constructor and copy-assignment operator but will not need a destructor. Explain what the copy constructor and copy-assignment operators must do. Explain why the class does not need a destructor.

// Answer: The copy constructor will dynamically allocate memory for its own use, and copy the vector to the memory. The copy-assignment operator will replace the vector with the one in which it copies from. A shared_ptr manages resources in an automatic manner. When the use count of the resources becomes 0, the resources will be automatically freed. Thus the class does not need a destructor.

// Exercise 13.26: Write your own version of the StrBlob class described in the previous exercise.

// Modified from lp-12-02-03.cpp

// To make StrBlob act like a value:
// g++ lp-13-25-26.cpp -D VALUE_LIKE

// To make StrBlob act like a pointer:
// compile as usual

#include "include\StrBlob.h"
#include "source\StrBlob.cpp"
#include <iostream>

using namespace std;

int main()
{
	StrBlob a({"a", "an", "the"});
	cout << a.use_count() << endl;	// 1
	StrBlob b(a);
	cout << b.use_count() << endl;	// 1
	a = b;
	cout << a.use_count() << endl;	// 1
	cout << b.use_count() << endl;	// 1
	while (!a.empty())
		a.pop_back();
	cout << a.empty() << endl;		// 1
	cout << b.empty() << endl;		// 0
	return 0;
}