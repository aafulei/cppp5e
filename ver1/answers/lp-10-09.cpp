// 18/01/23 = Mon
// 18/02/21 = Wed: a templatized read(), elimDups() and process()

// Exercise 10.9: Implement your own version of elimDups. Test your program by printing the vector after you read the input, after the call to unique, and after the call to erase.

// Sort a vector of strings in alphabetical order, removing duplicates.

// To run, enter, for example, "a <data\how" or "a <data\summer" in command prompt.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::sort;
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
	print(c);
}

int main()
{
	vector<string> v;
	process(v);
	return 0;
}