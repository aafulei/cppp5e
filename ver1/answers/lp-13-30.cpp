// 18/03/04 = Sun

// Exercise 13.30: Write and test a swap function for your valuelike version of HasPtr. Give your swap a print statement that notes when it is executed.

// Built incrementally on lp-13-23.cpp

#include <iostream>
#include <string>
#include <utility>		// to use std::swap()

using namespace std;

class HasPtr
{
	string * ps;
	int i;
public:
	HasPtr(const string & s = string()) : ps(new string(s)), i(0) { }
	HasPtr(const HasPtr & hp) : ps(new string(*hp.ps)), i(hp.i) { }
	// using copy-and-swap technique
	HasPtr & operator=(HasPtr hp)
	{
		swap(*this, hp);
		return *this;
	}
	// Alternatively:
	// HasPtr & operator=(const HasPtr & hp)
	// {
	// 	auto pt = new string(*hp.ps);
	// 	delete ps;
	// 	ps = pt;
	// 	i = hp.i;
	// 	return *this;
	// }
	~HasPtr()
	{
		delete ps;
	}
friend
	void swap(HasPtr & lhs, HasPtr & rhs);
friend
	void print(const HasPtr & hp);
};

void swap(HasPtr & lhs, HasPtr & rhs)
{
	clog << "void swap(HasPtr & lhs, HasPtr & rhs)" << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

void print(const HasPtr & hp)
{
	cout << *hp.ps << endl;
}

int main()
{
	HasPtr a("Hello");
	HasPtr b("World");
	HasPtr c;
	c = a;				// call swap
	swap(b, c);			// call swap
	print(b);			// Hello
	print(c);			// World
	return 0;
}