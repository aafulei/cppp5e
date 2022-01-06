// 18/1/17 = Wed

// See Lippman 9.2.2 for reference

// demonstrates use of difference_type

#include <iostream>
#include <vector>

using std::vector;

vector<int>::difference_type distance(vector<int>::iterator a, vector<int>::iterator b)
{
	vector<int>::difference_type dist = 0;
	auto c = a;
	for (; a!= b && c != b; ++a, --c, ++dist);
	return dist;
}

int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5 };
	auto b = vec.begin();
	auto e = vec.end();
	std::cout << distance(b, e) << std::endl;	// 5
	std::cout << distance(e, b) << std::endl;	// 5
	return 0;
}