// 18/02/28 = Wed

// Exercise 12.27: The TextQuery and QueryResult classes use only capabilities that we have already covered. Without looking ahead, write your own versions of these classes.

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
	ostream & print(ostream &) const;
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

ostream & 
QueryResult::
print(ostream & os) const
{
	lino count = 0;
	cin.ignore(256, '\n');
	for (auto n : *loc) {
		os << "(line " << n + 1 << ") " << "\t"
		   << txt->at(n) << endl << endl;
		if (++count % 100 == 0) {
			cout << "Press Enter to continue or B to break ...... " << endl;
			if (cin.get() != '\n') {
				cin.ignore(256, '\n');
				count = loc->size();
				break;
			}
		}
	}
	os << "\"" << aim << "\""  << " occurs " << count
	   << (count > 1 ? " times." : " time.") << endl;
	return os;
}

TextQuery::
TextQuery(istream & is) : txt(make_shared<vector<string>>())
{
	lino n = 0;
	for (string line; getline(is, line); txt->push_back(line), ++n) {
		istringstream iss(line);
		for (string word; iss >> word; )
			index[standardize(word)].insert(n);
	}
	clog << "Number of lines = " << n << endl << endl;
	clog << "Number of distinct words = " << index.size() << endl << endl;
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

bool process(const string & filename)
{
	ifstream ifs(filename);
	if (!ifs) {
		cerr << "Error: Cannot open file!" << endl;
		return false;
	}
	TextQuery tq(ifs);
	const string prompt = "Enter word to search or Q to quit: ";
	cout << prompt;
	for (string word; cin >> word && word != "Q" && word != "q";
		cout << prompt) {
		cout << endl;
		QueryResult result = tq.query(word);
		result.print(cout) << endl;
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