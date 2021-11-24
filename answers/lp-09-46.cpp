// 18/01/19 = Fri
// 18/02/20 = Tue: no dynamically allocation, return just string value

// Exercise 9.46: Rewrite the previous exercise using a position and length to manage the strings. This time use only the insert function.

// Exercise 9.45: Write a funtion that takes a string representing a name and two other strings representing a prefix, such as “Mr.” or “Ms.” and a suffix, such as “Jr.” or “III”. Using iterators and the insert and append functions, generate and return a new string with the suffix and prefix added to the given name.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string pre_and_suf(const string & name, const string & p, const string & s)
{
	string str(name);
	str.insert(0, p);
	str.insert(p.size(), " ");
	str.insert(str.size(), " ");
	str.insert(str.size(), s);
	return str;
}

int main()
{
	cout << pre_and_suf("James", "King", "I") << endl;
	cout << pre_and_suf("Elizabeth", "Queen", "II") << endl;
	return 0;
}