// 18/01/17 = Wed

// Exercise 9.16: Repeat the previous program, but compare elements in a list<int> to a vector<int>.

#include <iostream>
#include <list>
#include <vector>

using std::boolalpha;
using std::cout;
using std::endl;
using std::list;
using std::vector;

bool equal(const vector<int> & vec, const list<int> & lst)
{
	vector<int> vec2(lst.cbegin(), lst.cend());
	return vec == vec2;
}

int main()
{
	vector<int> vec = {1, 2, 3};
	list<int> lst1  = {1, 2, 3};
	list<int> lst2  = {4, 5, 6};
	std::cout << std::boolalpha;
	std::cout << equal(vec, lst1) << std::endl;	// true
	std::cout << equal(vec, lst2) << std::endl;	// false
	return 0;
}
