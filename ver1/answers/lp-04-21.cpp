// 18/02/03 = Sat

// Exercise 4.21: Write a program to use a conditional operator to find the elements in a vector<int> that have odd value and double the value of each such element.

// To run, entre, for example, "a <data\digits" in command prompt.

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

template<typename V>
void print(V v)
{
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vector<int> v;
	for (int i; cin >> i; v.push_back(i))
		;
	print(v);
	for (auto & e : v)
		e *= (e % 2) ? 2 : 1;
	print(v);
	return 0;
}