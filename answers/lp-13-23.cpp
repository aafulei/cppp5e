// 18/03/04 = Sun

// Exercise 13.23: Compare the copy-control members that you wrote for the solutions to the previous section’s exercises to the code presented here. Be sure you understand the differences, if any, between your code and ours.

// Difference 1:
// lp-13-22.cpp: first delete ps, then assign a new address
// lp-13-23.cpp: first copy a new address, then delete ps, then assign address
// (it is said to be exception-safe to put copying before deletion)

// Difference 2:
// lp-13-22.cpp: do nothing in case of self-assignment
// lp-13-23.cpp: do not check if it's self-assignment
// (more efficient if self-assignment does not happen often)
// (since we do a = a = b = b, so this should be slower than lp-13-22.cpp)

// Built incrementally on lp-13-22.cpp

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
		auto pt = new string(*hp.ps);
		delete ps;
		ps = pt;
		i = hp.i;
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