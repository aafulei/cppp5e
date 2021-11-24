// 18/01/17 = Wed

// Exercise 9.24: Write a program that fetches the first element in a vector using at, the subscript operator, front, and begin. Test your program on an empty vector.

#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void fetch(const vector<int> & vec)
{
	cout << string(25, '-') << endl;
	if (vec.empty()) {
		cerr << "Error: Empty vector!" << endl;
	}
	else {
		cout << vec.at(0) << endl;
		cout << vec[0] << endl;
		cout << vec.front() << endl;
		cout << *vec.begin() << endl;
	}
}

int main()
{
	vector<vector<int>> vv = {{}, {1}, {42, 24}};
	for (const auto & v : vv)
		fetch(v);
	return 0;
}