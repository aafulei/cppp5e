// 18/02/21 = Wed

// Makes a lambda and a nested lambda.

#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::function;

// alternatively since C++14:
// auto make_lambda(int a)
function<int(int)> make_lambda(int a)
{
	return [a](int b)
	{
		return a + b;
	};
}

// alternatively since C++14:
// auto make_nested_lambda(int a)
function<function<int(int)>(int)> make_nested_lambda(int a)
{
	return [a](int b)
	{
		return [a, b](int c)
		{
			return a + b + c;
		};
	};
}

int main()
{
    cout << make_lambda(42)(24) << endl;			// 66
    cout << make_nested_lambda(42)(24)(22) << endl;	// 88
    return 0;
}