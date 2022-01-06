// 18/03/11 = Sun

// Modified from lp-13-47-48.cpp

// Demonstrate the difference when the move operations are declared/defined with/without "noexcept".

// prints what happens when pushing back "A" to "Z" to a vector of String.

// reallocation policy: minimum capacity = 15u, doubles when it's full.

// notice the difference when pushing back "B", "C", "E" , "I", "Q", when reallocation happens.

// To compile without noexcept:
// g++ lp-13-noexcept.cpp -D WITHOUT_NOEXCEPT

// To compile with noexcept:
// g++ lp-13-noexcept.cpp -D WITH_NOEXCEPT

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#ifndef WITHOUT_NOEXCEPT
#define WITH_NOEXCEPT
#endif

class String
{
	char * b = nullptr;
	char * e = nullptr;
	char * f = nullptr;
	static std::allocator<char> a;
	static constexpr std::size_t initial_capacity = 15u;
public:
	String();
	String(const char * cs);
	String(const String &);
#ifdef WITHOUT_NOEXCEPT
	String(String &&);
#endif
#ifdef WITH_NOEXCEPT
	String(String &&) noexcept;
#endif
	String & operator=(const String &);
#ifdef WITHOUT_NOEXCEPT
	String & operator=(String &&);
#endif
#ifdef WITH_NOEXCEPT
	String & operator=(String &&) noexcept;
#endif
	~String();
	char * begin()					{ return b; 	}
	const char * begin() const		{ return b; 	}
	char * end()					{ return e; 	}
	const char * end() const		{ return e; 	}
	bool empty() const 				{ return b == e;}
	std::size_t size() const		{ return e - b; }
	std::size_t capacity() const	{ return f - b; }
	void reserve(std::size_t);
	void shrink_to_fit();
	void resize(std::size_t);
	void clear();
private:
	std::pair<char *, char *>alloc(std::size_t);
	std::pair<char *, char *>alloc_and_copy(std::size_t n, const char *, const char *);
	std::pair<char *, char *>alloc_and_copy(const char *, const char *);
	void free();
friend
	std::ostream & operator<<(std::ostream &, const String &);
};

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
	clog << "Call: constructor on (const char *) \"" << cs << "\"" << endl;
	auto len = strlen(cs);
	auto range = alloc_and_copy(cs, cs + len);
	b = range.first;
	e = f = range.second;
}

String::String(const String & s)
{
	clog << "Call: copy constructor on (const String &) \"" << s << "\"" << endl;
	auto range = alloc_and_copy(s.b, s.e);
	b = range.first;
	e = f = range.second;
}

#ifdef WITHOUT_NOEXCEPT
String::String(String && s) : b(s.b), e(s.e), f(s.f)
#endif
#ifdef WITH_NOEXCEPT
String::String(String && s) noexcept : b(s.b), e(s.e), f(s.f)
#endif
{
	clog << "Call: move constructor on (String &&) \"" << s << "\"" << endl;
	s.b = s.e = s.f = nullptr;
}

String & String::operator=(const String & s)
{
	clog << "Call: copy-assignment operator on (const String &) \"" << s << "\"" << endl;
	if (this != &s) {
		auto len = s.size();
		if (capacity() < len) {
			auto range = alloc_and_copy(s.b, s.e);
			free();
			b = range.first;
			e = f = range.second;
		}
		else {
			copy(s.b, s.e, b);
			e = b + len;
		}
	}
	return *this;
}

#ifdef WITHOUT_NOEXCEPT
String & String::operator=(String && s) 
#endif
#ifdef WITH_NOEXCEPT
String & String::operator=(String && s) noexcept
#endif
{
	clog << "Call: move-assignment operator on (String &&) \"" << s << "\"" << endl;
	if (this != &s) {
		b = s.b;
		e = s.e;
		f = s.f;
		s.b = s.e = s.f = nullptr;
	}
	return *this;
}

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

int main()
{
	vector<String> v;
	for (char a[2] = "A"; a[0] != 'Z' + 1; ++a[0]) {
		cout << string(50, '-') << endl;
		cout << "capacity = " << v.capacity() << endl;
		v.push_back(a);
		cout << "capacity = " << v.capacity() << endl;
	}
	return 0;
}

/* ---------- postscript ----------

Without noexcept, copy constructor is called when reallocation.

With noexcept, move constructor is called when reallocation.

----------------------------------- */