// 18/02/26 = Mon

// Exercise 11.38: Rewrite the word-counting (§ 11.1, p. 421) and word- transformation (§ 11.3.6, p. 440) programs to use an unordered_map.

// Exercise 11.3: Write your own version of the word-counting program.

// Exercise 11.4: Extend your program to ignore case and punctuation. For example, “example.” “example,” and “Example” should all increment the same counter.

// We rewrite the word-counting program in this file.

// Modified from lp-11-03-04.cpp
// Merely:
// #include <unordered_map>
// #include <unordered_set>
// #include "include\duexcel.h"
// unordered_map<string, size_t> count;
// unordered_set<string> exclude;

// Count words, excluding the words that appear in a set (e.g. "the"), and print out the high-frequency words (count >= 10 by default). 

// To run, enter, for example, "a <data\moon" or "a 100 <data\gatsby" in command prompt.

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <stdexcept>
#include <string>
#include <unordered_map>
// define WORDS_TO_EXCLUDE, a macro for a filename which is a string literal
// "duexcel" is a shuffule of the word "exclude"
#include "include\duexcel.h"

using namespace std;

string standardize(const string & word, const unordered_set<string> & exclude)
{
	string s = word;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	s.erase(remove_if(s.begin(), s.end(), [](char c){ return !isalpha(c); }),
			s.end());
	if (exclude.find(s) != exclude.end())
		s.clear();
	return s;
}

void process(unordered_map<string, size_t> & count, size_t min_count)
{
	ifstream ifs(WORDS_TO_EXCLUDE);
	if (!ifs)
		throw runtime_error("Cannot open file \"" WORDS_TO_EXCLUDE "\"!");
	istream_iterator<string> isit(ifs), isend;
	unordered_set<string> exclude(isit, isend);
	ifs.close();
	for (string word, s; cin >> word; ) {
		s = standardize(word, exclude);
		if (!s.empty())
			++count[s];
	}
	for (const auto & c : count) 
		if (c.second >= min_count)
			cout << c.first << (c.first.size() >= 8 ? "\t" : "\t\t")
				 << c.second << endl;
}

int main(int argc, char ** argv)
{
	unordered_map<string, size_t> count;
	size_t min_count = (argc == 1) ? 10u : atoi(argv[1]);
	process(count, min_count);
	return 0;
}