// 18/03/14 = Wed

// Exercise 14.43: Using library function objects, determine whether a given int value is divisible by any element in a container of ints.

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::placeholders;

template <typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

int main()
{
	cout << "Enter a number to see whether it is a multiple of ";
	vector<int> v = {2, 3, 5, 7};
	print(v);
	cout << boolalpha;
	for (int a; cin >> a;
		cout << any_of(v.begin(), v.end(),
					   bind(equal_to<int>(), 0,
					   bind(modulus<int>(), a, _1)))
			 << endl)
		;
	return 0;
}