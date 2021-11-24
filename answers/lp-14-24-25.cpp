// 18/03/13 = Tue

// Exercise 14.24: Decide whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define those operators.

// Answer: No. Because we haven't defined any copy-control members, and all the (non-static) data members of a Book are strings, which can be moved, the compiler will synthesize copy- and move-assignment operator for us.

// Exercise 14.25: Implement any other assignment operators your class should define. Explain which types should be used as operands and why.

// Answer: We implement Book & opreator=(const string &); which assigns a new ISBN to the book. The type of the right-hand operand is const string & because we do not modify and need not to copy it.

// Built incrementally on lp-14-17.cpp

#include "include\Book.h"
#include "source\Book.cpp"
#include <iostream>

using namespace std;

Book get_a_Book(Book b)
{
	return b;
}

int main()
{
	// for Exercise 14.24
	Book b1("978-7-211-20038-0", "C++ Primer", "Lippman"), b2, b3;
	b2 = b1;				// copy-assignment
	b3 = get_a_Book(b2);	// move-assignment
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;

	// for Exercise 14.25
	b1 = "XXX-X-XXX-XXXXX-X";
	cout << b1 << endl;
	
	return 0;
}
