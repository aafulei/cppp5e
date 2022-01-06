// 18/01/23 = Mon
// 18/02/21 = Wed: rewrite

// Exercise 10.11: Write a program that uses stable_sort and isShorter to sort a vector passed to your version of elimDups. Print the vector to verify that your program is correct.

// Modified from lp-10-09.cpp

// Sort a vector of strings in the ascending order of length. If two strings have the same length, then sort alphabetically. Duplicates are removed.

// To run, enter, for example, "a <data\how" or "a <data\summer" in command prompt.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;
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

template<typename E>
bool isShorter(const E & e1, const E & e2)
{
	return e1.size() < e2.size();
}

template<typename C>
void elimDups(C & c)
{
	sort(c.begin(), c.end());
	auto unique_end = unique(c.begin(), c.end());
	c.erase(unique_end, c.end());
}

template<typename C>
void process(C & c)
{
	read(cin, c);
	print(c);
	elimDups(c);
	stable_sort(c.begin(), c.end(), isShorter<typename C::value_type>); // add
	print(c);
}

int main()
{
	vector<string> v;
	process(v);
	return 0;
}