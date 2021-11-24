// 18/03/24 = Sat: build upon BlobPtr.h and BlobPtr.cpp

// Header for BlobPtr and ConstBlobPtr class templates

// for lp-16-12.cpp

#ifndef BLOBPTR_H
#define BLOBPTR_H

#include "Blob.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template<typename T> class Blob;
template<typename T> class BlobPtr;
template<typename T> class ConstBlobPtr;

template<typename T> bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template<typename T> bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template<typename T> bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
template<typename T> bool operator>(const BlobPtr<T> &, const BlobPtr<T> &);
template<typename T> bool operator<=(const BlobPtr<T> &, const BlobPtr<T> &);
template<typename T> bool operator>=(const BlobPtr<T> &, const BlobPtr<T> &);

template<typename T>
bool operator==(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template<typename T>
bool operator!=(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template<typename T>
bool operator<(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template<typename T>
bool operator>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template<typename T>
bool operator<=(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template<typename T>
bool operator>=(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

template<typename T>
class BlobPtr
{
public:
	using difference_type = typename std::vector<T>::difference_type;
	using size_type = typename std::vector<T>::size_type;
private:
	std::weak_ptr<std::vector<T>> wptr;
	size_type pos;
public:
	BlobPtr() : pos(0) {}
	BlobPtr(Blob<T> & b, size_type p = 0) : wptr(b.sptr), pos(p) {}
	T & operator*() const
	{
		auto sptr = check("Dereference past the end!");
		return (*sptr)[pos];
	}
	T * operator->() const
	{
		return &(this->operator*());
	}
	BlobPtr & operator++()
	{
		check("Increment past the end!");
		++pos;
		return *this;
	}
	BlobPtr & operator--()
	{
		--pos;
		check("Decrement past the begin!");
		return *this;
	}
	BlobPtr operator++(int)
	{
		BlobPtr old(*this);
		++*this;
		return old;
	}
	BlobPtr operator--(int)
	{
		BlobPtr old(*this);
		--*this;
		return old;
	}
	BlobPtr & operator+=(difference_type d)
	{
		if (d > 0)
			do
				++*this;
			while (--d != 0);
		else if (d < 0)
			do
				--*this;
			while (++d != 0);
		return *this;
	}
	BlobPtr & operator-=(difference_type d)
	{
		return *this += (-d);
	}
	BlobPtr operator+(difference_type d)
	{
		BlobPtr p(*this);
		return p += d;
	}
	BlobPtr operator-(difference_type d)
	{
		return *this + (-d);
	}
	difference_type operator-(const BlobPtr & p)
	{
		if (wptr.lock() != p.wptr.lock())
			throw std::invalid_argument("Refer to different Blob!");
		return pos - p.pos;
	}
private:
	std::shared_ptr<std::vector<T>>
	check(const std::string & msg, size_type pos = 0) const
	{
		auto sptr = wptr.lock();
		if (!sptr)
			throw std::runtime_error("Unbound BlobPtr!");
		if (pos >= sptr->size())
			throw std::out_of_range(msg);
		return sptr;
	}
friend bool operator== <T>(const BlobPtr &, const BlobPtr &);
friend bool operator!= <T>(const BlobPtr &, const BlobPtr &);
friend bool operator< <T>(const BlobPtr &, const BlobPtr &);
friend bool operator> <T>(const BlobPtr &, const BlobPtr &);
friend bool operator<= <T>(const BlobPtr &, const BlobPtr &);
friend bool operator>= <T>(const BlobPtr &, const BlobPtr &);
};

template<typename T>
class ConstBlobPtr
{
public:
	using difference_type = typename std::vector<T>::difference_type;
	using size_type = typename std::vector<T>::size_type;
private:
	std::weak_ptr<std::vector<T>> wptr;
	size_type pos;
public:
	ConstBlobPtr() : pos(0) {}
	ConstBlobPtr(const Blob<T> & b, size_type p = 0)
		: wptr(b.sptr), pos(p) {}
	const T & operator*() const
	{
		auto sptr = check("Dereference past the end!");
		return (*sptr)[pos];
	}
	const T * operator->() const
	{
		return &(this->operator*());
	}
	ConstBlobPtr & operator++()
	{
		check("Increment past the end!");
		++pos;
		return *this;
	}
	ConstBlobPtr & operator--()
	{
		--pos;
		check("Decrement past the begin!");
		return *this;
	}
	ConstBlobPtr operator++(int)
	{
		ConstBlobPtr old(*this);
		++*this;
		return old;
	}
	ConstBlobPtr operator--(int)
	{
		ConstBlobPtr old(*this);
		--*this;
		return old;
	}
	ConstBlobPtr & operator+=(difference_type d)
	{
		if (d > 0)
			do
				++*this;
			while (--d != 0);
		else if (d < 0)
			do
				--*this;
			while (++d != 0);
		return *this;
	}
	ConstBlobPtr & operator-=(difference_type d)
	{
		return *this += (-d);
	}
	ConstBlobPtr operator+(difference_type d)
	{
		ConstBlobPtr p(*this);
		return p += d;
	}
	ConstBlobPtr operator-(difference_type d)
	{
		return *this + (-d);
	}
	difference_type operator-(const ConstBlobPtr & p)
	{
		if (wptr.lock() != p.wptr.lock())
			throw std::invalid_argument("Refer to different Blob!");
		return pos - p.pos;
	}
private:
	std::shared_ptr<std::vector<T>>
	check(const std::string & msg, size_type pos = 0) const
	{
		auto sptr = wptr.lock();
		if (!sptr)
			throw std::runtime_error("Unbound ConstBlobPtr!");
		if (pos >= sptr->size())
			throw std::out_of_range(msg);
		return sptr;
	}
friend bool operator== <T>(const ConstBlobPtr &, const ConstBlobPtr &);
friend bool operator!= <T>(const ConstBlobPtr &, const ConstBlobPtr &);
friend bool operator< <T>(const ConstBlobPtr &, const ConstBlobPtr &);
friend bool operator> <T>(const ConstBlobPtr &, const ConstBlobPtr &);
friend bool operator<= <T>(const ConstBlobPtr &, const ConstBlobPtr &);
friend bool operator>= <T>(const ConstBlobPtr &, const ConstBlobPtr &);
};


template<typename T>
bool operator==(const BlobPtr<T> & p1, const BlobPtr<T> & p2)
{
	return p1.pos == p2.pos && p1.wptr.lock() == p2.wptr.lock();
}

template<typename T>
bool operator==(const ConstBlobPtr<T> & p1, const ConstBlobPtr<T> & p2)
{
	return p1.pos == p2.pos && p1.wptr.lock() == p2.wptr.lock();
}

template<typename T>
bool operator!=(const BlobPtr<T> & p1, const BlobPtr<T> & p2)
{
	return !(p1 == p2);
}

template<typename T>
bool operator!=(const ConstBlobPtr<T> & p1, const ConstBlobPtr<T> & p2)
{
	return !(p1 == p2);
}

template<typename T>
bool operator<(const BlobPtr<T> & p1, const BlobPtr<T> & p2)
{
	if (p1.wptr.lock() != p2.wptr.lock())
		throw std::invalid_argument("Refer to different Blob!");
	return p1.pos < p2.pos;
}

template<typename T>
bool operator<(const ConstBlobPtr<T> & p1, const ConstBlobPtr<T> & p2)
{
	if (p1.wptr.lock() != p2.wptr.lock())
		throw std::invalid_argument("Refer to different Blob!");
	return p1.pos < p2.pos;
}

template<typename T>
bool operator>(const BlobPtr<T> & p1, const BlobPtr<T> & p2)
{
	return p2 < p1;
}

template<typename T>
bool operator>(const ConstBlobPtr<T> & p1, const ConstBlobPtr<T> & p2)
{
	return p2 < p1;
}

template<typename T>
bool operator<=(const BlobPtr<T> & p1, const BlobPtr<T> & p2)
{
	return !(p2 < p1);
}

template<typename T>
bool operator<=(const ConstBlobPtr<T> & p1, const ConstBlobPtr<T> & p2)
{
	return !(p2 < p1);
}

template<typename T>
bool operator>=(const BlobPtr<T> & p1, const BlobPtr<T> & p2)
{
	return !(p1 < p2);
}

template<typename T>
bool operator>=(const ConstBlobPtr<T> & p1, const ConstBlobPtr<T> & p2)
{
	return !(p1 < p2);
}









#endif

