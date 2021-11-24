// 18/1/17 = Wed

// See Lippman 9.2.3 for reference

// container.begin() is overloaded :
// - if the container is non-const, then the return type is iterator;
// - if the container is const, then the return type is const_iterator.

#include <iostream>
#include <type_traits>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vec1 = { 1, 2, 3 };
	vector<int> vec2 = { 4, 5, 6 };
	vector<int> const vec3 = { 7, 8, 9 };

	auto it1 = vec1.begin();
	auto it2 = vec2.begin();
	auto it3 = vec3.begin();

	cout << std::boolalpha;
	cout << std::is_same<decltype(it1), decltype(it2)>() << endl;	// true
	cout << std::is_same<decltype(it2), decltype(it3)>() << endl;	// false
}