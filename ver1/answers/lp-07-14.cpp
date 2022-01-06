// 18/02/09 = Fri

// Exercise 7.14: Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.

#include <iostream>

using std::cout;
using std::ostream;
using std::endl;

struct S
{
	int a = 1;
	double b = 2.0;
	char c = 'c';
	S() = default;
	S(int a, double b, char c) : a(a), b(b), c(c) {}
};

ostream & out(ostream & os, const S & s)
{
	return os << s.a << " | " << s.b << " | " << s.c;
}

int main()
{
	out(cout, S()) << endl;
	return 0;
}
