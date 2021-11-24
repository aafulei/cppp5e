// 18/01/18 = Thu: try
// 18/02/19 = Mon

// Exercise 9.31: The program on page 354 to remove even-valued elements and duplicate odd ones will not work on a list or forward_list. Why? Revise the program so that it works on these types as well.

// // silly loop to remove even-valued elements and insert a duplicate of odd-valued elements
// vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
// auto iter = vi.begin(); // call begin, not cbegin because we're changing vi
// while (iter != vi.end()) {
// 	if (*iter % 2) {
// 		iter = vi.insert(iter, *iter); // duplicate the current element
// 		iter += 2; // advance past this element and the one inserted before it
// 	}
// 	else
// 		iter = vi.erase(iter);     // remove even elements
// 		// don't advance the iterator; iter denotes the element after the one we erased
// }

// Answer:
// 1. For a list, compound assignment (+=) is not defined for the iterators. To adapt, change "iter += 2" to "++++iter;".
// 2. For forward_list, specialized operations (e.g. insert_after) are defined.

#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::forward_list;
using std::list;
using std::string;
using std::vector;

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

void rem_even_dup_odd(list<int> & lst)
{
	for (auto it = lst.begin(); it != lst.end(); ) {
		if (*it % 2 == 1) {
			it = lst.insert(it, *it);
			++++it;
		}
		else
			it = lst.erase(it);
	}
}

void rem_even_dup_odd(forward_list<int> & fl)
{
	auto p = fl.before_begin(), q = fl.begin();
	while (q != fl.end()) {
		if (*q % 2 == 1) {
			q = fl.insert_after(p, *q);
			++++p;
			++++q;
		}
		else
			q = fl.erase_after(p);
	}
}

template<typename C, typename const_it>
void process(const const_it b, const const_it e)
{
	cout << string(25, '-') << endl;
	C c(b, e);
	print(c);
	rem_even_dup_odd(c);
	print(c);
}

int main()
{
	const vector<vector<int>> vv = {{},
									{0},
									{1},
									{0, 1},
									{1, 0},
									{1, 2, 3},
									{4, 5, 6},
									{7, 7, 7, 8},
									{9, 0, 0, 0},
									{1, 3, 5, 7, 9},
									{2, 4, 6, 8, 0},
									{1, 2, 3, 4, 5, 6, 7, 8, 9},
									{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
	for (const auto & v : vv) {
		const auto b = v.cbegin(), e = v.cend();
		process<list<int>>(b, e);
		process<forward_list<int>>(b, e);
	}
	return 0;
}