// 18/01/28 = Sun

// Exercise 3.42: Write a program to copy a vector of ints into an array of ints.

#include <iostream>
#include <iterator>
#include <vector>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

template<typename Seq>
void print(Seq const& seq)
{
	for (auto elem : seq)
		cout << elem << " ";
	cout << endl;
}

int main()
{
	int a[] = {1, 2, 3};
	vector<int> v = {4, 5, 6};
	print(a);
	print(v);
	copy(v.begin(), v.end(), begin(a));
	print(a);
	return 0;
}