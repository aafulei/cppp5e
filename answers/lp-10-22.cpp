// 18/02/22 = Thu

// Exercise 10.22: Rewrite the program to count words of size 6 or less using functions in place of the lambdas.

// Modified from lp-10-20.cpp

// Read strings from cin. Print out the number of strings having a length of 6 or less.

// To run, enter, for example, "a <data\summer" in command prompt.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bind;
using namespace std::placeholders;


bool is_short(const string & s, string::size_type sz)
{
	return s.size() <= sz;
}

void process(vector<string> & v)
{
	for (string s; cin >> s; v.push_back(s))
		;
	// bind is_short() to a new callable
	cout << count_if(v.begin(), v.end(), bind(is_short, _1, 6)) << endl;
}

int main()
{
	vector<string> v;
	process(v);
	return 0;
}