// 17/10/22 = Sun
// 18/01/27 = Sat: a concise for loop that makes int i a local variable

// Exercise 3.14: Write a program to read a sequence of ints from cin and store those values in a vector.

// To run, enter, for example, "a <data\digits" in command prompt

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> v;
	for (int i; cin >> i; v.push_back(i))
		;
	for (auto i : v)
		cout << i << " ";
	return 0;
}
