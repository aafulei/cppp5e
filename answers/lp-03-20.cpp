// 17/10/22 = Sun
// 18/01/27 = Sat: new arithmetic for indexing; concise for loop

// Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.

// To run, enter, for example "a <data\digits" in command prompt

// For completeness, test vectors of 0, 1, 2 elements.

// The first half of a vector is [0, v.size() / 2). (Excluding the mid-point if number of elements are odd). Be very careful of expression like (v.size() - 1) / 2, because if v is empty, this could be a disaster!

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Given {1, 2, 3, 4, 5}, returns {3, 5, 7, 9}, not {3, 7, 5}
void adj_pair_sum(vector<int> const& v)
{
	for (decltype(v.size()) i = 1; i < v.size(); ++i)
		cout << v[i-1] + v[i] << " ";
	cout << endl;
}

// Given {1, 2, 3, 4, 5}, returns {6, 6, 3}, not {6, 6, 6}
void sym_pair_sum(vector<int> const& v)
{
	auto sz = v.size();
	for (decltype(sz) i = 0; i != sz / 2; ++i)
		cout << v[i] + v[sz-1-i] << " ";
	if (sz % 2 == 1)
		cout << v[sz / 2];
	cout << endl;
}

int main()
{
	vector<int> v;
	for (int i; cin >> i; v.push_back(i), cout << i << " ")
		;
	cout << endl;
	adj_pair_sum(v);
	sym_pair_sum(v);
	return 0;
}