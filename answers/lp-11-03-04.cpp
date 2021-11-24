// 18/02/13 = Tue
// 18/02/24 = Sat: use istream_iterator to read directly to set

// Exercise 11.3: Write your own version of the word-counting program.

// Exercise 11.4: Extend your program to ignore case and punctuation. For example, “example.” “example,” and “Example” should all increment the same counter.

// Count words, excluding the words that appear in a set (e.g. "the"), and print out the high-frequency words (count >= 10 by default). 

// To run, enter, for example, "a <data\moon" or "a 100 <data\gatsby" in command prompt.

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
// define WORDS_TO_EXCLUDE, a macro for a filename which is a string literal
#include "include\exclude.h"

using namespace std;

string standardize(const string & word, const set<string> & exclude)
{
	// convert all letters to lowercase
	// ::tolower is different from std::tolower
	string s = word;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	// alternatively:
	// transform(s.begin(), s.end(), s.begin(),
	// 			[](char c)	// return c; cannot be omitted
	// 			{
	// 				if (c >= 'A' && c <= 'Z')
	// 					c += 'a' - 'A';
	// 				return c;
	// 			});

	// remove all non-alphabetical characters
	// remove_if(b, e, p) removes all the elements for which predicate p is true from the range [b, e), and returns a one-past-the-end iterator for the new end of the range.
	s.erase(remove_if(s.begin(), s.end(), [](char c){ return !isalpha(c); }),
			s.end());

	// exclude words
	if (exclude.find(s) != exclude.end())
		s.clear();
	return s;
}

void process(map<string, size_t> & count, size_t min_count)
{
	// prepare words to exclude
	ifstream ifs(WORDS_TO_EXCLUDE);
	if (!ifs)
		throw runtime_error("Cannot open file \"" WORDS_TO_EXCLUDE "\"!");
	istream_iterator<string> isit(ifs), isend;
	set<string> exclude(isit, isend);
	ifs.close();	// don't forget to close

	// standardize words
	for (string word, s; cin >> word; ) {
		s = standardize(word, exclude);
		// s might be empty if it was, say, a number
		if (!s.empty())
			++count[s];
	}

	// print words whose frequency >= min_count
	for (const auto & c : count) 
		if (c.second >= min_count)
			cout << c.first << (c.first.size() >= 8 ? "\t" : "\t\t")
				 << c.second << endl;
}

int main(int argc, char ** argv)
{
	map<string, size_t> count;
	size_t min_count = (argc == 1) ? 10u : atoi(argv[1]);
	process(count, min_count);
	return 0;
}