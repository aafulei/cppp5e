// 18/03/12 = Mon

// Exercise 14.12: Define an input operator for the class you used in exercise 7.40 from § 7.5.1 (p. 291). Be sure the operator handles input errors.

// Built incrementally on lp-14-08.cpp

// We must allow default construction for a Book here, because we want to have an empty book first, then to read data into it.

// To run, enter "a <data\books" in command prompt.

#include "include\Book.h"
#include "source\Book.cpp"
#include <iostream>

using namespace std;

int main()
{
	for (Book book; cin >> book; cout << book << endl)
		;
	return 0;
}
