// 18/03/03 = Sat

// Exercise 13.5: Given the following sketch of a class, write a copy constructor that copies all the members. Your constructor should dynamically allocate a new string (§ 12.1.2, p. 458) and copy the object to which ps points, rather than copying ps itself.

// class HasPtr {
// public:
// 	HasPtr(const std::string &s = std::string()):
// 		ps(new std::string(s)), i(0) { }
// private:
// 	std::string *ps;
// 	int i;
// };

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
	// for test
	string get_string()
	{
		return *ps;
	}
	// for test
	void del_string() 
	{
		delete ps;
		ps = nullptr;
	}
private:
	string * ps;
	int i;
};

int main()
{
	HasPtr a("Hello, World!");
	HasPtr b(a);
	cout << a.get_string() << endl;	// Hello, World!
	a.del_string();
	cout << b.get_string() << endl;	// Hello, World!
	return 0;
}


