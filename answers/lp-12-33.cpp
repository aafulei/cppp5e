// 18/03/01 = Thu

// Exercise 12.33: In Chapter 15 we’ll extend our query system and will need some additional members in the QueryResult class. Add members named begin and end that return iterators into the set of line numbers returned by a given query, and a member named get_file that returns a shared_ptr to the file in the QueryResult object.

// Modified from lp-12-32.cpp, with StrBlob replaced with vector<string>

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
using lset = set<vector<string>::size_type>;	// add
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
	lset::iterator begin()	{	return loc->begin(); }	// add
	lset::iterator end() 	{	return loc->end(); }	// add
	tsha get_file()			{	return txt; }			// add
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