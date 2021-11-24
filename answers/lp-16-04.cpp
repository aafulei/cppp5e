// 18/03/21 = Wed

// Exercise 16.4: Write a template that acts like the library find algorithm. The function will need two template type parameters, one to represent the function’s iterator parameters and the other for the type of the value. Use your function to find a given value in a vector<int> and in a list<string>.

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

template<typename I, typename T>
I find(I b, I e, const T & val)
{
	while (b != e)
		if (*b == val)
			return b;
		else
			++b;
	return b;
}

// It is not straightforward to return the position where val is found.
// Consider C is a list, not a vector.
template<typename C, typename T>
void search(const C & c, const T & val)
{
	typename C::const_iterator it;
	if ((it = ::find(c.cbegin(), c.cend(), val)) != c.cend())
		cout << *it << " is found." << endl;
	else
		cout << val << " is not found." << endl;
}

template<typename C>
void print(const C & c)
{
	for (const auto e : c)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vector<int> vec = {1, 3, 5, 7, 9};
	print(vec);
	for (int i = 0; i != 10; ++i)
		::search(vec, i);

	list<string> lst = {"a", "e", "i", "o", "u"};
	print(lst);
	for (char c = 'a'; c != 'f'; ++c)
		::search(lst, string(1, c));

	return 0;
}



