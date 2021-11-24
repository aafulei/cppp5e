// 18/03/06 = Tue
// 18/03/08 = Thu: move constructor and move-assignment operator
// 18/03/12 = Mon: equality and inequality operators

// Source code for String class

// Modified from StrVec.cpp for lp-13-39-40.cpp

// for lp-13-44.cpp, lp-13-47-48.cpp, lp-13-49.cpp, lp-14-16.cpp, lp-14-18.cpp

#include "..\include\String.h"
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

allocator<char> String::a;

String::String()
{
	auto range = alloc(initial_capacity);
	b = e = range.first;
	f = range.second;
}

String::String(const char * cs)
{
#ifdef DEBUG_COPY	// for Exercise 13.47
	clog << "Call: constructor on (const char *) \"" << cs << "\"" << endl;
#endif
	auto len = strlen(cs);
	auto range = alloc_and_copy(cs, cs + len);
	b = range.first;
	e = f = range.second;
}

String::String(const String & s)
{
#ifdef DEBUG_COPY	// for Exercise 13.47
	clog << "Call: copy constructor on (const String &) \"" << s << "\"" << endl;
#endif
	auto range = alloc_and_copy(s.b, s.e);
	b = range.first;
	e = f = range.second;
}

#ifndef DISABLE_MOVE
String::String(String && s) noexcept : b(s.b), e(s.e), f(s.f)
{
#ifdef DEBUG_MOVE	// for Exercise 13.49
	// Reading s is still legal at this moment. Why?
	clog << "Call: move constructor on (String &&) \"" << s << "\"" << endl;
#endif
	s.b = s.e = s.f = nullptr;
}
#endif

String & String::operator=(const String & s)
{
#ifdef DEBUG_COPY	// for Exercise 13.47
	clog << "Call: copy-assignment operator on (const String &) \"" << s << "\"" << endl;
#endif
	if (this != &s) {
		auto len = s.size();
		if (capacity() < len) {
			auto range = alloc_and_copy(s.b, s.e);
			free();
			b = range.first;
			e = f = range.second;
		}
		else {
			// Don't use strcpy() here. This copy is between two char arrays, not between two C-strings. What's the difference?
			copy(s.b, s.e, b);
			e = b + len;
		}
	}
#ifdef DEBUG_SELF_ASSIGN
	else {
		clog << "Note: guarded against self-(copy-)assignment" << endl;
	}
#endif
	return *this;
}

#ifndef DISABLE_MOVE
String & String::operator=(String && s) noexcept
{
#ifdef DEBUG_MOVE	// for Exercise 13.49
	// Reading s is still legal at this moment. Why?
	clog << "Call: move-assignment operator on (String &&) \"" << s << "\"" << endl;
#endif
	// The guard against self-assignment is crucial.
	// Without it, self-assignment will invalidate itself, and cause memory leaks.
	if (this != &s) {
		b = s.b;
		e = s.e;
		f = s.f;
		// setting pointers in s to nullptr is crucial
		s.b = s.e = s.f = nullptr;
	}
#ifdef DEBUG_SELF_ASSIGN
	else {
		clog << "Note: guarded against self-(move-)assignment" << endl;
	}
#endif
	return *this;
}
#endif

String::~String()
{
	free();
}

void String::reserve(size_t n)
{
	if (capacity() < n) {
		auto range = alloc_and_copy(n, b, e);
		free();
		b = range.first;
		e = range.second;
		f = b + n;
	}
}

// requests the String to reduce its capacity to fit its size
// a String is guaranteed to have initial_capacity
void String::shrink_to_fit()
{
	if (size() < initial_capacity)
		a.deallocate(b + initial_capacity, capacity() - initial_capacity);
	else
		a.deallocate(e, capacity() - size());
}

void String::resize(size_t n)
{
	if (n > size()) {
		reserve(n);
		auto p = e;
		e = b + n;
		while (p != e)
			a.construct(p++, '\0');
	}
	else {
		auto p = e;
		e = b + n;
		while (p != e)
			a.destroy(--p);
	}
}

void String::clear()
{
	while (e != b)
		a.destroy(--e);
}

pair<char *, char *>
String::alloc(size_t n)
{
	auto db = a.allocate(n);
	auto df = db + n;
	return {db, df};
}

pair<char *, char *>
String::alloc_and_copy(size_t n, const char * sb, const char * se)
{
	auto db = a.allocate(n);
	auto de = uninitialized_copy(sb, se, db);
	return {db, de};
}

pair<char *, char *>
String::alloc_and_copy(const char * sb, const char * se)
{
	return alloc_and_copy(se - sb, sb, se);
}

void String::free()
{
	if (b) {
		while (e != b)
			a.destroy(--e);
		a.deallocate(b, capacity());
		b = e = f = nullptr;
	}
}

ostream & operator<<(ostream & os, const String & s)
{
	for (auto c : s)
		os << c;
	return os;
}

bool operator==(const String & s1, const String & s2)
{
	if (s1.size() != s2.size())
		return false;
	else
		for (auto it1 = s1.cbegin(), it2 = s2.cbegin();
			it1 != s1.cend(); ++it1, ++it2)
			if (*it1 != *it2)
				return false;
	return true;
}

bool operator!=(const String & s1, const String & s2)
{
	return !(s1 == s2);
}

bool operator<(const String & s1, const String & s2)
{
	return lexicographical_compare(s1.cbegin(), s1.cend(),
								   s2.cbegin(), s2.cend());
}

bool operator>(const String & s1, const String & s2)
{
	return s2 < s1;
}

bool operator<=(const String & s1, const String & s2)
{
	return !(s2 < s1);
}

bool operator>=(const String & s1, const String & s2)
{
	return !(s1 < s2);
}
