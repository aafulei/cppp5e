// 17/10/25 = Wed
// 18/01/17 = Wed: redo

// Exercise 9.13: How would you initialize a vector<double> from a list<int>? From a vector<int>? Write code to check your answers.

#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;

void print(const vector<double> & v)
{
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

int main()
{
	list<int> lst = {1, 2, 3};
	vector<int> vec {4, 5, 6};
	vector<double> dvec1(lst.begin(), lst.end());
	vector<double> dvec2(vec.begin(), vec.end());
	print(dvec1);	// 1 2 3
	print(dvec2);	// 4 5 6
	return 0;
}