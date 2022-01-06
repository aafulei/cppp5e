// 18/01/23 = Mon
// 18/02/21 = Wed: rewrite to read from cin

// Exercise 10.13: The library defines an algorithm named partition that takes a predicate and partitions the container so that values for which the predicate is true appear in the first part and those for which the predicate is false appear in the second part. The algorithm returns an iterator just past the last element for which the predicate returned true. Write a function that takes a string and returns a bool indicating whether the string has five characters or more. Use that function to partition words. Print the elements that have five or more characters.

// To run, enter, for example, "a <data\how" or "a <data\fox" in command prompt.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::partition;
using std::string;
using std::vector;

bool is_long(const string & s)
{
	return s.size() >= 5;
}

// call partition() in print_long(), so vector<string> cannot be const
void print_long(vector<string> & v)
{
	for (auto it  = v.cbegin();
		// cannot write partition(v.cbegin(), v.cend(), is_long);
		it != partition(v.begin(), v.end(), is_long);
		++it)
		cout << *it << " ";
}

void process(vector<string> & v)
{
	for (string s; cin >> s; v.push_back(s))
		cout << s << " ";
	cout << endl;
	print_long(v);
}

int main()
{
	vector<string> text;
	process(text);
	return 0;
}