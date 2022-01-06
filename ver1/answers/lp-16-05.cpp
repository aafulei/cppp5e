// 18/03/21 = Wed

// Exercise 16.5: Write a template version of the print function from § 6.2.4 (p. 217) that takes a reference to an array and can handle arrays of any size and any element type.

// void print(int (&arr)[10])
// {
//     for (auto elem : arr)
//         cout << elem << endl;
// }

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

template<typename T, size_t N>
void print(const T (& a)[N])
{
	for (size_t i = 0; i != N; ++i)
		cout << a[i] << endl;
}

int main()
{
	int a[] = {1, 2, 3};
	string b[] = {"a", "e", "i", "o", "u"};
	print(a);
	print(b);
	return 0;
}