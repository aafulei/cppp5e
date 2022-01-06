// 18/02/22 = Thu

// Exercise 10.24: Use bind and check_size to find the first element in a vector of ints that has a value greater than the length of a specified string value.

// Reads a vector of ints from cin. Prints the first int that is greater than the length of a string specified in the command line. If unspecified, that string is "command".

// To run, enter, for example, "a good <data\digits" in command prompt.

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;
using std::bind;
using std::cin;
using std::cout;
using std::endl;
using std::find_if_not;
using std::string;
using std::vector;

bool check_size(const string & s, string::size_type sz)
{
    return s.size() >= sz;
}

void process(vector<int> & v, const string & s)
{
	for (int i; cin >> i; v.push_back(i))
		cout << i << " ";
	cout << endl;
	
	// Question: How to directly negate the predicate supplied by bind?
	// Answer:
	// 0. nested bind(): ... bind(loigcal_not<bool>(), bind(...))
	// 1. since C++17: ... not_fn(bind(...)) ...
	// 2. deprecated in C++17: ... not1<function<bool(int)>>(bind(...)) ...

	auto it = find_if_not(v.cbegin(), v.cend(), bind(check_size, s, _1));
	if (it == v.cend())
		cout << "No element in the vector "
				"has a value greater than the length of \""
			 << s << "\"." << endl;
	else
		cout << "The first element that "
				"has a value greater than the length of \""
			 << s << "\" is " << *it << " at position "
			 << (it - v.cbegin()) << "." << endl;
}

int main(int argc, char ** argv)
{
	vector<int> v;
	string s = (argc == 1) ? "command" : argv[1];
	process(v, s);
	return 0;
}