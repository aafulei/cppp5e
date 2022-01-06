// 18/03/13 = Tue: build upon lp-07-42.cpp

// Source code for Book class

#include "..\include\Book.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Book::Book(istream & is)
{
	string line;
	getline(is, line);
	istringstream iss(line);
	iss >> isbn;
	iss >> title;
	iss >> author;
}

// Ex 14.25
Book & Book::operator=(const string & i)
{
	isbn = i;
}

void Book::info() const
{
	cout << "ISBN\t"	<< isbn		<< '\n'
		 << "Title\t"	<< title 	<< '\n'
		 << "Author\t"	<< author 	<< '\n'
		 << endl;
}

// Ex 14.12
// Input policy:
// 1. each line represents a book
// 2. a book can have
// (1) only an ISBN, or
// (2) an ISBN and a title, or
// (3) an ISBN and a title and an author
istream & operator>>(istream & is, Book & book)
{
	book = Book();
	string line;
	getline(is, line);
	istringstream iss(line);
	iss >> book.isbn;
	iss >> book.title;
	iss >> book.author;
	return is;
}

// Ex 14.08
ostream & operator<<(ostream & os, const Book & book)
{
	return os << book.isbn << " " << book.title << " " << book.author;
}

bool operator==(const Book & b1, const Book & b2)
{
	// Two books are the same if and only if they have the same ISBN.
	// However, it's possible that for one book we give its title (author) but for another we omit it. In this case, we treat them as identical.
	return b1.get_isbn()  == b2.get_isbn() ;
}

bool operator!=(const Book & b1, const Book & b2)
{
	return !(b1 == b2);
}