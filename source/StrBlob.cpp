// 18/03/01 = Thu: build upon lp-12-02-03.cpp
// 18/03/04 = Sun: own version of StrBlob for lp-13-25-26.cpp
// 18/03/10 = Sat: an rvalue reference version of push_back for lp-13-55.cpp
// 18/03/12 = Mon: equality and inequality operators for lp-14-16.cpp
// 18/03/12 = Mon: integrate with StrBlobPtr
// 18/03/13 = Tue: operator[], check for at(), operator<<

// Source code for StrBlob class

// The copy behavior of StrBlob is pointer-like (see page 455), unless VALUE_LIKE is defined, in which case it is value-like (see Exercise 13.25).

// We put the implementation of (c)begin/(c)end member functions in StrBlobPtr.cpp, not in StrBlob.cpp. When these member functions are needed, we must also supply StrBlobPtr.

// StrBlob and StrBlobPtr are designed to be safer than StrVec. That is, we do not hesitate to perform range checks to guard against possible out-of-range errors, even for overloaded operators like [] and *(dereference).

// for lp-12-32.cpp, lp-13-25-26.cpp, lp-13-55.cpp, lp-14-16.cpp, lp-14-18.cpp, lp-14-26.cpp

#include "..\include\StrBlob.h"
#include "..\include\StrBlobPtr.h"
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
using svec = vector<string>;
using size_type = vector<string>::size_type;
using initializer = std::initializer_list<std::string>;

StrBlob::StrBlob() : sptr(make_shared<svec>()) {}

StrBlob::StrBlob(initializer i) : sptr(make_shared<svec>(i)) {}

#ifdef VALUE_LIKE
// add: copy constructor for lp-13-26.cpp
StrBlob::StrBlob(const StrBlob & sb) : sptr(make_shared<svec>(*sb.sptr)) {}

// add: copy-assignment operator for lp-13-26.cpp
StrBlob & StrBlob::operator=(const StrBlob & sb)
{
	*sptr = *sb.sptr;
}
#endif

// add: for test for lp-13-26.cpp
long StrBlob::use_count() const
{
	return sptr.use_count();
}

bool StrBlob::empty() const
{
	return sptr->empty();
}

size_type StrBlob::size() const
{
	return sptr->size();
}

string & StrBlob::front()
{	
	check("front() on empty StrBlob!");
	return sptr->front();
}

const string & StrBlob::front() const
{	
	check("front() on empty StrBlob!");
	return sptr->front();
}

string & StrBlob::back()
{	
	check("back() on empty StrBlob!");
	return sptr->back();
}

const string & StrBlob::back() const
{	
	check("back() on empty StrBlob!");
	return sptr->back();
}

// for efficiency and like a vector, we do not do any check
string & StrBlob::operator[](size_type n)
{
#ifdef DEBUG_CONST_OVERLOAD
	clog << "Call: non-const member function " << __func__ << endl;
#endif
	return sptr->at(n);
}

const string & StrBlob::operator[](size_type n) const
{
#ifdef DEBUG_CONST_OVERLOAD
	clog << "Call: const member function " << __func__ << endl;
#endif
	return sptr->at(n);
}

string & StrBlob::at(size_type n)
{
	check("at() wrong place of StrBlob", n);
	return sptr->at(n);
}

const string & StrBlob::at(size_type n) const
{
	check("at() wrong place of StrBlob", n);
	return sptr->at(n);
}

void StrBlob::push_back(const string & s)
{
#ifdef DEBUG_PUSH_BACK
	clog << "Call: ordinary version of push_back()" << endl;
#endif
	sptr->push_back(s);
}

// add: an rvalue reference version of push_back for lp-13-55.cpp
void StrBlob::push_back(string && s)
{
#ifdef DEBUG_PUSH_BACK
	clog << "Call: rvalue reference version of push_back()" << endl;
#endif
	// if you forgot std::move(), the rvalue reference version is meaningless
	sptr->push_back(std::move(s));
}

void StrBlob::pop_back()
{	
	check("pop_back() on empty StrBlob!");
	return sptr->pop_back();
}

// check that pos is valid in vector<string>
// by default, i = 0, which checks the vector is non-empty
void StrBlob::check(const string & msg, size_type pos) const
{
	if (pos >= size())
		throw out_of_range(msg);
}

bool operator==(const StrBlob & sb1, const StrBlob & sb2)
{
	return sb1.sptr == sb2.sptr;
}


bool operator!=(const StrBlob & sb1, const StrBlob & sb2)
{
	return !(sb1 == sb2);
}

ostream & operator<<(ostream & os, const StrBlob & sb)
{
	// Question: Can we write a range-for like for (const auto & s : sb)?
	// Answer: It depends on whether we've implemented operator++ and operator* for ConstStrBlobPtr. Had we done this, we would not need to declare operator<< as a friend of StrBlob.
	for (auto it = sb.sptr->cbegin(); it != sb.sptr->cend(); ++it)
		os << "\"" << *it << "\" ";
	return os;
}