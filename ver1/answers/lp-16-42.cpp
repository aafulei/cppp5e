// 18/03/27 = Tue

// Exercise 16.42: Determine the type of T and of val in each of the following calls:

// template <typename T> void g(T&& val);
// int i = 0; const int ci = i; 
// (a) g(i); 
// (b) g(ci); 
// (c) g(i * ci);

// Answer:
// |      | `T`           | `val`         |
// | :--- | ------------- | ------------- |
// | (a)  | `int &`       | `int &`       |
// | (b)  | `const int &` | `const int &` |
// | (c)  | `int`         | `int &&`      |

#include <iostream>
#include <string>
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
}

int i = 0;
const int ci = i;

void line()
{
	clog << string(50, '-') << endl;
}

int main()
{
	g(i);		line();
	g(ci);		line();
	g(i * ci);
	return 0;
}
