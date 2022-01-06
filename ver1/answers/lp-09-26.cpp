// 18/01/17 = Wed
// 18/02/19 = Mon: use std::begin() and std::end() for built-in arrays

// Exercise 9.26: Using the following definition of ia, copy ia into a vector and into a list. Use the single-iterator form of erase to remove the elements with odd values from your list and the even values from your vector.

// int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::list;
using std::vector;

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

int main()
{
	const int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	
	// list
	list<int> lst(begin(ia), end(ia));
	print(lst);
	for (auto it = lst.begin(); it != lst.end(); )
		if (*it % 2 == 1)
			it = lst.erase(it);
		else
			++it;
	print(lst);

	// vector
	vector<int> vec(begin(ia), end(ia));
	print(vec);
	for (auto it = vec.begin(); it != vec.end(); )
		if (*it % 2 == 0)
			it = vec.erase(it);
		else
			++it;
	print(vec);
	
	return 0;
}