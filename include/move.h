// 18/03/27 = Tue

// Header for move class template

// 1. if move takes an lvalue, it yields an rvalue
// 2. if move takes an rvalue, it still yields an rvalue

#ifndef MOVE_H
#define MOVE_H

#include <type_traits>

template<typename T>
typename std::remove_reference<T>::type && move(T && t)
{
	return static_cast<typename std::remove_reference<T>::type &&>(t);
}

// TODO: forward

/* ---------- postscript ----------

	Q: Why don't we simply write move() as follows?

	template<typename T>
	T && move(T && val)
	{
		return static_cast<T &&>(val);
	}

	A: Consider passing an lvalue reference to the template function. It will return an lvalue reference rather than an rvalue reference. For example:

	#include "include\move.h"
	#include <type_traits>
	#include <iostream>

	using namespace std;

	int main()
	{
		int i = 42, & r = i;
		cout << is_lvalue_reference<decltype(::move(i))>() << endl;	// 1
		cout << is_rvalue_reference<decltype(::move(i))>() << endl;	// 0
		return 0;
	}

----------------------------------- */

#endif