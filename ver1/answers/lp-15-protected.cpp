// 18/03/17 = Sat

// Demonstrate that the access to a protected member is not granted generally to a derived class. A derived class can only access a protected member in its base class via a derived object as an implementor (rather than as a user). It cannot, say, take a base-class object in a member function and freely alter the value of the protected part of the base-class object.

#include <iostream>

using namespace std;

struct B
{
protected:
	 int a = 11;
};

struct D : B
{
	void f() 			{ this->a = 22; 	}
	void g(D & d) 		{ d.a = 33; }
	// void h(B & b) 	{ b.a = 44; }
	void print() const 	{ cout << a << endl; }
};

int main()
{
	D d, e;
	d.print();		// 11
	d.f();
	d.print();		// 22
	d.g(e);
	e.print();		// 33
	// d.a = 55;	// user (not implementor) of class D cannot access a
	return 0;
}
