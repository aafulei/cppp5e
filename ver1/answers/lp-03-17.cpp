// 17/10/22 = Sun
// 18/01/27 = Sat: a concise for loop that makes string s a local variable

// Exercise 3.17: Read a sequence of words from cin and store the values a vector. After you've read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.

// To run, enter, for example "a <data\summer" in command prompt

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
	vector<string> v;
	for (string s; cin >> s; v.push_back(s))
		;
	for (auto & s : v)
		for (auto & c : s)
			c = toupper(c);
	decltype(v.size()) n = 0;
	for (auto const& s : v) {
		cout << s << " ";
		if (++n % 8 == 0)
			cout << endl;
	}
	return 0;
}