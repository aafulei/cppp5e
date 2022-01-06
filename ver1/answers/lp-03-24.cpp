// 17/10/23 = Mon
// 18/01/27 = Sat: reverse iterator; new arithmetic for indexing; concise for loop

// Exercise 3.24: Redo the last exercise from § 3.3.3 (p. 105) using iterators.

// Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to- last, and so on.

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Given {1, 2, 3, 4, 5}, returns {3, 5, 7, 9}, not {3, 7, 5}
void adj_pair_sum(vector<int> const& v)
{
	if (!v.empty())
		for (auto it = v.cbegin() + 1; it != v.cend(); ++it)
			cout << *(it-1) + *it << " ";
	cout << endl;
}

// Given {1, 2, 3, 4, 5}, returns {6, 6, 3}, not {6, 6, 6}
void sym_pair_sum(vector<int> const& v)
{
	auto itb = v.cbegin();
	auto ite = v.crbegin();							// reverse iterator
	auto mid = itb + (v.cend() - v.cbegin()) / 2;

	for (; itb != mid; ++itb, ++ite)
		cout << *itb + *ite << " ";
	if (v.size() % 2 == 1)
		cout << *mid;
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