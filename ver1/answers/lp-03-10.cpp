// 17/10/20 = Fri
// 18/01/26 = Fri: read from standard input

// Exercise 3.10: Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.

// To run, enter, for example, "a <data\summer" in command prompt.

#include <cctype>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	for (string str; getline(cin, str); cout << endl)
		for (auto c : str)
			if (!ispunct(c))
				cout << c;
	return 0;
}
