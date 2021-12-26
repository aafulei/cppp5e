// 21/12/26 = Sun
// 18/02/06 = Tue

// Exercise 6.17: Write a function to determine whether a string contains any capital letters. Write a function to change a string to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?

// Answer: No. The first functions does not change the string while the second does.

#include <cctype>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::isupper;
using std::string;
using std::tolower;

bool has_upper(const string & s)
{
	for (auto c : s)
		if (isupper(c))
			return true;
	return false;
}

void to_lower(string & s)
{
	for (auto & c : s)
		c = tolower(c);
}

int main()
{
	// use has_upper()
	cout << has_upper("lp-06-17.cpp") << endl;
	cout << has_upper((const char *)"lp-06-17.cpp") << endl;
	cout << has_upper(string("HKUST")) << endl;
	cout << has_upper((string)"HKUST") << endl;
	// use to_lower()
	string hkust = "HKUST";
	to_lower(hkust);
	cout << hkust << endl;
	return 0;
}
