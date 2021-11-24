// 18/03/01 = Thu: build upon lp-12-02-03.cpp
// 18/03/04 = Sun: own version of StrBlob for lp-13-25-26.cpp
// 18/03/10 = Sat: an rvalue reference version of push_back for lp-13-55.cpp
// 18/03/12 = Mon: equality and inequality operators for lp-14-16.cpp
// 18/03/12 = Mon: integrate with StrBlobPtr
// 18/03/12 = Mon: (c)begin/(c)end member functions
// 18/03/13 = Tue: operator[], friend operator<<

// Header for StrBlob class

// The copy behavior of StrBlob is pointer-like (see page 455), unless VALUE_LIKE is defined, in which case it is value-like (see Exercise 13.25).

// The relationship between StrBlob and StrBlobPtr is:
// 1. StrBlobPtr is dependent on StrBlob, but not the other way round.
// 2. Whenever StrBlobPtr is used, we must also supply the full definition of StrBlob (StrBlob.h and StrBlob.cpp).
// 3. When StrBlob is used, however, it is possible that we do not need to provide StrBlobPtr.
// 4. It is for this reason that we put the implementation of (c)begin/(c)end member functions in StrBlobPtr.cpp, not in StrBlob.cpp. When these member functions are needed, we must also supply StrBlobPtr.

#ifndef STRBLOB_H
#define STRBLOB_H

#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
public:
	using string = std::string;
	using svec = std::vector<std::string>;
	using size_type = std::vector<std::string>::size_type;
	using initializer = std::initializer_list<std::string>;
private:
	std::shared_ptr<svec> sptr;
public:
	StrBlob();
	StrBlob(initializer);
#ifdef VALUE_LIKE
	StrBlob(const StrBlob &);
	StrBlob & operator=(const StrBlob &);
#endif
	long use_count() const;
	bool empty() const;
	size_type size() const;
	StrBlobPtr begin();
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr cbegin() const;
	StrBlobPtr end();
	ConstStrBlobPtr end() const;
	ConstStrBlobPtr cend() const;
	string & front();
	const string & front() const;
	string & back();
	const string & back() const;
	string & operator[](size_type);
	const string & operator[](size_type) const;
	string & at(size_type);
	const string & at(size_type) const;
	void push_back(const string &);
	void push_back(string &&);
	void pop_back();
private:
	void check(const string &, size_type pos = 0) const;
friend class StrBlobPtr;
friend class ConstStrBlobPtr;
friend bool operator==(const StrBlob &, const StrBlob &);
friend bool operator!=(const StrBlob &, const StrBlob &);
friend std::ostream & operator<<(std::ostream &, const StrBlob &);
};

#endif