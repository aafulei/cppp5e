// 18/03/05 = Mon
// 18/03/06 = Tue: redo
// 18/03/07 = Wed: move constructor and move-assignment operator
// 18/03/12 = Mon: equality and inequality operators
// 18/03/13 = Tue: operator[]

// Source code for StrVec class

// for lp-13-39-40.cpp, lp-13-42.cpp, lp-13-49.cpp, lp-14-16.cpp, lp-14-18.cpp, lp-14-26.cpp

#include "..\include\StrVec.h"
#include <algorithm>		// for std::copy, std::lexicographical_compare
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>

using namespace std;
using size_type = std::size_t;

// We must define and initialize each static data member out of the class.
allocator<string> StrVec::a;

StrVec::StrVec()
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

StrVec::StrVec(initializer_list<string> il)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	auto range = alloc_and_copy(il.begin(), il.end());
	b = range.first;
	e = f = range.second;
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

StrVec::StrVec(const StrVec & sv)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	auto range = alloc_and_copy(sv.b, sv.e);
	b = range.first;
	e = f = range.second;
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

StrVec::StrVec(StrVec && sv) noexcept : b(sv.b), e(sv.e), f(sv.f)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
#ifdef DEBUG_MOVE
	clog << "Call: move constructor" << endl;
#endif
	// setting pointers in sv to nullptr is crucial
	sv.b = sv.e = sv.f = nullptr;
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

StrVec & StrVec::operator=(const StrVec & sv)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	if (this != &sv) {
		auto len = sv.size();
		if (capacity() < len) {
			auto range = alloc_and_copy(sv.b, sv.e);
			free();
			b = range.first;
			e = f = range.second;
		}
		else {
			copy(sv.b, sv.e, b);
			e = b + len;
		}
	}
#ifdef DEBUG_SELF_ASSIGN
	else {
		clog << "Note: guarded against self-(copy-)assignment" << endl;
	}
#endif
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
	return *this;
}

StrVec & StrVec::operator=(StrVec && sv) noexcept
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
#ifdef DEBUG_MOVE
	clog << "Call: move-assignment operator" << endl;
#endif
	// The guard against self-assignment is crucial.
	// Without it, self-assignment will invalidate itself, and cause memory leaks.
	if (this != &sv) {
		b = sv.b;
		e = sv.e;
		f = sv.f;
		// setting pointers in sv to nullptr is crucial
		sv.b = sv.e = sv.f = nullptr;
	}
#ifdef DEBUG_SELF_ASSIGN
	else {
		clog << "Note: guarded against self-(move-)assignment" << endl;
	}
#endif
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
	return *this;
}

StrVec::~StrVec()
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	free();
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

// for Exercise 14.23
StrVec & StrVec::operator=(initializer_list<string> il)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	auto len = il.size();
	if (capacity() < len) {
#ifdef DEBUG_ALLOC_OR_NOT	// for Exercise 14.23
	clog << "Note: Memory allocated"  << endl;
#endif
		// There is no cbegin/cend for an initializer_list
		auto range = alloc_and_copy(il.begin(), il.end());
		free();
		b = range.first;
		e = f = range.second;
	}
	else {
#ifdef DEBUG_ALLOC_OR_NOT	// for Exercise 14.23
	clog << "Note: No need for memory allocation"  << endl;
#endif
		copy(il.begin(), il.end(), b);
		e = b + len;
	}
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
	return *this;
}

// Exercise 14.26: for efficiency and like a vector, we do not do any check
string & StrVec::operator[](size_type n)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
#ifdef DEBUG_CONST_OVERLOAD
	clog << "Call: non-const member function " << __func__ << endl;
#endif
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
	return b[n];
}

// Exercise 14.26: for efficiency and like a vector, we do not do any check	
const string & StrVec::operator[](size_type n) const
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
#ifdef DEBUG_CONST_OVERLOAD
	clog << "Call: const member function " << __func__ << endl;
#endif
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
	return b[n];
}

string & StrVec::at(size_type n)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
#ifdef DEBUG_CONST_OVERLOAD
	clog << "Call: non-const member function " << __func__ << endl;
#endif
	if (n >= size()) {
		string error = "n (which is " + to_string(n) + ") >= size (which is " + to_string(size()) + ")";
		throw out_of_range(error);
	}
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
	return b[n];
}

const string & StrVec::at(size_type n) const
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
#ifdef DEBUG_CONST_OVERLOAD
	clog << "Call: const member function " << __func__ << endl;
#endif
	if (n >= size()) {
		string error = "n (which is " + to_string(n) + ") >= size (which is " + to_string(size()) + ")";
		throw out_of_range(error);
	}
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
	return b[n];
}

void StrVec::push_back(const string & s)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	check_and_alloc();
	a.construct(e++, s);
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

void StrVec::reserve(size_type n)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	if (capacity() < n) {
		auto range = alloc_and_move(n, b, e);
		free();
		b = range.first;
		e = range.second;
		f = b + n;
	}
#ifdef DEBUG
	clog << "With: capacity = " << capacity() << endl;
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

void StrVec::resize(size_type n)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	if (n > size()) {
		reserve(n);
		auto p = e;
		e = b + n;
		while (p != e)
			a.construct(p++, "");
	}
	else {
		auto p = e;
		e = b + n;
		while (p != e)
			a.destroy(--p);
	}
#ifdef DEBUG
	clog << "With: size = " << size() << endl;
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

pair<string *, string *>
StrVec::alloc_and_copy(const string * sb, const string * se)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	// sb: source begin
	// se: source end
	// db: destination begin
	// de: destination end
	auto db = a.allocate(se - sb);
	auto de = uninitialized_copy(sb, se, db);
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
	return {db, de};
}

// sb and se must not be const string * in order to make move really happen
pair<string *, string *>
StrVec::alloc_and_move(size_type n, string * sb, string * se)
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	auto db = a.allocate(n);
	auto de = uninitialized_copy(make_move_iterator(sb),
								 make_move_iterator(se), db);
	// Alternatively: (since C++17)
	// auto de = uninitialized_move(sb, se, db);
	
	// no need to set sb = se = nullptr here -- it's the work of string's move constructor
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
	return {db, de};
}

void StrVec::check_and_alloc()
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	if (size() == capacity())
		reallocate();
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

void StrVec::reallocate()
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	auto n = (size() == 0) ? 1 : size() * 2;
	reserve(n);
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

void StrVec::free()
{
#ifdef DEBUG
	clog << "Call: " << __func__ << "()" << endl;
#endif
	if (b) {
		while (e != b)
			a.destroy(--e);
		// Alternatively:
		// Since the lambda is scope, there is no need to capture a, which is a static member.
		// for_each(reverse_iterator<string *>(e), reverse_iterator<string *>(b), [](string & s){ a.destroy(&s); });
		a.deallocate(b, capacity());
		b = e = f = nullptr;	// so that b will not be deallocated twice
	}
#ifdef DEBUG
	clog << "Exit: " << __func__ << "()" << endl;
#endif
}

ostream & operator<<(ostream & os, const StrVec & sv)
{
	for (const auto & s : sv)
		os << "\"" << s << "\" ";
	return os;
}

bool operator==(const StrVec & sv1, const StrVec & sv2)
{
	if (sv1.size() != sv2.size())
		return false;
	else
		for (auto it1 = sv1.cbegin(), it2 = sv2.cbegin();
			it1 != sv1.cend(); ++it1, ++it2)
			if (*it1 != *it2)
				return false;
	return true;
}

bool operator!=(const StrVec & sv1, const StrVec & sv2)
{
	return !(sv1 == sv2);
}

bool operator<(const StrVec & sv1, const StrVec & sv2)
{
	return lexicographical_compare(sv1.cbegin(), sv1.cend(),
								   sv2.cbegin(), sv2.cend());
}

bool operator>(const StrVec & sv1, const StrVec & sv2)
{
	return sv2 < sv1;
}

bool operator<=(const StrVec & sv1, const StrVec & sv2)
{
	return !(sv2 < sv1);
}

bool operator>=(const StrVec & sv1, const StrVec & sv2)
{
	return !(sv1 < sv2);
}