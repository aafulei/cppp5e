// 18/01/17 = Wed

// Exercise 9.15: Write a program to determine whether two vector<int>s are equal.

#include <iostream>
#include <vector>

using std::boolalpha;
using std::cout;
using std::endl;
using std::vector;

bool equal(const vector<int> & v1, const vector<int> & v2)
{	return v1 == v2; }

int main()
{
	vector<int> vec1 = {1, 2, 3};
	vector<int> vec2 = {1, 2, 3};
	vector<int> vec3 = {4, 5, 6};
	cout << boolalpha;
	cout << equal(vec1, vec2) << endl;	// true
	cout << equal(vec2, vec3) << endl;	// false
	return 0;
}
