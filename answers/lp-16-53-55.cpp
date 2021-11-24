// 18/03/28 = Wed

// Exercise 16.53: Write your own version of the print functions and test them by printing one, two, and five arguments, each of which should have different types.

// Exercise 16.54: What happens if we call print on a type that doesn’t have an << operator?

// Answer: Compilation error: no match for 'operator<<'.

// Exercise 16.55: Explain how the variadic version of print would execute if we declared the nonvariadic version of print after the definition of the variadic version.

// Answer: In general, this would cause a compilation error. When there is only one argument to be printed, the compiler would still instantiate the variadic version, since the non-variadic version is not in scope. That way, print(os, a ...) would be a call with an empty a, which hsa no matching call.

// To the contrary, suppose we have declared the non-variadic version beforehand. When there is only one argument to be printed, the compiler would instantiate the non-variadic version, since it is more specialized. This would terminate the printing process correctly.

// However, there seems to be an exception. Suppose the last argument has a class type (which has overloaded operator<<). It seems that even we haven't forward declared the non-variadic version, the compiler will still instantiate it. See postscript for details.

#include <iostream>
#include <string>

using namespace std;

// without this declaration of non-variadic version, there would be an error
template <typename T> ostream & print(ostream &, const T &);

template<typename T, typename ... A>
ostream & print(ostream & os, const T & t, const A & ... a)
{
	os << t << ", ";
	return print(os, a ...);
}

template <typename T>
ostream & print(ostream & os, const T & t)
{
	return os << t << endl;
}

class Empty {};

int main()
{
	int i = 42;
	bool b = false;
	char c = 'f';
	double d = 42.0;
	string s = "forty-two";
	print(cout, i);
	print(cout, i, s);
	print(cout, i, b, c, d, s);
	// print(cout, i, Empty());		// error: no matching call for 'operator<<'
	return 0;
}

/* ---------- postscript ---------

// Don't know why the following program would compile.

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class C
{
	int i;
public:
	C(int i) : i(i) {}
	friend ostream & operator<<(ostream &, const C &);
};

ostream & operator<<(ostream & os, const C & c)
{
	return os << c.i;
}

template<typename T, typename ... A>
ostream & print(ostream & os, const T & t, const A & ... a)
{
	cout << "[Instantiate: variadic version] ";
	os << t << ", ";
	return print(os, a ...);
}

template <typename T>
ostream & print(ostream & os, const T & t)
{
	cout << "[Instantiate: non-variadic version] ";
	return os << t << endl;
}

int main()
{
	int i = 33;
	// print(cout, C(42), i);	// error: no surprise
	print(cout, i, C(42));		// okay: don't know why
	return 0;
}

----------------------------------- */