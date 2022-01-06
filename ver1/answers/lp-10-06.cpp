// 18/01/23 = Mon
// 18/02/21 = Wed: a templatized read()

// Exercise 10.6: Using fill_n, write a program to set a sequence of int values to 0.

// To run, enter, for example, "a <data\digits" in command prompt.

#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::fill_n;
using std::istream;
using std::vector;

template <typename C>
void read(istream & is, C & c)
{
	for (typename C::value_type e; is >> e; c.push_back(e))
		;
}

template <typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

void process(vector<int> & v)
{
	read(cin, v);
	print(v);
	fill_n(v.begin(), v.size(), 0);
	print(v);
}

int main()
{
	vector<int> v;
	process(v);
	return 0;
}