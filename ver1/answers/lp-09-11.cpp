// 18/01/17 = Wed

// Exercise 9.11: Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print(const vector<int> & v)
{
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vector<int> v1;
	vector<int> v2(v1);
	vector<int> v3 = {1, 2, 3};	// vector<int> v3 = 3 is illegal !
	vector<int> v4(v3.begin(), v3.end());
	vector<int> v5(5, 42);
	vector<int> v6(6);
	cout << "v1: "; print(v1);	// empty
	cout << "v2: "; print(v2);	// empty
	cout << "v3: "; print(v3);	// 1 2 3
	cout << "v4: "; print(v4);	// 1 2 3
	cout << "v5: "; print(v5);	// 42 42 42 42 42
	cout << "v6: "; print(v6);	// 0 0 0 0 0 0
	return 0;
}