// 18/02/08 = Thu

// Define a pointer that points to a function which takes and returns a pointer to function, either of which takes and returns an int.

#include <iostream>

using std::cout;
using std::endl;

int f(int) { return 42; }
int (*foo(int (*)(int)))(int) {	return &f; }

int main()
{
	int (*(*p)(int(*)(int)))(int) = &foo;
	std::cout << (*(*p)(&f))(0) << std::endl;
	return 0;
}