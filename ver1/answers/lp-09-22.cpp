// 18/01/17 = Wed: try
// 18/02/18 = Sun
// 18/02/19 = Mon: iterator arithmetic

// Exercise 9.22 : Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?

// vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
// while (iter != mid)
// 	if (*iter == some_val)
// 		iv.insert(iter, 2 * some_val);

// Answer:
// 1. There is no increment to the iter in the while loop -- the loop is endless.
// 2. insert may invalidate the iterator.

// We write a function to loop over a vector. If some value appears in the first half, then insert double its value just before it.

// Assumptions:
// 1. If the number of elements is odd, the middle one does not belong to the first half.
// 2. By saying the first half, we mean the first half before the insertion.

// Iterator arithmetic:
// 1. Let [b, e) be an iterator range, there are exactly sz = (e-b) elements in it.
// 2. To denote the first half, excluding the one right in the middle, we use [b, m), where m = b + sz/2 = b + (e-b)/2.
// 3. If the definition of the first half includes the one right in the middle, then we need an adjustment, which is m += (sz % 2).
// 4. In this case, we focus on the original first half. Then an offset is needed, which is, given an insertion happens, offset += (sz % 2).

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void insert_double(vector<int> & iv, int some_val)
{
	// if vector is empty, it is an error to dereference the iterator
	if (iv.empty())
		return;
	vector<int>::difference_type offset = 0;
	for (auto it = iv.begin(); it != iv.begin() + iv.size()/2 + offset; ++it) {
		if (*it == some_val) {
			it = iv.insert(it, 2 * some_val);
			offset += (iv.size() % 2);
			it += 1;
		}
	}
}

template<typename V>
void print(const V & v)
{
	for (const auto & e : v)
		cout << e << " ";
	cout << endl;
}

void process(vector<int> & v, int val)
{
	cout << string(25, '-') << endl;
	print(v);
	insert_double(v, val);
	print(v);
}

int main()
{
	const int val = 1;
	vector<vector<int>> vv =	{{},
								{0},
								{1},
								{0, 0},
								{1, 0},
								{1, 1},
								{0, 1, 1},
								{1, 0, 1},
								{1, 1, 1},
								{0, 1, 1, 0},
								{1, 1, 0, 0},
								{1, 1, 1, 1},
								{0, 0, 1, 0, 0},
								{1, 1, 0, 1, 1},
								{1, 1, 1, 1, 1}};
	for (auto & v : vv)
		process(v, val);
    return 0;
}
