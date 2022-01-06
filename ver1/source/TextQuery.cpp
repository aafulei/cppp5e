// 18/03/19 = Mon: build upon lp-12-33.cpp
// 18/03/19 = Mon: #ifdef DEBUG to print numbers of lines, words to clog

// Source code for TextQuery and QueryResult classes

#include "..\include\TextQuery.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string & standardize(string & s)
{
	transform(s.cbegin(), s.cend(), s.begin(), ::tolower);
	s.erase(remove_if(s.begin(), s.end(), [](char c){ return !isalpha(c); }),
			s.end());
	return s;
}

TextQuery::TextQuery(istream & is) : txt(make_shared<text>())
{
	lino n = 0;
	for (string line; getline(is, line); txt->push_back(line), ++n) {
		istringstream iss(line);
		for (string word; iss >> word; )
			index[standardize(word)].insert(n);
	}
	#ifdef DEBUG
		clog << "Number of lines = " << n << endl;
		clog << "Number of distinct words = " << index.size() << endl;
	#endif
}

QueryResult TextQuery::query(const string & word) const
{
	string aim(word);
	standardize(aim);
	auto it = index.find(aim);
	return QueryResult(aim, txt, 
					(it == index.end() ?
					make_shared<lset>() : make_shared<lset>(it->second)));
}

ostream & operator<<(ostream & os, const QueryResult & qr)
{
	QueryResult::lino count = 0;
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
		cout << prompt)
		cout << tq.query(word) << endl;
	ifs.close();
}
