// 18/02/21 = Wed

// Exercise 10.18: Rewrite biggies to use partition instead of find_if. We described the partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).

// Exercise 10.16: Write your own version of the biggies function using lambdas.

// biggies() takes a vector of string and a size. It prints out all the strings in the vector that have the same or longer size than the given size. To this aim, we do not have to sort.

// Modified from lp-10-16.cpp

// To run, enter, for example, "a <data\how" or "a 4 <data\fox" in command prompt.

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using std::atoi;
using std::cin;
using std::cout;
using std::endl;
using std::for_each;
using std::string;
using std::vector;
using std::partition;

// remove const for v
void biggies(vector<string> & v, vector<string>::size_type sz)
{
	// partition
	auto p = partition(v.begin(), v.end(),
			[sz](const string & s)
			{	return s.size() >= sz; });
	// print
	for_each(v.begin(), p,
		[](const string & s)
		{	cout << s << " "; });
}

void process(vector<string> & v, vector<string>::size_type sz)
{
	for (string s; cin >> s; v.push_back(s))
		cout << s << " ";
	cout << endl;
	biggies(v, sz);
}

int main(int argc, char ** argv)
{
	vector<string> v;
	vector<string>::size_type sz = (argc == 1) ? 5u : atoi(argv[1]);
	process(v, sz);
	return 0;
}