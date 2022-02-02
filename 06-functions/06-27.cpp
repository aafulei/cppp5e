// 22/02/02 = Wed
// 18/02/07 = Wed

// Exercise 6.27: Write a function that takes an initializer_list<int> and produces the sum of the elements in the list.

#include <initializer_list>
#include <iostream>

using std::initializer_list;
using std::cout;
using std::endl;

int sum(initializer_list<int> lst)
{
	int result {};
	for (auto i : lst)
		result += i;
	return result;
}

int main()
{
	cout << sum({}) << endl;
	cout << sum({1}) << endl;
	cout << sum({1,2}) << endl;
	cout << sum({1,2,3}) << endl;
	cout << sum({1,2,3,4}) << endl;
	cout << sum({1,2,3,4,5}) << endl;
}
