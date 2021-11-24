// 17/10/23 = Mon
// 18/01/27 = Sat: a concise for loop that makes string line a local variable

// Exercise 3.22: Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you’ve updated text, print its contents.

// A paragraph is a group of strings ended with a blank line.

// To run, enter, for example, "a <data\gettysburg" in command prompt.

#include <cctype>
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
	vector<string> text;
	for (string line; getline(cin, line); text.push_back(line))
		;
	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
		for(auto &c : *it)
			c = toupper(c);		// c remains unchanged if it is not a letter
	for (auto it = text.cbegin(); it != text.cend(); ++it)
		cout << *it << endl;
	return 0;
}