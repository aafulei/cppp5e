// 18/02/21 = Wed

// Exercise 10.16: Write your own version of the biggies function using lambdas.

// biggies() takes a vector of string and a size. It prints out all the strings in the vector that have the same or longer size than the given size. To this aim, we do not have to sort.

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

void biggies(const vector<string> & v, vector<string>::size_type sz)
{
	auto f = [sz] (const string & s) -> void
	{
		if (s.size() >= sz)
			cout << s << " ";
	};
	for_each(v.begin(), v.end(), f);
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