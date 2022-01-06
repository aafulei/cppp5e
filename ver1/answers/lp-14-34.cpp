 // 18/03/14 = Wed

// Exercise 14.34: Define a function-object class to perform an if-then-else operation: The call operator for this class should take three parameters. It should test its first parameter and if that test succeeds, it should return its second parameter; otherwise, it should return its third parameter.

// Print the sign of a number read from input until 0 is read.

#include <iostream>

using namespace std;

template<typename T>
struct Ternary
{
	T operator()(bool a, T b, T c) const
	{
		return a ? b : c;
	}
};

int main()
{
	for (double d = 1.0; cin >> d && d != 0;
		cout << Ternary<char>()(d > 0, '+', '-') << endl)
		;
	return 0;
}