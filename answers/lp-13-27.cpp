// 18/03/04 = Sun

// Exercise 13.27: Define your own reference-counted version of HasPtr.

// Modified from lp-13-22.cpp

#include <cstddef>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class HasPtr
{
	string * ps;
	int i;
	size_t * use;
public:
	// constructor that takes a string (with a default argument)
	HasPtr(const string & s = string()) : ps(new string(s)), i(0),
										  use(new size_t(1))  { }
	// copy constructor
	HasPtr(const HasPtr & hp) : ps(hp.ps), i(hp.i),	use(hp.use)
	{
		++*use;
	}
	// copy-assignment operator
	HasPtr & operator=(const HasPtr & hp)
	{
		++*hp.use;
		--*use;
		if (use == 0) {
			delete ps;
			delete use;
		}
		ps = hp.ps;
		i = hp.i;
		use = hp.use;
		return *this;
	}
	// destructor
	~HasPtr()
	{
		--*use;
		if (*use == 0) {
			delete ps;
			delete use;
		}
	}
friend
	string get(const HasPtr & hp)
	{
		return *hp.ps;
	}
friend
	void set(HasPtr & hp, const string & str)
	{
		*hp.ps = str;
	}
};

// We may omit the declarations of get() and set(), because of "argument-dependent name lookup".

void print(HasPtr hp)
{
	cout << get(hp) << endl;
}

int main()
{
	HasPtr a("Hello, World!");
	HasPtr b = a;
	HasPtr c;
	c = b;

	print(a);					// Hello, World!
	print(b);					// Hello, World!
	set(a, "Nihao, Shijie!");
	print(c);					// Nihao, Shijie!

	return 0;
}