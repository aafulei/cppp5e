// 17/10/20 = Fri

// convert a series of numbers into hexadecimal digits

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string const hexdigitis = "0123456789ABCDEF";
	cout << "Enter a series of numbers (0-15): ";
	string result;
	unsigned short digit;
	while (cin >> digit)
		if (digit < hexdigitis.size())
			result += hexdigitis[digit];
	cout << result << endl;
	return 0;
}