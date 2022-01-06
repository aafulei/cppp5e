// 17/10/25 = Wed
// 18/01/17 = Wed: redo

// Exercise 9.14: Write a program to assign the elements from a list of char* pointers to C-style character strings to a vector of strings.

#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main()
{
	list<char const *> lst = {"am", "is", "are"};
	vector<string> vec;
	vec.assign(lst.cbegin(), lst.cend());
	for (const auto & elem : vec)
		cout << elem << " ";
	return 0;
}