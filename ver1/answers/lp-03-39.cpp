// 18/01/28 = Sun

// Exercise 3.39: Write a program to compare two strings. Now write a program to compare the values of two C-style character strings.

#include <cstring>
#include <iostream>
#include <string>

using std::boolalpha;
using std::cout;
using std::endl;
using std::strcmp;
using std::string;

int main()
{
	// strings
	string s1 = "Hello";
	string s2 = "Hello";
	string s3 = "World";
	cout << boolalpha;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1 " << ((s1 == s2) ? "=" : ((s1 < s2) ? "<" : ">")) << " s2" << endl;
	cout << "s2 " << ((s2 == s3) ? "=" : ((s2 < s3) ? "<" : ">")) << " s3" << endl;
	
	// C-style character strings (char const *)
	auto cs1 = s1.c_str();
	auto cs2 = s2.c_str();
	auto cs3 = s3.c_str();
	cout << "cs1 = " << cs1 << endl;
	cout << "cs2 = " << cs2 << endl;
	cout << "cs3 = " << cs3 << endl;
	int cmp = strcmp(cs1, cs2);
	cout << "cs1 " << ((cmp == 0) ? "=" : (cmp < 0 ? "<" : ">")) << " cs2" << endl;
	cmp = strcmp(cs2, cs3);
	cout << "cs2 " << ((cmp == 0) ? "=" : (cmp < 0 ? "<" : ">")) << " cs3" << endl;
	
	return 0;
}