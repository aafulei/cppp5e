// 18/02/04 = Sun

// Exercise 5.17: Given two vectors of ints, write a program to determine whether one vector is a prefix of the other. For vectors of unequal length, compare the number of elements of the smaller vector. For example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool is_prefix(vector<int> v1, vector<int> v2)
{
	vector<int> &small = v1.size() <= v2.size() ? v1 : v2;
	vector<int> &large = v1.size() <= v2.size() ? v2 : v1;
	for (decltype(small.size()) i = 0; i != small.size(); ++i)
		if (small[i] != large[i])
			return false;
	return true;
}

int main()
{
	vector<int> v1 = {0, 1, 1, 2};
	vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
	cout << (is_prefix(v1, v2) ? "Yes" : "No") << endl;
	return 0;
}