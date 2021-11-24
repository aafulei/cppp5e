// 18/01/19 = Fri

// Exercise 9.41: Write a program that initializes a string from a vector<char>.

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<char> vec = {'H', 'e', 'l', 'l', 'o'};
	string str(vec.begin(), vec.end());
	cout << str << endl;
	return 0;
}