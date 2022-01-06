// 18/01/27 = Sat

// use iterators to do binary search for 0-9 in an ordered sequence of integers

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using iter = vector<int>::iterator;

iter binary_search(iter lo, iter hi, int val)
{
	if (lo == hi)	// if vector is empty, dereferencing is undefined
		return hi;
	auto nf = hi;
	for (auto mi = lo + (hi - lo) / 2; lo != mi; mi = lo + (hi - lo) / 2)
		if (val == *mi)
			return mi;
		else if (val < *mi)
			hi = mi;
		else
			lo = mi;
	if (val == *lo)
		return lo;
	else
		return nf;
}

int main()
{
	cout << "Enter an ordered sequence of integers: ";
	vector<int> v;
	for (int i; cin >> i; v.push_back(i))
		;
	for (int i = 0; i != 10; ++i) {
		cout <<  "Search for " << i << " : ";
		auto it = binary_search(v.begin(), v.end(), i);
		if (it == v.end())
			cout << "Not Found" << endl;
		else
			cout << *it << endl;
	}
}