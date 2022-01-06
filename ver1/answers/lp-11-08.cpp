// 18/02/13 = Tue
// 18/02/24 = Sat: construct and assign to istream_iterator for reading

// Exercise 11.8: Write a program that stores the excluded words in a vector instead of in a set. What are the advantages to using a set?

// Answer: A set is always ordered. Given the amount of insertions and erasures is large, the cost may be considerable for a vector.

// To run, enter, for example, "a <data\moon" or "a <data\gatsby" in command prompt.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>
// define WORDS_TO_EXCLUDE, a macro for a filename which is a string literal
#include "include\exclude.h"

using namespace std;

int main()
{
	// prepare words to exclude
	ifstream ifs(WORDS_TO_EXCLUDE);
	if (!ifs)
		throw runtime_error("Cannot open file \"" WORDS_TO_EXCLUDE "\"!");
	istream_iterator<string> isit(ifs), isend;
	vector<string> vex(isit, isend);
	set<string> sex(vex.cbegin(), vex.cend());
	ifs.close();	// don't forget to close

	// count words to exclude
	unsigned vc = 0, sc = 0;
	isit = istream_iterator<string>(cin);	// isit can be assigned
	// alternatively:
	// isit = cin;
	for (string word; isit != isend; ) {
		word = *isit++;
		if (find(vex.begin(), vex.end(), word) != vex.end())
			++vc;
		if (sex.find(word) != sex.end())
			++sc;
	}
	cout << "Count words to exclude using a vector: " << vc << endl;
	cout << "Count words to exclude using a set: " << sc << endl;

	return 0;
}