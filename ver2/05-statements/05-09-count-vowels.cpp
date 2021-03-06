// 18/02/04 = Sun

// Exercise 5.9: Write a program using a series of if statements to count the number of vowels in text read from cin.

#include <iostream>
#include <cstring>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::tolower;

int main()
{
	unsigned a, e, i, o, u, blank, tab, newline, ff, fl, fi;
	a = e = i = o = u = blank = tab = newline = ff = fl = fi = 0;
	for (string line; getline(cin, line); ++newline) {
		bool prev = false;
		for (auto c : line) {
			if (prev) {
				if (c == 'f')
					++ff;
				else if (c == 'l')
					++fl;
				else if (c == 'i')
					++fi;
				prev = false;
			}
			else if (c == 'f')
				prev = true;
			c = tolower(c);
			if (c == 'a')
				++a;
			else if (c == 'e')
				++e;
			else if (c == 'i')
				++i;
			else if (c == 'o')
				++o;
			else if (c == 'u')
				++u;
			else if (c == ' ')
				++blank;
			else if (c == '\t')
				++tab;
		}
	}
	cout << "a\t" << a << endl;
	cout << "e\t" << e << endl;
	cout << "i\t" << i << endl;
	cout << "o\t" << o << endl;
	cout << "u\t" << u << endl;
	cout << "blank\t" << blank << endl;
	cout << "tab\t" << tab << endl;
	cout << "newline\t" << newline << endl;
	cout << "ff\t" << ff << endl;
	cout << "fi\t" << fi << endl;
	cout << "fl\t" << fl << endl;
	return 0;
}
