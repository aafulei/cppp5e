// 18/03/06 = Tue

// Exercise 13.42: Test your StrVec class by using it in place of the vector<string> in your TextQuery and QueryResult classes (§ 12.3, p. 484).

// Modified from lp-12-32.cpp, with StrBlob replaced with StrVec

// With StrVec.h included, whose implementation is in StrVec.cpp, which is modified from lp-13-39-40.cpp

// To run, enter, for example, "a data\gatsby" in command prompt.

#include "include\StrVec.h"
#include "source\StrVec.cpp"

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
using lino = StrVec::size_type;
using lsha = shared_ptr<set<StrVec::size_type>>;
using tsha = shared_ptr<StrVec>;

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
friend
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
TextQuery(istream & is) : txt(make_shared<StrVec>())
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

void runQueries(ifstream & ifs)
{
	TextQuery tq(ifs);
	const string prompt = "Enter word to search or Q to quit: ";
	cout << prompt;
	for (string word; cin >> word && word != "Q" && word != "q";
		cout << prompt) {
		QueryResult result = tq.query(word);
		print(cout, result) << endl;
	}
	ifs.close();
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