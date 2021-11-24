// 18/03/12 = Mon

// Exercise 14.17: Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the equality operators? If so, implement them. If not, explain why not.

// Answer: Yes.

// Built incrementally on lp-14-12.cpp

// To run, enter "a <data\books" in command prompt.

#include "include\Book.h"
#include "source\Book.cpp"
#include <iostream>

using namespace std;

int main()
{
	for (Book book, last; cin >> book; last = book) {
		cout << "Reading " << book.get_isbn() << " ...... ";
		cout << (book == last ? "Duplicated?" : "Got it!") << endl;
	}
	return 0;
}
