// 18/02/10 = Sat
// 18/03/13 = Tue: add Book(), empty(), rewrite Book(istream & is)

// Exercise 7.42: For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

// To run, enter "a <data\books" in command prompt.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::clog;
using std::cout;
using std::endl;
using std::getline;
using std::istream;
using std::istringstream;
using std::string;
using std::vector;

class Book
{
	string isbn;
	string title;
	string author;
public:
	Book()						// no delegation needed
	{
		clog << "Call default constructor()" << endl;
	}
	Book(string i) : Book(i, "", "")
	{
		clog << "Call constructor(string)" << endl;
	}
	Book(string i, string t) : Book(i, t, "")
	{
		clog << "Call constructor(string, title)" << endl;
	}
	Book(string i, string t, string a) : isbn(i), title(t), author(a)
	{
		clog << "Call constructor(string, title, author)" << endl;
	}
	Book(istream &);			// no delegation needed
	bool empty() const { return isbn.empty(); }
	void info() const;
};

Book::Book(istream & is)		// no delegation needed
{
	clog << "Call constructor(istream & is)" << endl;
	// The old implementation is just one line:
	// is >> isbn >> title >> author;
	// But we have to do more as follows.
	// Why? Consider constructing two Books from two lines:
	// 978-7-211-20038-0
	// 978-7-211-20038-0 C++_Primer
	// Had we done in the old manner, this would be taken as one book:
	// ISBN 	978-7-211-20038-0
	// Title 	978-7-211-20038-0
	// Author 	C++_Primer
	string line;
	getline(is, line);
	istringstream iss(line);
	iss >> isbn;
	iss >> title;
	iss >> author;
}

void Book::info() const
{
	cout << "ISBN\t"	<< isbn		<< '\n'
		 << "Title\t"	<< title 	<< '\n'
		 << "Author\t"	<< author 	<< '\n'
		 << endl;
}

int main()
{
	cout << "Case 0" << endl;
	Book primer0;
	primer0.info();

	cout << "Case 1" << endl;
	Book primer1("978-7-211-20038-0");
	primer1.info();
	
	cout << "Case 2" << endl;
	Book primer2("978-7-211-20038-0", "C++ Primer");
	primer2.info();
	
	cout << "Case 3" << endl;
	Book primer3("978-7-211-20038-0", "C++ Primer", "Lippman");
	primer3.info();
	
	cout << "Case 4" << endl;
	// Cannot leave a blank between "C++" and "Primer". Why?
	istringstream iss("978-7-211-20038-0 C++_Primer Lippman");
	Book primer4(iss);
	primer4.info();

	cout << string(50, '-') << endl;
	for (vector<Book> v; cin; v.back().info()) {
		Book book(cin);
		if (book.empty())
			break;
		else
			v.push_back(book);
	}

	return 0;
}