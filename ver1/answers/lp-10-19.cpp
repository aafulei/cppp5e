// 18/02/21 = Wed

// Exercise 10.19: Rewrite the previous exercise to use stable_partition, which like stable_sort maintains the original element order in the paritioned sequence.

// Exercise 10.18: Rewrite biggies to use partition instead of find_if. We described the partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).

// Exercise 10.16: Write your own version of the biggies function using lambdas.

// biggies() takes a vector of string and a size. It prints out all the strings in the vector that have the same or longer size than the given size. To this aim, we do not have to sort.

// Modified from lp-10-18.cpp
// Merely:
// auto p = stable_partition(...);

// To run, enter, for example, "a 4 <data\fox" in command prompt. Compare the result with that of lp-10-18.cpp using the same argument and input.

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

void biggies( vector<string> & v, vector<string>::size_type sz)
{
	auto p = stable_partition(v.begin(), v.end(),	// stable partition
			[sz](const string & s)
			{	return s.size() >= sz; });
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