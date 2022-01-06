// 18/01/19 = Fri

// Exercise 9.38: Write a program to explore how vectors grow in the library you use.

// First we grow a vector, one element at a time, to watch how its size and capacity change. Then we grow a vector rapidly, only to watch the critical points where it reallocates its elements.

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

using index = vector<int>::size_type;

void show(const vector<int> & v)
{	cout << "size: " << v.size() <<" capacity: " << v.capacity() << endl; }

int main()
{
	vector<int> v;
	for (index i = 0; i != 100; ++i, v.push_back(0))
		show(v);
	cout << string(50, '-') << endl;
	v.clear();
	v.shrink_to_fit();
	for (index i = 0; i != 20; ++i, v.push_back(0)) {
		while (v.size() != v.capacity())
			v.push_back(0);
		show(v);
	}
	return 0;
}