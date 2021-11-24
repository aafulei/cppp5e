// 18/03/19 = Mon: build upon lp-12-33.cpp
// 18/03/25 = Sun: default constructor for TextQuery
// 18/03/25 = Sun: private => protected: TextQuery data members, type aliases

// Header for TextQuery and QueryResult classes

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

class QueryResult;

class TextQuery
{
protected:
	using string = std::string;
	using text = std::vector<string>;
	using lino = text::size_type;
	using lset = std::set<lino>;
	using lsha = std::shared_ptr<lset>;
	using tsha = std::shared_ptr<text>;
	using wmap = std::map<string, lset>;
protected:
	tsha txt;
	wmap index;
public:
	TextQuery() = default;
	TextQuery(std::istream &);
	QueryResult query(const string &) const;
friend class Query_base;
};

class QueryResult
{
	using string = std::string;
	using text = std::vector<string>;
	using lino = text::size_type;
	using lset = std::set<lino>;
	using lsha = std::shared_ptr<lset>;
	using tsha = std::shared_ptr<text>;
	using wmap = std::map<string, lset>;

	string aim;
	tsha txt;
	lsha loc;
public:
	QueryResult(string a, tsha t, lsha l) : aim(a), txt(t), loc(l) {}
	lset::iterator begin()				{ return loc->begin(); }
	lset::const_iterator begin() const 	{ return loc->begin(); }
	lset::const_iterator cbegin()		{ return loc->cbegin(); }
	lset::iterator end() 				{ return loc->end(); }
	lset::const_iterator end() const	{ return loc->end(); }
	lset::const_iterator cend()			{ return loc->cend(); }
	tsha get_file()						{ return txt; }
friend std::ostream & operator<<(std::ostream &, const QueryResult &);
};

void runQueries(std::ifstream & ifs);

#endif