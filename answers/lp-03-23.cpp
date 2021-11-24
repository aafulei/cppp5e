// 17/10/23 = Mon
// 18/01/27 = Sat: a concise for loop that makes int i a local variable

// Exercise 3.23: Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.

// To run, enter, for example "a <data\digits" in command prompt.

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

template<typename V>
void vprint(V const& v)		// no need to spell out std::vector here
{
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vector<int> v;
	for (int i; cin >> i && v.size() <= 10; v.push_back(i))
		;
	vprint(v);
	for (auto it = v.begin(); it != v.end(); ++it)
		*it *= 2;
	vprint(v);
	return 0;
}