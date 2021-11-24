// 18/01/19 = Fri
// 18/02/20 = Tue: a <sstream> version to take care of entire words

// Exercise 9.43: Write a function that takes three strings, s, oldVal, and newVal. Using iterators, and the insert and erase functions replace all instances of oldVal that appear in s by newVal. Test your function by using it to replace common abbreviations, such as "tho" by "though" and "thru" by "through".

#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::string;

void replace_with(string & s, const string & oldVal, const string & newVal)
{
	auto m = oldVal.size(), n = newVal.size();
	for (auto it = s.begin(); it <= s.end() - m; ++it)
		if (string(it, it + m) == oldVal) {
			it = s.erase(it, it + m);
			it = s.insert(it, newVal.begin(), newVal.end());
			it += n;
		}
}

void replace_word_with(string & s, const string & oldVal, const string & newVal)
{
	istringstream iss(s);
	ostringstream oss;
	for (string word; iss >> word; ) {
		if (!oss.str().empty())
			oss << " ";
		if (word == oldVal)
			word = newVal;
		oss << word;
	}
	s = oss.str();
}

void process
(void (*r)(string &, const string &, const string &), 
string & s, const string & oldVal, const string & newVal)
{
	r(s, oldVal, newVal);
	cout << s << endl;
}

int main()
{
	// an iterator, insert and erase version
	cout << string(75, '-') << endl;
	string s = "tho thru thru tho tho";
	cout << s << endl;
	process(replace_with, s, "thru", "through");
	process(replace_with, s, "tho", "though");
	cout << string(75, '-') << endl;
	// a <sstream> version to take care of entire words
	string t = "tho thomas thorough thought thru tho thou thrust thru trough";
	cout << t << endl;
	process(replace_word_with, t, "thru", "through");
	process(replace_word_with, t, "tho", "though");
	cout << string(75, '-') << endl;
	return 0;
}