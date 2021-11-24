// 18/03/12 = Mon: build upon lp-12-22.cpp
// 18/03/12 = Mon: operators ==, !=
// 18/03/12 = Mon: integrate with StrBlob
// 18/03/13 = Tue: operators ++/--, +=/-=, +/-, *(dereference), ->

// Header for StrBlobPtr class and ConstBlobPtr class

// Question: Do I need to include StrBlob.h in StrBlobPtr.h?
// Answer: No, since Case 2 applies here.
// 1. If you have used the definition of StrBlob (e.g. sb.sptr where sb is a StrBlob), then the compiler needs to know the full definition of StrBlob.
// 2. If you have just used a pointer or a reference to StrBlob, then a forward class declaration is fine. Just write "class StrBlob;".

#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlob;

class StrBlobPtr
{
public:
	using difference_type = std::vector<std::string>::difference_type;
	using size_type = std::vector<std::string>::size_type;
	using string = std::string;
	using svec = std::vector<std::string>;
private:
	std::weak_ptr<svec> wptr;
	size_type pos;
public:
	StrBlobPtr();
	StrBlobPtr(StrBlob &, size_type pos = 0);
	string & derefer() const;
	string & operator*() const;
	string * operator->() const;
	StrBlobPtr & increment();
	StrBlobPtr & operator++();
	StrBlobPtr & operator--();
	StrBlobPtr   operator++(int);
	StrBlobPtr   operator--(int);
	StrBlobPtr & operator+=(difference_type);
	StrBlobPtr & operator-=(difference_type);
	StrBlobPtr   operator+(difference_type);
	StrBlobPtr   operator-(difference_type);
	difference_type operator-(const StrBlobPtr &);
private:
	std::shared_ptr<svec> check(const string &, size_type pos = 0) const;
friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
};

class ConstStrBlobPtr
{
public:
	using difference_type = std::vector<std::string>::difference_type;
	using size_type = std::vector<std::string>::size_type;
	using string = std::string;
	using svec = std::vector<std::string>;
private:
	std::weak_ptr<svec> wptr;
	size_type pos;
public:
	ConstStrBlobPtr();
	ConstStrBlobPtr(const StrBlob &, size_type pos = 0);
	const string & derefer() const;
	const string & operator*() const;
	const string * operator->() const;
	ConstStrBlobPtr & increment();
	ConstStrBlobPtr & operator++();
	ConstStrBlobPtr & operator--();
	ConstStrBlobPtr   operator++(int);
	ConstStrBlobPtr   operator--(int);
	ConstStrBlobPtr & operator+=(difference_type);
	ConstStrBlobPtr & operator-=(difference_type);
	ConstStrBlobPtr   operator+(difference_type);
	ConstStrBlobPtr   operator-(difference_type);
	difference_type operator-(const ConstStrBlobPtr &);
private:
	const std::shared_ptr<svec> check(const string &, size_type pos = 0) const;
friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
};

#endif
