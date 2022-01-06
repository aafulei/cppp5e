// 18/01/28 = Sun

// Exercise 3.41: Write a program to initialize a vector from an array of ints.

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
	vector<int> v(begin(a), end(a));
	print(a);
	print(v);
	return 0;
}