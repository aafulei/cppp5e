// 18/02/28 = Wed

// Exercise 12.23: Write a program to concatenate two string literals, putting the result in a dynamically allocated array of char. Write a program to concatenate two library strings that have the same value as the literals used in the first program.

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

char * concat(const char * a, const char * b)
{
	char * c = new char[sizeof a + sizeof b - 1];
	strcpy(c, a);
	strcat(c, b);
	return c;
}

int main()
{
	// C-style strings
	const char * a = "Hello, ";
	const char * b = "World!";
	char * c = concat(a, b);
	cout << c << endl;
	delete[] c;
	// library strings
	string s = a;
	string t = b;
	cout << s + t << endl;
	return 0;
}


