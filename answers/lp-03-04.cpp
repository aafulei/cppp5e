// 17/10/20 = Fri

// Exercise 3.4: Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2)
		cout << "s1 == s2" << endl;
	else if (s1 < s2)
		cout << "s1 < s2" << endl;
	else
		cout << "s1 > s2" << endl;

	string::size_type len1 = s1.size(), len2 = s2.size();
	// alternatively:
	// auto len1 = s1.size(), len2 = s2.size();
	string relation;
	if (len1 == len2)
		relation = "==";
	else
		relation = (len1 < len2) ? "<" : ">";
	cout << "s1.size() " << relation << " s2.size()" << endl;

	return 0;
}