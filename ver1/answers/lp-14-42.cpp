// 18/03/14 = Wed

// Exercise 14.42: Using library function objects and adaptors, define an expression to
// (a) Count the number of values that are greater than 1024
// (b) Find the first string that is not equal to pooh
// (c) Multiply all values by 2

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::placeholders;

template <typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

int main()
{
	// (a): 6
	vector<int> u;
	for (int i = 1020; i != 1030; u.push_back(++i))
		;
	print(u);
	cout << count_if(u.cbegin(), u.cend(),
					 bind(greater<int>(), _1, 1024)) << endl;
	// Alternatively:
	// cout << count_if(u.cbegin(), u.cend(),
	// 				[](int a)
	// 				{
	// 					return greater<int>()(a, 1024);
	// 				}) << endl;

	// (b): hoop
	vector<string> v = {"pooh", "pooh", "hoop", "ooph"};
	print(v);
	auto it = find_if(v.cbegin(), v.cend(),
					  bind(not_equal_to<string>(), _1, "pooh"));
	// Alternatively:
	// auto it = find_if(v.cbegin(), v.cend(),
	// 				[](string s)
	// 				{
	// 					return not_equal_to<string>()(s, "pooh");
	// 				});
	if (it != v.end())
		cout << *it << endl;

	// (c): 22 44 66 88
	vector<int> w = {11, 22, 33, 44};
	print(w);
	transform(w.cbegin(), w.cend(), w.begin(), bind(multiplies<int>(), _1, 2));
	// Alternativley:
	// transform(w.cbegin(), w.cend(), w.begin(),
	// 		  [](int a)
	// 		  {
	// 		  	return multiplies<int>()(a, 2);
	// 		  });
	print(w);

	return 0;
}
