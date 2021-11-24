// 18/02/23 = Fri

// Exercise 10.29: Write a program using stream iterators to read a text file into a vector of strings.

// To run, enter, for example, "a data\spring" or "a data\summer" in command prompt.

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool read(const string & filename, vector<string> & v)
{
	ifstream ifs(filename);
	if (!ifs) {
		cerr << "Error: Cannot open file!" << endl;
		return false;
	}
	istream_iterator<string> isit(ifs), isend;
	copy(isit, isend, back_inserter(v));
	ifs.close();
	return true;
}

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return -1;
	}
	vector<string> v;
	if (read(argv[1], v)) {
		ostream_iterator<string> osit(cout, " ");
		copy(v.cbegin(), v.cend(), osit);
		return 0;
	}
	else
		return -1;
}



