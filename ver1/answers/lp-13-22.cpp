// 18/03/04 = Sun

// Exercise 13.22: Assume that we want HasPtr to behave like a value. That is, each object should have its own copy of the string to which the objects point. We’ll show the definitions of the copy-control members in the next section. However, you already know everything you need to know to implement these members. Write the HasPtr copy constructor and copy-assignment operator before reading on.

// Built incrementally on lp-13-11.cpp

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
	string * ps;
	int i;
public:
	// constructor that takes a string (with a default argument)
	HasPtr(const string & s = string()) : ps(new string(s)), i(0) { }
	// copy constructor
	HasPtr(const HasPtr & hp) : ps(new string(*hp.ps)), i(hp.i) { }
	// copy-assignment operator
	HasPtr & operator=(const HasPtr & hp)
	{
		if (&hp != this) {			// allow self-assignment
			delete ps;				// avoid memory leaks
			ps = new string(*hp.ps);
			i = hp.i;
		}
		return *this;
	}
	// destructor
	~HasPtr()
	{
		delete ps;
	}
};

void progress(size_t i, size_t n)
{
	int p = (i + 1) * 100 / n;
	if (p != i * 100 / n)
		cout << p << "%\r";
	if (p == 100)
		cout << "    " << endl;
}

void process(size_t size)
{
	HasPtr a;
	HasPtr b("Hello, World!");
	const size_t n = size;
	cout << "Allocating resources ..." << endl;
	for (size_t i = 0; i < n; ++i) {
		a = a = b = b;
		progress(i, n);
	}
	cout << "Press any key to terminate ..." << endl;
	cin.get();
}

int main()
{
	process(100'000'000);
	return 0;
}