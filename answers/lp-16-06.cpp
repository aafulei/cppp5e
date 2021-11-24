// 18/03/21 = Wed

// Exercise 16.6: How do you think the library begin and end functions that take an array argument work? Define your own versions of these functions.

#include <algorithm>	// for std::transform
#include <cctype>		// for ::toupper
#include <iostream>
#include <string>

using namespace std;

template<typename T, size_t N>
T * begin(T (& a)[N])
{
	return a;
}

template<typename T, size_t N>
T * end(T (& a)[N])
{
	return a + N;
}

int main()
{
	int a[] = {1, 2, 3};
	string b[] = {"a", "e", "i", "o", "u"};

	for (auto it = ::begin(a); it != ::end(a); ++it)
		*it *= 2;
	for (const auto & i : a)
		cout << i << " ";					// 2 4 6
	cout << endl;

	cout << ::end(b) - ::begin(b) << endl;	// 5
	for (auto & s : b)
		transform(s.begin(), s.end(), s.begin(), ::toupper);
	for (const auto & s : b)
		cout << s << " ";					// A E I O U

	return 0;
}
