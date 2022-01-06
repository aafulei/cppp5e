// 18/01/23 = Mon

// Exercise 10.3: Use accumulate to sum the elements in a vector<int>.

// To run, enter, for example, "a <data\digits" in command prompt.

// std::accumulate is defined in <numeric>, not <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

template <typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vector<int> v;
	for (int i; cin >> i; v.push_back(i))
		;
	print(v);
	cout << accumulate(v.cbegin(), v.cend(), 0) << endl;	// 19
	return 0;
}