// 17/10/20 = Fri
// 18/01/26 = Fri: cope with unnecessary trailing space

// Exercise 3.5: Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s, t;
	while (cin >> s)
		t += s;
	cout << t << endl;
	
	cin.clear();
	t.clear();	// alternatively: t = "";
	while (cin >> s)
		t += ((t.empty() ? "" : " ") + s);	// revised on 18/1/26 = Fri
		// this is better than:
		// t += (s + " ");
		// because it copes with the unnecessary trailing space
	cout << t << endl;

	return 0;
}