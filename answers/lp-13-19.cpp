// 18/03/03 = Sat

// Exercise 13.19: Does your Employee class need to define its own versions of the copy-control members? If so, why? If not, why not? Implement whatever copy-control members you think Employee needs.

// Answer: Yes, because we want to keep the ID unique for each employee.

// Built incrementally on lp-13-18.cpp

#include <iostream>
#include <string>

using namespace std;
using ID = unsigned;

class Employee
{
	static ID serial;
	ID id;
	string name;
public:
	Employee() : id(++serial) {}
	Employee(const string & name) : id(++serial), name(name) {}
	Employee(const Employee & e) : id(++serial), name(e.name) {}
	Employee & operator=(const Employee & e)
	{
		name = e.name;
	}
	void info() const
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
	}
};

unsigned Employee::serial = 0;

int main()
{
	Employee e1("Jackie");
	e1.info();
	Employee e2("James");
	e2.info();
	Employee e3(e1);		// here comes another Jackie
	e3.info();
	e3 = e2;				// this Jackie changes his name to James
	e3.info();
	return 0;
}