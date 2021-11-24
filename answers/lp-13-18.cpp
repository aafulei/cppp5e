// 18/03/03 = Sat

// Exercise 13.18: Define an Employee class that contains an employee name and a unique employee identifier. Give the class a default constructor and a constructor that takes a string representing the employee’s name. Each constructor should generate a unique ID by incrementing a static data member.

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
	return 0;
}