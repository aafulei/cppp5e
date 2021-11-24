// 18/03/24 = Sat: build upon StrVec.h and StrVec.cpp

// Header for Vec template class

#ifndef VEC_H
#define VEC_H

#include <algorithm>		// for std::copy, std::lexicographical_compare
#include <cstddef>			// for std::size_t
#include <initializer_list>	// for std::initializer_list
#include <iostream>			// for std::ostream
#include <memory>			// for std::allocator
#include <string>			// for std::string
#include <utility>			// for std::pair

template<typename T>
class Vec
{
	T * b = nullptr;
	T * e = nullptr;
	T * f = nullptr;
	static std::allocator<T> a;
public:
	using size_type = std::size_t;
	Vec() = default;
	Vec(std::initializer_list<T> il)
	{
		auto range = alloc_and_copy(il.begin(), il.end());
		b = range.first;
		e = f = range.second;
	}
	Vec(const Vec & v)
	{
		auto range = alloc_and_copy(v.b, v.e);
		b = range.first;
		e = f = range.second;
	}
	Vec(Vec && v) noexcept : b(v.b), e(v.e), f(v.f)
	{
		v.b = v.e = v.f = nullptr;
	}
	Vec & operator=(const Vec & v)
	{
		if (this != &v) {
			auto len = v.size();
			if (capacity() < len) {
				auto range = alloc_and_copy(v.b, v.e);
				free();
				b = range.first;
				e = f = range.second;
			}
			else {
				copy(v.b, v.e, b);
				e = b + len;
			}
		}
		return *this;
	}
	Vec & operator=(Vec && v) noexcept
	{
		if (this != &v) {
			b = v.b;
			e = v.e;
			f = v.f;
			v.b = v.e = v.f = nullptr;
		}
		return *this;
	}
	~Vec()
	{
		free();
	}
	Vec & operator=(std::initializer_list<T> il)
	{
		auto len = il.size();
		if (capacity() < len) {
			// There is no cbegin/cend for an initializer_list
			auto range = alloc_and_copy(il.begin(), il.end());
			free();
			b = range.first;
			e = f = range.second;
		}
		else {
			copy(il.begin(), il.end(), b);
			e = b + len;
		}
		return *this;
	}
	T & operator[](size_type n)				{ return b[n]; }
	const T & operator[](size_type n) const { return b[n]; }
	T & at(size_type n)
	{
		if (n >= size()) {
			std::string error = "n (which is " + std::to_string(n) + ") >= size (which is " + std::to_string(size()) + ")";
			throw std::out_of_range(error);
		}
		return b[n];
	}
	const T & at(size_type n) const
	{
		if (n >= size()) {
			std::string error = "n (which is " + std::to_string(n) + ") >= size (which is " + std::to_string(size()) + ")";
			throw std::out_of_range(error);
		}
		return b[n];
	}
	size_type size() const			{ return e - b; }
	size_type capacity() const 		{ return f - b; }
	T * begin() 					{ return b; }
	const T * begin() const 		{ return b; }
	const T * cbegin() const 		{ return const_cast<const T *>(b); }
	T * end() 						{ return e; }
	const T * end() const 			{ return e; }
	const T * cend() const 			{ return const_cast<const T *>(e); }
	void push_back(const T & s)
	{
		check_and_alloc();
		a.construct(e++, s);
	}
	void reserve(size_type n)
	{
		if (capacity() < n) {
			auto range = alloc_and_move(n, b, e);
			free();
			b = range.first;
			e = range.second;
			f = b + n;
		}
	}
	void resize(size_type n)
	{
		if (n > size()) {
			reserve(n);
			auto p = e;
			e = b + n;
			while (p != e)
				a.construct(p++, "");
		}
		else {
			auto p = e;
			e = b + n;
			while (p != e)
				a.destroy(--p);
		}
	}
private:
	std::pair<T *, T *> alloc_and_copy(const T * sb, const T * se)
	{
		// sb: source begin
		// se: source end
		// db: destination begin
		// de: destination end
		auto db = a.allocate(se - sb);
		auto de = uninitialized_copy(sb, se, db);
		return {db, de};
	}
	// parameters must not be const T * to make move really happen
	std::pair<T *, T *> alloc_and_move(std::size_t n, T * sb, T * se)
	{
		auto db = a.allocate(n);
		auto de = uninitialized_copy(make_move_iterator(sb),
								 make_move_iterator(se), db);
		// Alternatively: (since C++17)
		// auto de = uninitialized_move(sb, se, db);
		return {db, de};
	}
    void check_and_alloc()
    {
		if (size() == capacity())
			reallocate();
    }
    void reallocate()
    {
		auto n = (size() == 0) ? 1 : size() * 2;
		reserve(n);
    }
    void free()
    {
    	if (b) {
			while (e != b)
				a.destroy(--e);
			// Alternatively:
			// for_each(reverse_iterator<T *>(e), reverse_iterator<T *>(b), [](T & s){ a.destroy(&s); });
			a.deallocate(b, capacity());
			b = e = f = nullptr; // so that b will not be deallocated twice
		}
    }
};

// define and default initialize static member a of Vec<T>
template<typename T> std::allocator<T> Vec<T>::a;

template<typename T>
std::ostream & operator<<(std::ostream & os, const Vec<T> & v)
{
	for (const auto & s : v)
		os << s << " ";
	return os;
}


template<typename T>
bool operator==(const Vec<T> & v1, const Vec<T> & v2)
{
	if (v1.size() != v2.size())
		return false;
	else
		for (auto it1 = v1.cbegin(), it2 = v2.cbegin();
			it1 != v1.cend(); ++it1, ++it2)
			if (*it1 != *it2)
				return false;
	return true;
}

template<typename T>
bool operator!=(const Vec<T> & v1, const Vec<T> & v2)
{
	return !(v1 == v2);
}

template<typename T>
bool operator<(const Vec<T> & v1, const Vec<T> & v2)
{
	return std::lexicographical_compare(v1.cbegin(), v1.cend(),
										v2.cbegin(), v2.cend());
}

template<typename T>
bool operator>(const Vec<T> & v1, const Vec<T> & v2)
{
	return v2 < v1;
}

template<typename T>
bool operator<=(const Vec<T> & v1, const Vec<T> & v2)
{
	return !(v2 < v1);
}

template<typename T>
bool operator>=(const Vec<T> & v1, const Vec<T> & v2)
{
	return !(v1 < v2);
}

#endif