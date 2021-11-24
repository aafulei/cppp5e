// 18/02/25 = Sun

// Exercise 11.33: Implement your own version of the word-transformation program.

// Read two files:
// 1. rules to map acronyms to full words
// 2. a text that may contain acronyms
// Print rules. Print original text. Print text expanded.

// To run, enter, for example, "a data\acronyms data\chat" in command prompt.

#include <algorithm>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>

using namespace std;
using namespace std::placeholders;

map<string, string> prepare(ifstream & ifs)
{
	map<string, string> m;
	for (string line, word, acronym, full; getline(ifs, line); full.clear()) {
		istringstream iss(line);
		iss >> acronym;
		for (bool first_word = true; iss >> word; first_word = false)
			full += (first_word ? "" : " ") + word;
		// in case of duplicated keys, take the first value inserted
		if (!acronym.empty() && !full.empty())
			m.insert({acronym, full});
		// alternatively:
		// in case of duplicated keys, take the last value inserted
		// m[acronym] = full;	
	}
	ifs.close();
	return m;
}

void print(const map<string, string> & m)
{
	for (const auto e : m)
		cout << "[" << e.first << "]\t" << e.second << endl;
}

string expand(const string & s, const map<string, string> & rules)
{
	string t;
	transform(s.cbegin(), s.cend(), back_inserter(t), ::toupper);
	auto e = find_if(t.crbegin(), t.crend(), 
					[](char c){return isalpha(c);}).base();
	auto it = rules.find(string(t.cbegin(), e));
	return it == rules.cend() ? s : it->second + string(e, t.cend());
}

bool process(const string & rfile, const string & tfile)
{
	// prepare rules to map acronyms to full words
	ifstream rfs(rfile);
	if (!rfs) {
		cerr << "Error: Cannot open file \"" + rfile + "\"!" << endl;
		return false;
	}
	auto rules = prepare(rfs);
	rfs.close();
	cout << string(100, '-') << endl;
	print(rules);
	cout << string(100, '-') << endl;
	// use mapping rules to expand text
	ifstream tfs(tfile);
	if (!tfs) {
		cerr << "Error: Cannot open file \"" + tfile + "\"!" << endl;
		return false;
	}
	ostringstream oss;
	for (string line; getline(tfs, line); cout << line << endl) {
		istringstream iss(line);
		istream_iterator<string> isit(iss), isend;
		ostream_iterator<string> osit(oss, " ");
		transform(isit, isend, osit, bind(expand, _1, rules));
		oss << endl;
	}
	tfs.close();
	cout << string(100, '-') << endl;
	cout << oss.str();
	return true;	
}

int main(int argc, char ** argv)
{
	if (argc < 3) {
		cerr << "Error: Format is [command][rules][text]!" << endl;
		return -1;
	}
	return process(argv[1], argv[2]) ? 0 : -1;
}