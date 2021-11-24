// 18/03/14 = Wed

// Exercise 14.38:  Write a class that tests whether the length of a given string matches a given bound. Use that object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.

// Exercise 14.39: Revise the previous program to report the count of words that are of sizes 1 through 9 and 10 or more.

// To run, enter, for example, "a data\moon" or "a data\gatsby" in command prompt.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <functional>
#include <string>

using namespace std;

using size_type = string::size_type;

class Is_Length_Within
{
	size_type l;
	size_type u;
public:
	Is_Length_Within(size_type l, size_type u) : l(l), u(u) {}
	bool operator()(const string & s) const
	{
		return l <= s.size() && s.size() <= u;
	}
};

auto count_within(ifstream & ifs, size_type l, size_type u)
{
	istream_iterator<string> isit(ifs), isend;
	Is_Length_Within within(l, u);
	return count_if(isit, isend, within);
}

bool process(const string & filename, size_type l, size_type u)
{
	ifstream ifs(filename);
	if (!ifs) {
		cerr << "Error: Cannot open file!" << endl;
		return false;
	}
	auto n = count_within(ifs, l, u);
	string be = n > 1 ? "are " : "is ";
	string form = n > 1 ? "s " : " ";
	cout << "There " << be << n << " word" << form
		 << "whose length" << form << be << "within the range of "
		 << "[" << l << ", " << u << "]." << endl;
	ifs.close();
	return true;
}

void report(const string & filename)
{
	for (auto u = 9u; u != 15u && process(filename, 1u, u); ++u)
		;
}

void manipulate(const string & filename)
{
	size_type l, u;
	do {
		cout << "Enter your lower bound: ";
		cin >> l;
		cout << "Enter your upper bound: ";
		cin >> u;
	}
	while (cin && process(filename, l, u));
}

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return -1;
	}
	string filename = argv[1];
	report(filename);
	manipulate(filename);
	return 0;
}