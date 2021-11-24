// 18/03/27 = Tue

// Exercise 16.41: Write a version of sum with a return type that is guaranteed to be large enough to hold the result of the addition.

#include <iostream>

using namespace std;

template<typename A, typename B>
auto sum(A a, B b) -> decltype(a + b)
{
	return a + b;
}

int main()
{
	// in fact, if the constants are really large, there will be problems
	cout << sum(1357924680123456789, 3141592653589793238) << endl;
}
