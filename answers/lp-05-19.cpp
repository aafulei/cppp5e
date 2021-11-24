// 18/02/04 = Sun

// Exercise 5.19: Write a program that uses a do while loop to repetitively request two strings from the user and report which string is less than the other.

#include <cctype>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::toupper;

int main()
{
	const int N = 256;
	string s1, s2, option;
	do {
		cout << "Entern two strings:" << endl;
		cin >> s1 >> s2;
		cout << s1 << (s1 == s2 ? " = " : s1 < s2 ? " < " : " > ") <<  s2 << endl;
		cin.ignore(N, '\n');
		cout << "Continue? Enter (Y)es or (N)o."<< endl;
		cin >> option;
	}
	while (cin && !option.empty() && toupper(option[0]) == 'Y');
	return 0;
}