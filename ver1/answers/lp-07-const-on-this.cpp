// 18/03/12 = Mon

// Demonstrate how "const" works on "this"

// The "const" after the parameter list of a member function modifies the implicit "this".

// By default, "this" is a (const) pointer to non-const object. Though "this" is implicit, it follows the usual initialization rules. That is, by default, we cannot bind "this" to a const object. In other words, a const object cannot call an ordinary member function.

// To make a member function callable by a const object, we have to append "const" to its parameter list. In this way, the "this" becomes a pointer to const, so that we may bind it to a const object.

// If a member function is const, it can still be called by a non-const object, because we may freely bind a pointer-to-const to a non-const object, only that a non-const member function would be a better match in case of overloading.

// To summarize:
// 1. ordinary (non-const) member function: callable only by non-const object
// 2. const member function: callable by both const and non-const objects
// 3. overloading: (non-)const member function a better match for (non-)const

// See pages 258, 276.

#include <iostream>

using namespace std;

struct A
{
	void f() 		{ cout << "this is bound to a non-const object" << endl; }
	void f() const 	{ cout << "this is bound to a const object" 	<< endl; }
	void g() 		{ cout << "callable only by a non-const object"	<< endl; }
};

int main()
{
	A a;
	a.f();			// this is bound to a non-const object
	a.g();			// callable only by a non-const object

	const A b;
	b.f();			// this is bound to a const object
	// b.g();		// g() is can be called only by a non-const object

	return 0;
}