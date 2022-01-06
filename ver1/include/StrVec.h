// 18/03/05 = Mon
// 18/03/06 = Tue: redo
// 18/03/07 = Wed: move constructor and move-assignment operator
// 18/03/12 = Mon: cbegin(), cend(), equality and inequality operators
// 18/03/13 = Tue: operator[]
// 18/03/28 = Wed: emplace_back()

// Header for StrVec class

#ifndef STRVEC_H
#define STRVEC_H

#include <cstddef>				// for std::size_t
#include <initializer_list>		// for std::initializer_list
#include <iostream>				// for std::ostream
#include <memory>				// for std::allocator
#include <string>				// for std::string
#include <utility>				// for std::pair, std::forward

class StrVec
{
	std::string * b = nullptr;
	std::string * e = nullptr;
	std::string * f = nullptr;
	static std::allocator<std::string> a;
public:
	using size_type = std::size_t;
	StrVec();
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec &);
	StrVec(StrVec &&) noexcept;
	StrVec & operator=(const StrVec &);
	StrVec & operator=(StrVec &&) noexcept;
	~StrVec();
	StrVec & operator=(std::initializer_list<std::string>);	// Exercise 14.23
	std::string & operator[](size_type);					// Exercise 14.26
	const std::string & operator[](size_type) const;		// Exercise 14.26
	std::string & at(size_type);
	const std::string & at(size_type) const;
	size_type size() const			{ return e - b; }
	size_type capacity() const 		{ return f - b; }
	std::string * begin() 				{ return b; }
	const std::string * begin() const 	{ return b; }
	const std::string * cbegin() const
	{
		return const_cast<const std::string *>(b);
	}
	std::string * end() 				{ return e; }
	const std::string * end() const 	{ return e; }
	const std::string * cend() const
	{
		return const_cast<const std::string *>(e);
	}
	void push_back(const std::string &);
	template<typename ... T> void emplace_back(T && ...);	// Ex 16.58
	void reserve(size_type);
	void resize(size_type);
private:
	std::pair<std::string *, std::string *> alloc_and_copy(const std::string *, const std::string *);
	// parameters must not be const string * to make move really happen
	std::pair<std::string *, std::string *> alloc_and_move(std::size_t n, std::string *, std::string *);
	void check_and_alloc();
	void reallocate();
	void free();
// We don't have declare as friends operators <<, ==, < and the like.
};

// Ex 16.58
template<typename ... T>
void StrVec::emplace_back(T && ... t)
{
#ifdef DEBUG
	std::clog << "Inst: " << __func__ << "()" << std::endl;
#endif
	check_and_alloc();
	a.construct(e++, std::forward<T>(t) ...);
#ifdef DEBUG
	std::clog << "Exit: " << __func__ << "()" << std::endl;
#endif
}

#endif