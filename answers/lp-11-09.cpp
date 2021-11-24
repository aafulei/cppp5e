// 18/02/13 = Tue
// 18/02/24 = Sat: evident speed-up by restructuring the functions
// In the 18/02/13 version, I inefficiently set up a exclude-word set every time a word is examined. By moving that part out of the function, the program becomes much faster.

// Exercise 11.9: Define a map that associates words with a list of line numbers on which the word might occur.

// Print line numbers of high-frequency words  (count >= 10 by default), excluding words, such as "the" and "that", that appear in a given list.

// To run, enter, for example, "a <data\moon" or "a 100 <data\gatsby" in command prompt.

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
// define WORDS_TO_EXCLUDE, a macro for a filename which is a string literal
#include "include\exclude.h"

using namespace std;

// Consider an index at the end of a book. Given a word, you get the pages where it appear.
using index = map<string, list<size_t>>;

void standardize(string & s, const set<string> & exclude)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	s.erase(remove_if(s.begin(), s.end(), [](char c){ return !isalpha(c); }),
			s.end());
	if (exclude.find(s) != exclude.end())
		s.clear();
}

void process(index & ind)
{
	// prepare words to exclude
	ifstream ifs(WORDS_TO_EXCLUDE);
	if (!ifs)
		throw runtime_error("Cannot open file \"" WORDS_TO_EXCLUDE "\"!");
	istream_iterator<string> isit(ifs), isend;
	set<string> exclude(isit, isend);
	ifs.close();
	// construct an index for standardized words
	size_t num = 1;
	for (string line; getline(cin, line); ++num) {
		istringstream iss(line);
		for (string word; iss >> word; ) {
			standardize(word, exclude);
			if (!word.empty())
				ind[word].push_back(num);
		}
	}
}

void print(index::value_type elem)
{
	cout << elem.first << (elem.first.size() >= 8 ? "\t" : "\t\t");
	for (const auto & e : elem.second)
		cout << e << " ";
}

void print(index & ind, size_t min_count)
{
	// print high-frequency words
	for (const auto & elem : ind)
		if (elem.second.size() >= min_count) {
			print(elem);
			cout << endl;
		}
}

int main(int argc, char ** argv)
{
	index ind;
	size_t min_count = (argc == 1) ? 10u : atoi(argv[1]);
	process(ind);
	print(ind, min_count);
	return 0;
}