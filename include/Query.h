// 18/03/19 = Mon

// Header for Query class hierarchy

#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"
#include <memory>
#include <string>

class Query_base
{
protected:
	using lino = TextQuery::lino;
	virtual ~Query_base() = default;
private:
	// private pure virtuals
	virtual QueryResult eval(const TextQuery &) const = 0;
	virtual std::string rep() const = 0;
friend class Query;
};

// interface class that hides Query_base inheritane hierarchy
class Query
{
	std::shared_ptr<Query_base> qptr;
public:
	Query(const std::string &);
	QueryResult eval(const TextQuery & tq) const
	{
		#ifdef DEBUG_EVAL
			std::clog << "Query::eval()" << std::endl;
		#endif
		return qptr->eval(tq);
	}
	std::string rep() const
	{
		#ifdef DEBUG_REP
			std::clog << "Query::rep()" << std::endl;
		#endif
		return qptr->rep();
	}
private:
	Query(std::shared_ptr<Query_base> qptr) : qptr(qptr)
	{
		#ifdef DEBUG_CTOR
			std::clog << "Query(shared_ptr<Query_base>)" << std::endl;
		#endif
	}
friend Query operator~(const Query &);
friend Query operator&(const Query &, const Query &);
friend Query operator|(const Query &, const Query &);
};

class WordQuery : public Query_base
{
	std::string w;
private:
	WordQuery(const std::string & w) : w(w)
	{
		#ifdef DEBUG_CTOR
			std::clog << "WordQuery(const string &)\t (\"" << w << "\")" << std::endl;
		#endif
	}
	virtual QueryResult eval(const TextQuery & tq) const override
	{
		#ifdef DEBUG_EVAL
			std::clog << "WordQuery::eval()\t (\"" << w << "\")" << std::endl;
		#endif
		return tq.query(w);
	}
	virtual std::string rep() const override
	{
		#ifdef DEBUG_REP
			std::clog << "WordQuery::rep()\t (\"" << w << "\")" << std::endl;
		#endif
		return w;
	}
friend class Query;
};

class NotQuery : public Query_base
{
	Query q;
private:
	NotQuery(const Query & q) : q(q)
	{
		#ifdef DEBUG_CTOR
			std::clog << "NotQuery(const Query &)" << std::endl;
		#endif
	}
	virtual QueryResult eval(const TextQuery &) const override;
	virtual std::string rep() const override
	{
		#ifdef DEBUG_REP
			std::clog << "NotQuery::rep()" << std::endl;
		#endif
		return "~(" + q.rep() + ")";
	}
friend Query operator~(const Query &);
};

class BinaryQuery : public Query_base
{
protected:
	Query l, r;
	std::string op;
protected:
	BinaryQuery(const Query & l, const Query & r, std::string op)
		: l(l), r(r), op(op)
	{
		#ifdef DEBUG_CTOR
			std::clog << "BinaryQuery(const Query &, const Query &, string)" << std::endl;
		#endif
	}
	virtual std::string rep() const override
	{
		#ifdef DEBUG_REP
			std::clog << "BinaryQuery::rep()" << std::endl;
		#endif
		return "(" + l.rep() + " " + op + " " + r.rep() + ")";
	}
};

class AndQuery : public BinaryQuery
{
private:
	AndQuery(const Query & l, const Query & r) : BinaryQuery(l, r, "&")
	{
		#ifdef DEBUG_CTOR
			std::clog << "AndQuery(const Query &, const Query &)" << std::endl;
		#endif
	}
	virtual QueryResult eval(const TextQuery &) const override;
friend Query operator&(const Query &, const Query &);
};

class OrQuery : public BinaryQuery
{
private:
	OrQuery(const Query & l, const Query & r) : BinaryQuery(l, r, "|")
	{
		#ifdef DEBUG_CTOR
			std::clog << "OrQuery(const Query &, const Query &)" << std::endl;
		#endif
	}
	virtual QueryResult eval(const TextQuery &) const override;
friend Query operator|(const Query &, const Query &);
};

Query operator~(const Query &);
Query operator&(const Query &, const Query &);
Query operator|(const Query &, const Query &);

#endif