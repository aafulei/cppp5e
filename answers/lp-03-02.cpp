// 17/10/20 = Fri

// Exercise 3.2: Write a program to read the standard input a line at a time. Modify your program to read a word at a time.

#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	// one line at a time
	string str;
	while (getline(cin, str))
		cout << str << endl;	// getline() does not store newline, so we write our own
	// alternatively:
	// for (string str; getline(cin, str); cout << str << endl);
	
	// one word at a time
	if (cin.fail()) {			// cin fails after it reads EOF
		cerr << "Standard input has failed ... now is reset." << endl;
		cin.clear();
	}
	while (cin >> str) 
		cout << str << endl;
	// alternatively:
	// for (string str; cin >> str; cout << str << endl);

	return 0;
}