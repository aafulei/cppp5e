// 18/02/22 = Thu

// Exercise 10.25: In the exercises for § 10.3.2 (p. 392) you wrote a version of biggies that uses partition. Rewrite that function to use check_size and bind.

// Exercise 10.18: Rewrite biggies to use partition instead of find_if. We described the partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).

// Modified from lp-10-18.cpp
// Merely:
// auto p = partition(v.begin(), v.end(), bind(check_size, _1, sz));

// To run, enter, for example, "a <data\how" or "a 4 <data\fox" in command prompt.

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;
using std::atoi;
using std::bind;
using std::cin;
using std::cout;
using std::endl;
using std::for_each;
using std::partition;
using std::string;
using std::vector;

bool check_size(const string & s, string::size_type sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> & v, vector<string>::size_type sz)
{
	auto p = partition(v.begin(), v.end(), bind(check_size, _1, sz)); // bind
	for_each(v.begin(), p, [](const string & s){ cout << s << " "; });
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