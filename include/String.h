// 18/03/06 = Tue
// 18/03/08 = Thu: move constructor and move-assignment operator
// 18/03/12 = Mon: cbegin(), cend(), equality and inequality operators
// 18/03/13 = Tue: operator[]

// Header for String class

// Dynamic Memory Allocation Policy: A String is guaranteed to have a minimum capacity of 15. This is the only difference in dynamic memory allocation, compared with the StrVec class for lp-13-39-40.cpp.

#ifndef STRING_H
#define STRING_H

// Three states:
// 1. DEBUG_COPY: for lp-13-47-48.cpp, with copy, no move, with debug info;
// 2. DEBUG_MOVE: for lp-13-49.cpp, with copy and move, with debug info;
// 3. Otherwise : with copy and move, no debug info.

#ifdef DEBUG_COPY
#define DISABLE_MOVE
#endif

#ifdef DEBUG_MOVE
#define DEBUG_COPY
#endif

#include <cstddef>		// for std::size_t
#include <memory>		// for std::allocator
#include <utility>		// for std::pair

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
#ifndef DISABLE_MOVE
	String(String &&) noexcept;
#endif
	String & operator=(const String &);
#ifndef DISABLE_MOVE
	String & operator=(String &&) noexcept;
#endif
	~String();
	char & operator[](std::size_t n)				{ return b[n];	}
	const char & operator[](std::size_t n) const	{ return b[n];	}
	char * begin()									{ return b; 	}
	const char * begin() const						{ return b; 	}
	const char * cbegin() const
	{
		return const_cast<const char *>(b);
	}
	char * end()									{ return e; 	}
	const char * end() const						{ return e; 	}
	const char * cend() const
	{
		return const_cast<const char *>(e);
	}
	bool empty() const 								{ return b == e;}
	std::size_t size() const						{ return e - b; }
	std::size_t capacity() const					{ return f - b; }
	void reserve(std::size_t);
	void shrink_to_fit();
	void resize(std::size_t);
	void clear();
private:
	std::pair<char *, char *>alloc(std::size_t);
	std::pair<char *, char *>alloc_and_copy(std::size_t n, const char *, const char *);
	std::pair<char *, char *>alloc_and_copy(const char *, const char *);
	void free();
// We don't have declare as friends operators <<, ==, < and the like.
};

#endif