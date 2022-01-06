// 18/02/22 = Thu

// Exercise 10.27: In addition to unique (§ 10.2.3, p. 384), the library defines function named unique_copy that takes a third iterator denoting a destination into which to copy the unique elements. Write a program that uses unique_copy to copy the unique elements from a vector into an initially empty list.

// To run, enter, for example, "a <data\digits" in command prompt.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

// The textbook has mentioned the usage of "using namespace" in 10.3.
// For simplicity, from this exercise on, we will be "using namespace std;".
// Though clearly we understand that this practice is not recommended.
using namespace std;

template<typename C>
void read(istream & is, C & c)
{
	for (typename C::value_type e; is >> e; c.push_back(e))
		;
}

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

void process(vector<int> & vec, list<int> & lst)
{
	read(cin, vec);
	unique_copy(vec.cbegin(), vec.cend(), back_inserter(lst));
	print(vec);
	print(lst);
}

int main()
{
	vector<int> vec;
	list<int> lst;
	process(vec, lst);
	return 0;
}