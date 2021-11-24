// 18/03/12 = Mon: build upon lp-12-22.cpp
// 18/03/12 = Mon: operators ==, !=
// 18/03/12 = Mon: integrate with StrBlob
// 18/03/12 = Mon: (c)begin/(c)end member functions for StrBlob
// 18/03/13 = Tue: operators ++/--, +=/-=, +/-, *(dereference), ->

// Source code for StrBlobPtr class and ConstBlobPtr class

// Question: Do I need to include StrBlob.h in StrBlobPtr.cpp?
// Answer: Yes, since Case 1 applies here.
// 1. If you have used the definition of StrBlob (e.g. sb.sptr where sb is a StrBlob), then the compiler needs to know the full definition of StrBlob.
// 2. If you have just used a pointer or a reference to StrBlob, then a forward class declaration is fine. Just write "class StrBlob;".

// We put the implementation of (c)begin/(c)end member functions of StrBlob in StrBlobPtr.cpp, not in StrBlob.cpp. See StrBlob.h for explanation.

// StrBlob and StrBlobPtr are designed to be safer than StrVec. That is, we do not hesitate to perform range checks to guard against possible out-of-range errors, even for overloaded operators like [] and *(dereference).

// for lp-12-22.cpp, lp-14-16.cpp, lp-14-18.cpp, lp-14-27-32.cpp

#include "..\include\StrBlob.h"
#include "..\include\StrBlobPtr.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

// Even if you have used "using" in class scope in header, you may still need to declare them here, consider:
// 
// shared_ptr<svec> StrBlobPtr::check(...)
// 
// The compiler does not know what "svec" is in the return type, because it has yet to see the class scope (StrBlobPtr::).

using namespace std;
using difference_type = std::vector<std::string>::difference_type;
using size_type = std::vector<std::string>::size_type;
using string = std::string;
using svec = std::vector<std::string>;

StrBlobPtr::
StrBlobPtr() : pos(0) {}

ConstStrBlobPtr::
ConstStrBlobPtr() : pos(0) {}

StrBlobPtr::
StrBlobPtr(StrBlob & sb, size_type pos)
	: wptr(sb.sptr), pos(pos) {}

ConstStrBlobPtr::
ConstStrBlobPtr(const StrBlob & sb, size_type pos)
	: wptr(sb.sptr), pos(pos) {}

string & StrBlobPtr::derefer() const
{
	auto sptr = check("Dereference past the end!");
	return (*sptr)[pos];
}

// sptr is const, so the string is const, too
const string & ConstStrBlobPtr::derefer() const
{
	auto sptr = check("Dereference past the end!");
	return (*sptr)[pos];
}

string & StrBlobPtr::operator*() const
{
	auto sptr = check("Dereference past the end!");
	return (*sptr)[pos];
}

const string & ConstStrBlobPtr::operator*() const
{
	auto sptr = check("Dereference past the end!");
	return (*sptr)[pos];
}

string * StrBlobPtr::operator->() const
{
	return &(this->operator*());
}

const string * ConstStrBlobPtr::operator->() const
{
	return &(this->operator*());
}

StrBlobPtr & StrBlobPtr::increment()
{
	check("Increment past the end!");
	++pos;
	return *this;
}

ConstStrBlobPtr & ConstStrBlobPtr::increment()
{
	check("Increment past the end!");
	++pos;
	return *this;
}

StrBlobPtr & StrBlobPtr::operator++()
{
	check("Increment past the end!");
	++pos;
	return *this;
}

ConstStrBlobPtr & ConstStrBlobPtr::operator++()
{
	check("Increment past the end!");
	++pos;
	return *this;
}

StrBlobPtr & StrBlobPtr::operator--()
{
	--pos;
	check("Decrement past the begin!");
	return *this;
}

ConstStrBlobPtr & ConstStrBlobPtr::operator--()
{
	--pos;
	check("Decrement past the begin!");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr old(*this);
	++*this;
	return old;
}

ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
	ConstStrBlobPtr old(*this);
	++*this;
	return old;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr old(*this);
	--*this;
	return old;
}

ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
	ConstStrBlobPtr old(*this);
	--*this;
	return old;
}

StrBlobPtr & StrBlobPtr::operator+=(difference_type d)
{
	if (d > 0)
		do
			++*this;
		while (--d != 0);
	else if (d < 0)
		do
			--*this;
		while (++d != 0);
	return *this;
}

ConstStrBlobPtr & ConstStrBlobPtr::operator+=(difference_type d)
{
	if (d > 0)
		do
			++*this;
		while (--d != 0);
	else if (d < 0)
		do
			--*this;
		while (++d != 0);
	return *this;
}

StrBlobPtr & StrBlobPtr::operator-=(difference_type d)
{
	return *this += (-d);
}

ConstStrBlobPtr & ConstStrBlobPtr::operator-=(difference_type d)
{
	return *this += (-d);
}

StrBlobPtr StrBlobPtr::operator+(difference_type d)
{
	StrBlobPtr p(*this);
	return p += d;
}

ConstStrBlobPtr ConstStrBlobPtr::operator+(difference_type d)
{
	ConstStrBlobPtr p(*this);
	return p += d;
}

StrBlobPtr StrBlobPtr::operator-(difference_type d)
{
	return *this + (-d);
}

ConstStrBlobPtr ConstStrBlobPtr::operator-(difference_type d)
{
	return *this + (-d);
}

difference_type StrBlobPtr::operator-(const StrBlobPtr & p)
{
	if (wptr.lock() != p.wptr.lock())
		throw invalid_argument("Refer to different StrBlob!");
	return pos - p.pos;
}

difference_type ConstStrBlobPtr::operator-(const ConstStrBlobPtr & p)
{
	if (wptr.lock() != p.wptr.lock())
		throw invalid_argument("Refer to different StrBlob!");
	return pos - p.pos;
}

shared_ptr<svec> StrBlobPtr::check(const string & msg, size_type pos) const
{
	auto sptr = wptr.lock();
	if (!sptr)
		throw runtime_error("Unbound StrBlobPtr!");
	if (pos >= sptr->size())
		throw out_of_range(msg);
	return sptr;
}

const shared_ptr<svec> ConstStrBlobPtr::check(const string & msg, size_type pos) const
{
	auto sptr = wptr.lock();
	if (!sptr)
		throw runtime_error("Unbound StrBlobPtr!");
	if (pos >= sptr->size())
		throw out_of_range(msg);
	return sptr;
}

bool operator==(const StrBlobPtr & p1, const StrBlobPtr & p2)
{
	return p1.pos == p2.pos && p1.wptr.lock() == p2.wptr.lock();
}

bool operator==(const ConstStrBlobPtr & p1, const ConstStrBlobPtr & p2)
{
	return p1.pos == p2.pos && p1.wptr.lock() == p2.wptr.lock();
}

bool operator!=(const StrBlobPtr & p1, const StrBlobPtr & p2)
{
	return !(p1 == p2);
}

bool operator!=(const ConstStrBlobPtr & p1, const ConstStrBlobPtr & p2)
{
	return !(p1 == p2);
}

bool operator<(const StrBlobPtr & p1, const StrBlobPtr & p2)
{
	if (p1.wptr.lock() != p2.wptr.lock())
		throw invalid_argument("Refer to different StrBlob!");
	return p1.pos < p2.pos;
}

bool operator<(const ConstStrBlobPtr & p1, const ConstStrBlobPtr & p2)
{
	if (p1.wptr.lock() != p2.wptr.lock())
		throw invalid_argument("Refer to different StrBlob!");
	return p1.pos < p2.pos;
}

bool operator>(const StrBlobPtr & p1, const StrBlobPtr & p2)
{
	return p2 < p1;
}

bool operator>(const ConstStrBlobPtr & p1, const ConstStrBlobPtr & p2)
{
	return p2 < p1;
}

bool operator<=(const StrBlobPtr & p1, const StrBlobPtr & p2)
{
	return !(p2 < p1);
}

bool operator<=(const ConstStrBlobPtr & p1, const ConstStrBlobPtr & p2)
{
	return !(p2 < p1);
}

bool operator>=(const StrBlobPtr & p1, const StrBlobPtr & p2)
{
	return !(p1 < p2);
}

bool operator>=(const ConstStrBlobPtr & p1, const ConstStrBlobPtr & p2)
{
	return !(p1 < p2);
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::begin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, sptr->size());
}

ConstStrBlobPtr StrBlob::end() const
{
	return ConstStrBlobPtr(*this, sptr->size());
}

ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, sptr->size());
}
