// 18/03/27 = Tue

// Exercise 16.39: Use an explicit template argument to make it sensible to pass two string literals to the original version of compare from § 16.1.1 (p. 652).

#include <iostream>
#include <string>

using namespace std;

template <typename T>
int compare(const T & v1, const T & v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main()
{
	cout << compare<string>("Hello", "Hi") << endl;	// -1
	return 0;
}