// 18/01/28 = Sun

// Exercise 3.36: Write a program to compare two arrays for equality. Write a similar program to compare two vectors.

#include <cstddef>
#include <iostream>
#include <vector>

using std::boolalpha;
using std::cout;
using std::endl;
using std::size_t;
using std::vector;

template<typename Seq>
void print(Seq const& seq)
{
	for (auto elem : seq)
		cout << elem << " ";
	cout << endl;
}

template<typename T, size_t N>
bool compare(T const (&a)[N], T const (&b)[N])
{
	for (size_t i = 0; i < N; ++i)
		if (a[i] != b[i])
			return false;
	return true;
}

int main()
{
	constexpr size_t N = 3;
	int a[N] = {1, 2, 3};
	int b[N] = {1, 2, 3};
	int c[N] = {4, 5, 6};
	cout << boolalpha;
	cout << "array a = "; print(a);
	cout << "array b = "; print(b);
	cout << "array c = "; print(c);
	cout << "array a equals array b? " << compare(a, b) << endl;
	cout << "array b equals array c? " << compare(b, c) << endl;
	vector<int> u =  {1, 2, 3};
	vector<int> v =  {1, 2, 3};
	vector<int> w =  {4, 5, 6};
	cout << "vector u = "; print(u);
	cout << "vector v = "; print(v);
	cout << "vector w = "; print(w);
	cout << "vector u equals vector v? " << (u == v) << endl;
	cout << "vector v equals vector w? " << (v == w) << endl;
	return 0;
}