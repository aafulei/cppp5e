// 18/01/19 = Fri

// Exercise 9.47: Write a program that finds each numeric character and then each alphabetic character in the string "ab2c3d7R4E6". Write two versions of the program. The first should use find_first_of, and the second find_first_not_of.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

using index = string::size_type;

void find_num(const string & str)
{
	const string numeric = "0123456789";
	for (index pos = 0;
		(pos = str.find_first_of(numeric, pos)) != string::npos;
		++pos)
		cout << "numeric " << str[pos] << " found at " << pos << endl;

	for (index pos = 0;
		(pos = str.find_first_not_of(numeric, pos)) != string::npos;
		++pos)
		cout << "alphabetic " << str[pos] << " found at " << pos << endl;
}

int main()
{
	const string str = "ab2c3d7R4E6";
	cout << str << endl;
	find_num(str);
	return 0;
}