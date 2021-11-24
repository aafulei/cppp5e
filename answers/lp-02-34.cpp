// 18/02/01 = Thu

// Exercise 2.34: Write a program containing the variables and assignments from the previous exercise. Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct. If not, study the examples until you can convince yourself you know what led you to the wrong conclusion.

#include <iostream>
#include <vector>

template<typename V>
void print(V v)
{
	for (auto e : v)
		std::cout << e << " ";
	std::cout << std::endl;
}

int main()
{
	int i = 0, &r = i;
	const int ci = i, &cr = ci;
	auto a = r;  // a is an int (r is an alias for i, which has type int)
	auto b = ci; // b is an int (top-level const in ci is dropped)
	auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
	auto d = &i; // d is an int* (& of an int object is int*)
	auto e = &ci;// e is const int* (& of a const object is low-level const)
	auto &g = ci;// g is a const int& that is bound to ci
	std::vector<int> vec = {a, b, c, *d, *e, g};
	print(vec);
	a = b = c = *d = 42;
	// cannot change value via e or g as they have low-level const
	vec = {a, b, c, *d, *e, g};
	print(vec);
	return 0;
}