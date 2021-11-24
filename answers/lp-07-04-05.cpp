// 18/02/09 = Fri

// Exercise 7.4: Write a class named Person that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.

// Exercise 7.5: Provide operations in your Person class to return the name and address. Should these functions be const? Explain your choice.

// Answer: Yes, because they do not change to the object.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct Person
{
	string name;
	string addr;

	string get_name() const { return name; }
	string get_addr() const { return addr; }
};

int main()
{
	Person frog;
	frog.name = "Kaka";
	frog.addr = "Japan";
	cout << frog.get_name() << " @ " << frog.get_addr() << endl;
	return 0;
}