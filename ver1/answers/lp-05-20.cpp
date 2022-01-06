// 18/02/04 = Sun

// Exercise 5.20: Write a program to read a sequence of strings from the standard input until either the same word occurs twice in succession or all the words have been read. Use a while loop to read the text one word at a time. Use the break statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.

// To run, enter, for example, "a <data\how" or "a <data\gettysburg" in command prompt.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	bool repeated = false;
	for (string r, s; cin >> s; r = s) {
		if (s == r) {
			cout << s << endl;
			repeated = true;
			break;
		}
	}
	if (!repeated)
		cout << "No word was repeated." << endl;
	return 0;
}