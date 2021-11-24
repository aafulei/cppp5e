// 18/03/13 = Tue: build upon lp-07-42.cpp

// Header for Book class

// for lp-14-08.cpp, lp-14-12.cpp, lp-14-17.cpp, lp-14-24-25.cpp, lp-14-48-49.cpp

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book
{
	std::string isbn;
	std::string title;
	std::string author;
public:
	Book(std::string i = "", std::string t = "", std::string a = "")
		: isbn(i), title(t), author(a) {}
	Book(std::istream &);
	Book & operator=(const std::string &);						// Ex 14.25
	explicit operator bool() const	{ return !empty(); }		// Ex 14.49
	bool empty() const				{ return isbn.empty(); }
	void info() const;
	const auto get_isbn() const		{ return isbn; } 			// C++14 auto
friend std::istream & operator>>(std::istream &, Book &);		// Ex 14.12
friend std::ostream & operator<<(std::ostream &, const Book &);	// Ex 14.08
// Ex 14.17: We do not have to declare operators == and != as friends after we have defined get_isbn().
};

#endif