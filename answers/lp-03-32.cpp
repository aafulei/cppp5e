// 18/01/28 = Sun

// Exercise 3.32: Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::begin;
using std::copy;
using std::cout;
using std::end;
using std::endl;
using std::vector;

template<typename Seq>
void print(Seq const& seq)
{
	for (auto i : seq)
		cout << i << " ";
	cout << endl;
}

int main()
{
	// use arrays
	int a[10];
	for (int i = 0; i < 10; ++i)
		a[i] = i;
	print(a);
	int b[10], c[10];
	// memberwise copy
	for (int i = 0; i < 10; ++i)
		b[i] = a[i];
	print(b);
	// std::copy
	copy(begin(a), end(a), begin(c));
	print(c);
	
	// use vectors
	vector<int> v;
	for (int i = 0; i != 10; v.push_back(i++))
		;
	print(v);
	vector<int> w = v;
	print(w);

	return 0;
}