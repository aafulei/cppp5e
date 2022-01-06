// 17/10/25 = Wed
// 18/01/16 = Tue: redo

// Exercise 9.5: Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

auto search(vector<int>::const_iterator b, vector<int>::const_iterator e, int val)
{
	for (; b != e; ++b)
		if (*b == val)
			return b;
	return e;
}

void find(vector<int>::const_iterator b, vector<int>::const_iterator e, int val)
{
	auto it = search(b, e, val);
	if (it == e)
		cout << val << " is not found." << endl;
	else
		cout << *it << " is found at position " << (it - b) << "." << endl;
}

template<typename V>
void print(const V & v)
{
	for (const auto & e : v)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print(vec);
	auto b = vec.cbegin();
	auto e = vec.cend();
	find(b, e, 0);
	find(b, e, 9);
	find(b, e, 10);
	find(b, e, 42);
	return 0;
}