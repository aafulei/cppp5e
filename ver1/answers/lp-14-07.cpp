// Exercise 14.7: Define an output operator for you String class you wrote for the exercises in § 13.5 (p. 531).

#include "include\String.h"
#include "source\String.cpp"
#include <iostream>

using namespace std;

int main()
{
	cout << String("Hello, World!") << endl;
	return 0;
}
