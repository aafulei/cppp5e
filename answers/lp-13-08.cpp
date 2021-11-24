// 18/03/03 = Sat
// 18/03/04 = Sun: add del_string() in operator= to avoid memory leaks

// Exercise 13.8: Write the assignment operator for the HasPtr class from exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your assignment operator should copy the object to which ps points.

// Built incrementally on lp-13-05.cpp

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	// constructor that takes a string (with a default argument)
	HasPtr(const string & s = string()) : ps(new string(s)), i(0) { }
	// copy constructor
	HasPtr(const HasPtr & hp) : ps(new string(*hp.ps)), i(hp.i) { }
	// copy-assignment operator
	HasPtr & operator=(const HasPtr & hp)
	{
		if (&hp != this) {			// Important: to allow self-assignment
			del_string();			// Important: to avoid memory leaks
			ps = new string(*hp.ps);
			i = hp.i;
		}
		return *this;
	}
	// for test
	string get_string()
	{
		return *ps;
	}
	// to avoid memory leaks
	void del_string() 
	{
		delete ps;
		ps = nullptr;
	}
private:
	string * ps;
	int i;
};

void progress(size_t i, size_t n)
{
	int p = (i + 1) * 100 / n;
	if (p != i * 100 / n)
		cout << p << "%\r";
	if (p == 100)
		cout << "    ";
}

int main()
{
	HasPtr a("Hello, World!");
	HasPtr b;
	cout << a.get_string() << endl;	// Hello, World!
	cout << b.get_string() << endl;	// (empty string)
	b = a;
	cout << b.get_string() << endl;	// Hello, World!

	// test for self-assignment, and memory leaks
	const size_t n = 100'000'000;
	cout << endl << "Allocating resources ..." << endl;
	for (size_t i = 0; i < n; ++i) {
		a = a = b = b;
		progress(i, n);
	}
	cout << endl << "Press any key to terminate ..." << endl;
	cin.get();						// press any key to terminate
	return 0;
}
