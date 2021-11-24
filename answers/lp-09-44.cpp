// 18/01/19 = Fri

// Exercise 9.44: Rewrite the previous function using an index and replace.

// Exercise 9.43: Write a function that takes three strings, s, oldVal, and newVal. Using iterators, and the insert and erase functions replace all instances of oldVal that appear in s by newVal. Test your function by using it to replace common abbreviations, such as "tho" by "though" and "thru" by "through".

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void replace_with(string & s, const string & oldVal, const string & newVal)
{
	auto m = oldVal.size(), n = newVal.size();
	for (string::size_type i = 0; i <= s.size() - m; ++i)
		if (s.substr(i, m) == oldVal) {
			s.replace(i, m, newVal);
			i += (n-1);
		}
}

void process(string & s, const string & oldVal, const string & newVal)
{
	replace_with(s, oldVal, newVal);
	cout << s << endl;
}

int main()
{
	// an index and replace version
	string s = "tho thru thru tho tho";
	cout << s << endl;
	process(s, "thru", "through");
	process(s, "tho", "though");
	return 0;
}