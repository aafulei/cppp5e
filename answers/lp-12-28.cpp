// 18/03/01 = Thu

// Exercise 12.28: Write a program to implement text queries without defining classes to manage the data. Your program should take a file and interact with a user to query for words in that file. Use vector, map, and set containers to hold the data for the file and to generate the results for the queries.

// Modified from lp-12-27.cpp

// To run, enter, for example, "a data\gatsby" in command prompt.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using lino = vector<string>::size_type;
using lset = set<vector<string>::size_type>;
using smap = map<string, set<vector<string>::size_type>>;
using svec = vector<string>;

string & standardize(string & s)
{
	transform(s.cbegin(), s.cend(), s.begin(), ::tolower);
	s.erase(remove_if(s.begin(), s.end(), [](char c){ return !isalpha(c); }),
			s.end());
	return s;
}

smap make_index(istream & is, svec & txt)
{
	lino n = 0;
	smap index;
	for (string line; getline(is, line); txt.push_back(line), ++n) {
		istringstream iss(line);
		for (string word; iss >> word; )
			index[standardize(word)].insert(n);
	}
	clog << "Number of lines = " << n << endl << endl;
	clog << "Number of distinct words = " << index.size() << endl << endl;
	return index;
}

void search(const svec & txt, const string & word, const smap & index)
{
	string aim(word);
	standardize(aim);
	auto it = index.find(aim);
	if (it == index.cend())
		return;
	else {
		lset loc = it->second;
		lino count = 0;
		cin.ignore(256, '\n');
		for (auto n : loc) {
			cout << "(line " << n + 1 << ") " << "\t"
			   << txt[n] << endl << endl;
			if (++count % 100 == 0) {
				cout << "Press Enter to continue or B to break ...... " << endl;
				if (cin.get() != '\n') {
					cin.ignore(256, '\n');
					count = loc.size();
					break;
				}
			}
		}
		cout << "\"" << aim << "\""  << " occurs " << count
		     << (count > 1 ? " times." : " time.") << endl << endl;
	}
}

bool process(const string & filename)
{
	ifstream ifs(filename);
	if (!ifs) {
		cerr << "Error: Cannot open file!" << endl;
		return false;
	}
	svec txt;
	auto index = make_index(ifs, txt);
	const string prompt = "Enter word to search or Q to quit: ";
	cout << prompt;
	for (string word; cin >> word && word != "Q" && word != "q" ;
		cout << prompt) {
		cout << endl;
		search(txt, word, index);
	}
	ifs.close();
	return true;
}

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return -1;
	}
	return process(argv[1]) ? 0 : -1;
}