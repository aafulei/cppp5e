// 18/03/03 = Sat

// Exercise 13.13: A good way to understand copy-control members and constructors is to define a simple class with these members in which each member prints its name:

// struct X
// {
// 	X()				{ cout << "X()"				<< endl; }
// 	X(const  X &)	{ cout << "X(const  X&)"	<< endl; }
// };

// Add the copy-assignment operator and destructor to X and write a program using X objects in various ways: Pass them as nonreference and reference parameters; dynamically allocate them; put them in containers; and so forth. Study the output until you are certain you understand when and why each copy-control member is used. As you read the output, remember that the compiler can omit calls to the copy constructor.

#include <iostream>
#include <vector>

using namespace std;

struct X
{
	X()						 { cout << "X()"						<< endl; }
	X(const  X &)			 { cout << "X(const  X&)"				<< endl; }
	X & operator=(const X &) { cout << "X & operator=(const X &)"	<< endl; }
	~X()					 { cout << "~X()"						<< endl; }
};

void f(X)	{}
void g(X &)	{}

int main()
{
	X x;						// X()
	f(x);						// X(const  X&) ~X()
	g(x);						//
	auto px = new X();			// X()
	vector<X>().push_back(x);	// X(const  X&) ~X()
	return 0;					// ~X()
}