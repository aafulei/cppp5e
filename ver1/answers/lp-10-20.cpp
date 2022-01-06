// 18/02/22 = Thu

// Exercise 10.20: The library defines an algorithm named count_if. Like find_if, this function takes a pair of iterators denoting an input range and a predicate that it applies to each element in the given range. count_if returns a count of how often the predicate is true. Use count_if to rewrite the portion of our program that counted how many words are greater than length 6.

// Read strings from cin. Print out the number of strings having a length greater than 6.

// To run, enter, for example, "a <data\summer" in command prompt.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void process(vector<string> & v)
{
	for (string s; cin >> s; v.push_back(s))
		;
	cout << count_if(v.begin(), v.end(),
					[](const string & s)
					{	return s.size() > 6; })
		 << endl;
}

int main()
{
	vector<string> v;
	process(v);
	return 0;
}