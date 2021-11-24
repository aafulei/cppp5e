// 18/03/24 = Sat: build upon StrBlob.h and StrBlob.cpp
// 18/03/25 = Sun: constructor for iterator range

// Header for Blob class template

// It is required that Blob is shared and checked.

// for lp-16-12.cpp, lp-16-24.cpp

#ifndef BLOB_H
#define BLOB_H

#include "BlobPtr.h"
#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template<typename> class Blob;
template<typename> class BlobPtr;
template<typename> class ConstBlobPtr;

template<typename T> bool operator==(const Blob<T> &, const Blob<T> &);
template<typename T> bool operator!=(const Blob<T> &, const Blob<T> &);

template<typename T>
class Blob
{
public:
	using size_type = typename std::vector<T>::size_type;
private:
	std::shared_ptr<std::vector<T>> sptr;
public:
	Blob()
		: sptr(std::make_shared<std::vector<T>>()) {}
	Blob(std::initializer_list<T> i)
		: sptr(std::make_shared<std::vector<T>>(i)) {}
	template<typename I> Blob(I b, I e);	// Ex 16.24
	bool empty() const 				{ return sptr->empty(); }
	size_type size() const 			{ return sptr->size(); }
	BlobPtr<T> begin()				{ return BlobPtr<T>(*this); }
	ConstBlobPtr<T> begin() const 	{ return ConstBlobPtr<T>(*this); }
	ConstBlobPtr<T> cbegin() const	{ return ConstBlobPtr<T>(*this); }
	BlobPtr<T> end()				{ return BlobPtr<T>(*this, size()); }
	ConstBlobPtr<T> end() const  { return ConstBlobPtr<T>(*this, size()); }
	ConstBlobPtr<T> cend() const { return ConstBlobPtr<T>(*this, size()); }
	T & front()
	{
		check("front() on empty Blob!");
		return sptr->front();
	}
	const T & front() const
	{
		check("front() on empty Blob!");
		return sptr->front();
	}
	T & back()
	{
		check("back() on empty Blob!");
		return sptr->back();
	}
	const T & back() const
	{
		check("back() on empty Blob!");
		return sptr->back();
	}
	T & operator[](size_type n)
	{
		check("at wrong place of Blob", n);
		return sptr->at(n);
	}
	const T & operator[](size_type n) const
	{
		check("at wrong place of Blob", n);
		return sptr->at(n);
	}
	void push_back(const T & e)
	{
		sptr->push_back(e);
	}
	void push_back(T && e)
	{
		sptr->push_back(std::move(e));
	}
	void pop_back()
	{
		sptr->pop_back();
	}
private:
	void check(const std::string & msg, size_type pos = 0) const
	{
		if (pos >= size())
			throw std::out_of_range(msg);
	}
friend class BlobPtr<T>;
friend class ConstBlobPtr<T>;
friend bool operator== <T>(const Blob &, const Blob &);
friend bool operator!= <T>(const Blob &, const Blob &);
// Since we've implemented operator++ and operator* for ConstBlob<T>Ptr, we don't have to befriend operator<<.
// friend std::ostream & operator<< <T>(std::ostream &, const Blob &);
};

// Ex 16.24
template<typename T>
template<typename I>
Blob<T>::Blob(I b, I e) : sptr(std::make_shared<std::vector<T>>(std::vector<T>(b, e))) {}

template<typename T>
bool operator==(const Blob<T> & b1, const Blob<T> & b2)
{
	return b1.sptr == b2.sptr;
}

template<typename T>
bool operator!=(const Blob<T> & b1, const Blob<T> & b2)
{
	return !(b1 == b2);
}

template<typename T>
std::ostream & operator<<(std::ostream & os, const Blob<T> & b)
{
	// Question: Can we write a range-for like for (const auto & e : b)?
	// Answer: It depends on whether we've implemented operator++ and operator* for ConstBlob<T>Ptr. Had we done this, we would not need to declare operator<< as a friend of Blob.
	// for (auto it = b.sptr->cbegin(); it != b.sptr->cend(); ++it)
	// 	os << "\"" << *it << "\" ";
	for (const auto & e : b)
		os << e << " ";
	return os;
}

#endif
