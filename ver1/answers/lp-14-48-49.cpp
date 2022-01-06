// 18/03/14 = Wed

// Exercise 14.48: Determine whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) should have a conversion to bool. If so, explain why, and explain whether the operator should be explicit. If not, explain why not.

// Answer: Yes, we plan to convert a Book to false if it is empty, and to true if otherwise. The operator should be explicit. We need this conversion following the same logic as converting a pointer to bool to see if it really points to something (or is a nullptr). Likewise, this conversion is explicit so as to avoid unwanted implicit conversion. We only need it when it is used as a condition.

// Exercise 14.49: Regardless of whether it is a good idea to do so, define a conversion to bool for the class from the previous exercise.

// To run, enter "a <data\books" in command prompt.

#include "include\Book.h"
#include "source\Book.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	for (vector<Book> v; cin; v.back().info()) {
		Book book(cin);
		// The original code in lp-07-42.cpp was:
		// if (!book.empty())
		// 	break;
		// else
		// 	v.push_back(book);
		// Now we change it to:
		if (book)
			v.push_back(book);
		else
			break;
	}
	return 0;
}