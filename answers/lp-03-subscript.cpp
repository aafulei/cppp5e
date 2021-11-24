// 18/01/26 = Fri

// case conversions

// demonstrates safety check before subscripting

#include <cctype>
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::istringstream;
using std::string;

int main()
{
	// lowercase
	string const LINE = "this program demonstrates safety check before subscripting.";
	cout << LINE << endl;

	// UPPERCASE
	string str(LINE);
	for (auto &c : str)				// range for saves from safety check
		c = toupper(c);
	cout << str << endl;

	// First letter in uppercase
	str = LINE;
	if (!str.empty())									// safety check
		str[0] = toupper(str[0]);
	cout << str << endl;
	
	// FIRST word in uppercase
	str = LINE;
	for (decltype(str.size()) index = 0;
		index != str.size() && !isspace(str[index]);	// safety check
		++index)
		str[index] = toupper(str[index]);
	cout << str << endl;

	// Capitalize Each Word
	str = LINE;
	bool flag = true;
	for (decltype(str.size()) index = 0;
		index != str.size();							// safety check
		++index)
		if (isspace(str[index]))
			flag = true;
		else if (flag)/* && isalnum(str[index]))*/ {
			str[index] = toupper(str[index]);
			flag = false;
		}
	cout << str << endl;

	// Capitalize Each Word: made easier with stringstream
	istringstream iss(LINE);
	while (iss >> str) {
		str[0] = toupper(str[0]);
		cout << str << " ";
	}

	return 0;
}