// 18/02/08 = Thu

// Exercise 6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.

// bool isShorter(const string &s1, const string &s2)
// {	return s1.size() < s2.size(); }

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

inline bool isShorter(const string & s1, const string & s2)
{
	return s1.size() < s2.size();
}

int main()
{
	cout << isShorter("Hello", "World") << endl;
	return 0;
}
