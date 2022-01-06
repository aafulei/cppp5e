// 18/03/13 = Tue

// Demonstrate how overloaded operator-> works.

// Suppose operator-> is overloaded for class type T, and t is an object of class type T. The operator-> must return either one of the two types:
// 1. S * operator->();
// 2. R   operator->();
// For case 1, t->m tries to fetch the member m of class type S.
// For case 2, class type R must overload its operator->, too. In this case, the process of access is repeated, until it reaches a state of case 1.

// From another point of view, the left-hand operand (LHS) of the operator-> must fall into two categories:
// (i) LHS is a pointer, then LHS->RHS is equivalent to (*LHS).RHS;
// (ii) LHS is an object, then LHS.operator->() returns:
// (ii.case 1) ps, which is a S *, then LHS->RHS is equivalent to (*ps).RHS;
// (ii.case 2) r, which is an R, then LHS->RHS is equivalent to r->RHS. How r->RHS is interpreted follows the same rule. Thus the access of operator-> can be nested.

// Final note: for case 2, in fact, you may choose to return either R or R &. Which type you return depends on a trade-off between the cost of copy and safety/encapsulation.
// Pros of returning an R &: need not to copy.
// Cons of returning an R: expose your private data member to user. Consider:

// #include <iostream>
// #include <string>

// using namespace std;

// class R
// {
// 	int a = 22;
// public:
// 	R(int a) : a(a) 		{}
// 	R * operator->() 		{ return this; }
// 	R & operator=(int rhs) 	{ a = rhs; }
// 	void info() 			{ cout << a << endl; }
// };

// class S
// {
// 	R r = 44;
// public:
// 	R operator->() 			{ return r; }
// };

// class T
// {
// 	R r = 44;
// public:
// 	R & operator->() 		{ return r; }
// };

// int main()
// {
// 	S s;
// 	s->info();				// 44
// 	s.operator->() = 88;
// 	s->info();				// 44

// 	T t;
// 	t->info();				// 44
// 	t.operator->() = 88;
// 	t->info();				// 88
	
// 	return 0;
// }

#include <iostream>
#include <string>

using namespace std;

struct A
{
	A * operator->()	{ return this; }
	void f()			{ cout << "How do you do" << endl; }
};

struct B
{
	A a;
	A operator->()		{ return a; }
	void f()			{ cout << "How are you" << endl; }
};

struct C
{
	B b;
	B operator->()		{ return b; }
	void f()			{ cout << "Hello" << endl; }
};

struct D
{
	C c;
	C operator->()		{ return c; }
	void f()			{ cout << "Hi" << endl; }
};

void line()				{ cout << string(50, '-') << endl; }

int main()
{
	// category (i)
	typedef A *PA;
	typedef B *PB;
	typedef C *PC;
	typedef D *PD;
	PA()->f();										// How do you do
	PB()->f();										// How are you
	PC()->f();										// Hello
	PD()->f();										// Hi

	line();
	
	// category (ii)
	A()->f();			// case 1					// How do you do
	B()->f();			// case 2					// How do you do
	C()->f();			// case 2					// How do you do
	D()->f();			// case 2					// How do you do

	line();

	// for your interest
	D().f();										// Hi
	D().operator->().f();							// Hello
	D().operator->().operator->().f();				// How are you
	D().operator->().operator->().operator->().f();	// How do you do

	return 0;
}