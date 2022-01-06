// 18/03/03 = Sat
// 18/03/04 = Sun: avoid memory leaks; allow self-assignment

// Exercise 13.11: Add a destructor to your HasPtr class from the previous exercises.

// Built incrementally on lp-13-08.cpp

#include <iostream>
#include <memory>					// to use shared_ptr in main()
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
		clog << "ps has been deleted." << endl;
	}
	// Since we have defined a destructor to delete ps, we must remove del_string() which deletes ps to avoid deleting twice.
private:
	string * ps;
	int i;
};

int main()
{
	shared_ptr<HasPtr> sptr = make_shared<HasPtr>("Hello, World!");
	return 0;
}	// ps has been deleted.