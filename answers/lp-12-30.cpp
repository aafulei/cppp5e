// 18/03/01 = Thu

// Exercise 12.30: Define your own versions of the TextQuery and QueryResult classes and execute the runQueries function from § 12.3.1 (p. 486).

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
using lsha = shared_ptr<set<vector<string>::size_type>>;
using tsha = shared_ptr<vector<string>>;

string & standardize(string & s)
{
	transform(s.cbegin(), s.cend(), s.begin(), ::tolower);
	s.erase(remove_if(s.begin(), s.end(), [](char c){ return !isalpha(c); }),
			s.end());
	return s;
}

class QueryResult
{
	string aim;
	tsha txt;
	lsha loc;
public:
	QueryResult(string, tsha, lsha);
friend	// move in-class print() out of class and make it a friend
	ostream & print(ostream &, const QueryResult &);
};

class TextQuery
{
	tsha txt;
	map<string, set<lino>> index;
public:
	TextQuery(istream &);
	QueryResult query(const string &) const;
};

QueryResult::
QueryResult(string a, tsha t, lsha l) : aim(a), txt(t), loc(l) {}

TextQuery::
TextQuery(istream & is) : txt(make_shared<vector<string>>())
{
	lino n = 0;
	for (string line; getline(is, line); txt->push_back(line), ++n) {
		istringstream iss(line);
		for (string word; iss >> word; )
			index[standardize(word)].insert(n);
	}
	clog << "Number of lines = " << n << endl;
	clog << "Number of distinct words = " << index.size() << endl;
}

QueryResult
TextQuery::
query(const string & word) const
{
	string aim(word);
	standardize(aim);
	auto it = index.find(aim);
	return QueryResult(aim, txt, 
		(it == index.end() ?
		make_shared<set<lino>>() :
		make_shared<set<lino>>(it->second)));
}

// print() out of class to be consistent with textbook
ostream & print(ostream & os, const QueryResult & qr)
{
	lino count = 0;
	cin.ignore(256, '\n');
	for (auto n : *qr.loc) {
		os << "(line " << n + 1 << ") " << "\t"
		   << qr.txt->at(n) << endl;
		if (++count % 100 == 0) {
			cout << "Press Enter to continue or B to break ...... ";
			if (cin.get() != '\n') {
				cin.ignore(256, '\n');
				count = qr.loc->size();
				break;
			}
		}
	}
	os << "\"" << qr.aim << "\""  << " occurs " << count
	   << (count > 1 ? " times." : " time.") << endl;
	return os;
}

// taken from textbook as required
void runQueries(ifstream & infile)
{
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return -1;
	}
	ifstream ifs(argv[1]);
	if (!ifs) {
		cerr << "Error: Cannot open file!" << endl;
		return -1;
	}
	runQueries(ifs);
	ifs.close();
	return 0;
}