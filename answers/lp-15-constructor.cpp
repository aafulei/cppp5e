// 18/03/18 = Sun

// Demonstrate how constructors work in class hierarchy.

#include <iostream>
#include <string>

using namespace std;

struct A
{
	explicit A()			{ clog << "A()" << endl; }
	explicit A(int i)		{ clog << "A(int)" << endl; }
	explicit A(string s)	{ clog << "A(string)" << endl; }
};

struct B : A
{
	using A::A;
};

struct C : B
{
	// cannot inherit constructors from indirect base A
	// using A::A;
	// A is not a direct base of C
	// C(int i) : A(i) {}
	// Default constructors cannot/need not to be inherited. It is called implicitly.
	using B::B;
	C() = default;
	// override the constructor that takes an int
	C(int i) { clog << "C(int)" << endl; }
};

int main()
{
	int i = 42;
	string s;
	B b0;			// A()
	B b1(i);		// A(int)
	B b2(s);		// A(string)
	C c0;			// A()
	C c1(i);		// A() C(int)
	// C c2(s);		// constructor that takes a string is not inherited in C
	return 0;
}