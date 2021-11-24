// 18/02/10 = Sat

// Exercise 7.38: We might want to supply cin as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses cin as a default argument.

// Answer: If you are asking for a solution to the constructor of Sales_data class, then that is

// Sales_data(std::istream & is = std::cin) {	read(is, *this); }

// In what follows, we provide a general solution. 

// To run, enter, for example, "a <data\digits" in command prompt, which shall print 2.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;

class A
{
	int a = 0;
public:
	A(istream & is = cin)
	{	cin >> a; }
	int get() const
	{	return a; }
};

int main()
{
	A a;
	cout << a.get() << endl;
	return 0;
}