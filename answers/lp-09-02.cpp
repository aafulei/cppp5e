// 17/10/25 = Wed
// 18/01/16 = Tue: redo

// Exercise 9.2: Define a list that holds elements that are deques that hold ints.

// print:
// 1 2 3
// 4 5 6
// 7 8 9

#include <deque>
#include <iostream>
#include <list>

using std::cout;
using std::deque;
using std::endl;
using std::list;

int main()
{
	list<deque<int>> c;
	c.push_front(deque<int>{1, 2, 3});
	c.push_back(deque<int>{4, 5, 6});
	// c.emplace_back(inits) constructs an element with inits and appends it to c
	c.emplace_back(deque<int>{7, 8, 9});
	for (const auto & i : c) {
		for (const auto & j : i)
			cout << j << ' ';;
		cout << endl;
	}
	return 0;
}