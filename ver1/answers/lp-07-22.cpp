// 18/02/10 = Sat

// Exercise 7.22: Update your Person class to hide its implementation.

// Modified from lp-07-15.cpp

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Person		// change from struct to class
{
	friend istream & read(istream &, Person &);			// add friend
	friend ostream & print(ostream &, const Person &);	// add friend

	string name;
	string addr;
public:				// add public access specifier
	Person(const string & n) : name(n) {}
	Person(const string & n, const string & a) : name(n), addr(a) {}
	string get_name() const { return name; }
	string get_addr() const { return addr; }
};

istream & read(istream & is, Person & p)
{
	return is >> p.name >> p.addr;
}

ostream & print(ostream & os, const Person & p)
{
	return os << p.get_name() << " @ " << p.get_addr();
}

int main()
{
	print(cout, Person("Kaka", "Japan")) << endl;
	return 0;
}