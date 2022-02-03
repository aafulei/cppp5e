// 22/02/03 = Thu
// 18/02/08 = Thu

// Exercise 6.54: Write a declaration for a function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type.

// Exercise 6.55: Write four functions that add, subtract, multiply, and divide two int values. Store pointers to these values in your vector from the previous exercise.

// Exercise 6.56: Call each element in the vector and print their result.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

namespace A 	// <cstdlib> has defined div_t div(int, int);
{
	int add(int a, int b) { return a + b; }
	int sub(int a, int b) { return a - b; }
	int mul(int a, int b) { return a * b; }
	int div(int a, int b) { return a / b; }
}

int main()
{
	using F = int(*)(int, int);
	int (*p)(int, int) = &A::add;
	F q = &A::sub;
	auto r = &A::mul;
	decltype(r) s = &A::div;
	vector<int (*)(int, int)> v;
	// alternatively:
	// vector<decltype(p)> v;
	v = {p, q, r, s};
	for (auto e : v)
		cout << (*e)(42, 24) << " ";	// 66 18 1008 1
	cout << endl;
	return 0;
}
