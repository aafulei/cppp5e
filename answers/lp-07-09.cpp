// 18/02/09 = Fri

// Exercise 7.9: Add operations to read and print Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260).

// Exercise 7.4: Write a class named Person that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.

// Exercise 7.5: Provide operations in your Person class to return the name and address.

// Modified from lp-07-04-05.cpp

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::istream;
using std::istringstream;
using std::ostream;
using std::ostringstream;
using std::string;

struct Person
{
	string name;
	string addr;

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
	istringstream iss("Kaka Japan");
	ostringstream oss;
	Person frog;
	read(iss, frog);
	print(oss, frog);			// of course, we may directly print to cout
	cout << oss.str() << endl;
	return 0;
}