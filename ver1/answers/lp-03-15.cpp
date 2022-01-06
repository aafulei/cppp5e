// 17/10/22 = Sun
// 18/01/27 = Sat: a concise for loop that makes string s a local variable

// Exercise 3.15: Repeat the previous program but read strings this time.

// Exercise 3.14: Write a program to read a sequence of ints from cin and store those values in a vector.

// To run, enter, for example, "a <data\spring" or "a <data\summer" in command prompt.

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<string> v;
	for (string s; cin >> s; v.push_back(s))
		;
	for (auto const& s : v)
		cout << s << " ";
	return 0;
}