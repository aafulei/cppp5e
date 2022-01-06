// 18/01/23 = Mon

// Exercise 10.2: Repeat the previous program, but read values into a list of strings.

// Exercise 10.1: The algorithm header defines a function named count that, like find, takes a pair of iterators and a value. count returns a count of how often that value appears. Read a sequence of ints into a vector and print the count of how many elements have a given value.

// Modified from lp-10-01.cpp

// To run, enter, for example, "a <data\digits" in command prompt.

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::istream;
using std::list;
using std::string;
using std::to_string;

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

int main()
{
	list<string> lst;	// modified
	read(cin, lst);
	print(lst);
	for (int i = 0; i != 10; ++i)
		// modified
		cout << i << ": " << count(lst.cbegin(), lst.cend(), to_string(i)) << endl;
	return 0;
}