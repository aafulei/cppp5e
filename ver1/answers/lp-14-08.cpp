// 18/03/12 = Mon

// Exercise 14.8: Define an output operator for the class you chose in exercise 7.40 from § 7.5.1 (p. 291).

// Modified from lp-07-42.cpp

#include "include\Book.h"
#include "source\Book.cpp"
#include <iostream>

using namespace std;

int main()
{
	cout << Book("978-7-121-20038-0", "C++ Primer", "Lippman") << endl;;
	return 0;
}
