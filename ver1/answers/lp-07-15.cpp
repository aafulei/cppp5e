// 18/02/09 = Fri

// Exercise 7.15: Add appropriate constructors to your Person class.

// Modified from lp-07-09.cpp

// By defining a constructor ourselves, we do not allow default initialization for a Person, which is meaningless.

#include <iostream>
#include <string>
// <sstream> and related operations are deleted

using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

struct Person
{
	string name;
	string addr;
	Person(const string & n) : name(n) {} // add; allow person without addr
	Person(const string & n, const string & a) : name(n), addr(a) {} // add
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
	// It would be an error if we forgot const in parameters in constructor. Why?
	print(cout, Person("Kaka", "Japan")) << endl;
	return 0;
}