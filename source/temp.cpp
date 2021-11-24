#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

string dtos(double a, int n=10)
{
	stringstream ss;
	ss << setprecision(n) << a;
	return ss.str();
}


int main()
{
	string t = "((cas csalkd g))";
	auto b = t.cbegin();
	auto e = t.crbegin();
	while (*b == '(' && *e == ')') {
		++b;
		++e;
	}
	while (b != e.base()) {
		if (*b != ' ')
			cout << *b;
		++b;
	}
	// cout << "b: " << *b << endl;
	// cout << "e: " << *e << endl;
	return 0;
}