// 18/1/17 = Wed

// demonstrates how to initailize sequential containers with a pair of iterators

// see Lippman 9.2.4 for reference

#include <forward_list>
#include <iostream>
#include <string>
#include <vector>

using std::forward_list;
using std::string;
using std::vector;

int main()
{
	// it is flexible to initailize sequential containers with a pair of iterators

	vector<char const *> vec { "Li Bai", "Du Fu", "Bai Juyi" };
	forward_list<string> lst (vec.begin(), vec.end());

	for (auto name : lst) 
		std::cout << name << std::endl;

	return 0;
}