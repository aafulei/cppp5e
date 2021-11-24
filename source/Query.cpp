// 18/03/19 = Mon

// Source code for Query class hierarchy

#include "..\include\Query.h"
#include "..\include\TextQuery.h"
#include <algorithm>				// for std::set_intersection
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>

using namespace std;
using text = vector<string>;
using lino = text::size_type;
using lset = set<lino>;
using lsha = shared_ptr<lset>;
using tsha = shared_ptr<text>;
using wmap = map<string, lset>;

QueryResult Query_base::eval(const TextQuery &) const
{
	#ifdef DEBUG_EVAL
		clog << "Query_base::eval()" << endl;
	#endif
}

string Query_base::rep() const
{
	#ifdef DEBUG_REP
		clog << "Query_base::rep()" << endl;
	#endif
}

Query::Query(const string & w) : qptr(new WordQuery(w))
{
	#ifdef DEBUG_CTOR
		clog <<	"Query(const string &)" << endl;
	#endif
}

QueryResult OrQuery::eval(const TextQuery & t) const
{
	#ifdef DEBUG_EVAL
		clog << "OrQuery::eval()" << endl;
	#endif
	auto left = l.eval(t), right = r.eval(t);
	auto result = make_shared<lset>(left.begin(), left.end());
	result->insert(right.begin(), right.end());
	return QueryResult(rep(), left.get_file(), result);
}

QueryResult AndQuery::eval(const TextQuery & t) const
{
	#ifdef DEBUG_EVAL
		clog << "AndQuery::eval()" << endl;
	#endif
	auto left = l.eval(t), right = r.eval(t);
	auto result = make_shared<lset>(left.begin(), left.end());
	set_intersection(left.begin(), left.end(), right.begin(), right.end(),
					inserter(*result, result->begin()));
	return QueryResult(rep(), left.get_file(), result);
}

QueryResult NotQuery::eval(const TextQuery & t) const
{
	auto res = q.eval(t);
	auto result = make_shared<lset>();
	auto b = res.begin(), e = res.end();
	auto sz = res.get_file()->size();
	for (size_t n = 0; n != sz; ++n) {
		if (b == e || *b != n)
			result->insert(n);
		else if (b != e)
			++b;
	}
	return QueryResult(rep(), res.get_file(), result);
}

ostream & operator<<(ostream & os, const Query & q)
{
	return os << q.rep();
}

Query operator~(const Query & q)
{
	// implicitly calls private constructor: Query(shared_ptr<Query_base>)
	return shared_ptr<Query_base>(new NotQuery(q));
}

Query operator&(const Query & l, const Query & r)
{
	return shared_ptr<Query_base>(new AndQuery(l, r));
}

Query operator|(const Query & l, const Query & r)
{
	return shared_ptr<Query_base>(new OrQuery(l, r));
}
