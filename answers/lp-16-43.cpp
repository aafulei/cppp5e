// 18/03/27 = Tue

// Exercise 16.43: Using the function defined in the previous exercise, what would the template parameter of g be if we called g(i = ci)?

// Exercise 16.42: Determine the type of T and of val in each of the following calls:

// template <typename T> void g(T&& val);
// int i = 0; const int ci = i; 
// ...

// Answer: Expression i = ci is an lvalue. The template parameter T is an int &. The function parameter val is an int &. (In this case, T is an int &, and indirectly int & && collapses into int &. Thus val is an int &.)

#include <iostream>
#include <type_traits>
#include <typeinfo>

using namespace std;

template <typename T> void g(T && val)
{
	bool ct = is_const<typename remove_reference<T>::type>();
	bool lt = is_lvalue_reference<T>();
	bool rt = is_rvalue_reference<T>();

	bool cv = is_const<typename remove_reference<decltype(val)>::type>();
	bool lv = is_lvalue_reference<decltype(val)>();
	bool rv = is_rvalue_reference<decltype(val)>();

	clog << "type of T is \""
		 << (ct ? "const " : "")
		 << (typeid(T).name())
		 << (lt ? " &" : "")
		 << (rt ? " &&" : "")
		 << "\"" << endl;

	clog << "type of val is \""
		 << (cv ? "const " : "")
		 << (typeid(val).name())
		 << (lv ? " &" : "")
		 << (rv ? " &&" : "")
		 << "\"" << endl;

	// only if val is a non-const reference, it will change the argument's value
	val = 42;
}

int i = 0;
const int ci = i;

int main()
{
	g(i = ci);			// type of T is "i &"; type of val is "i &"
	cout << i << endl;	// 42
	return 0;
}
