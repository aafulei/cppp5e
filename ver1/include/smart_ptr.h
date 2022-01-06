// 18/03/25 = Sun
// 18/03/26 = Mon
// 18/03/28 = Wed: make_shared<T>()

// Header for shared_ptr and unique_ptr class templates

// for lp-16-28.cpp, lp-16-29-30.cpp, lp-16-60-61.cpp

/*	::::Operations Common to shared_ptr and unique_ptr::::

	shared_ptr<T> sp
	unique_ptr<T> up
	p 							used as condition
	*p
	p->mem
	p.get()
	swap(p, q)
	p.swap(q)

	::::Operations Specific to shared_ptr::::

	make_shared<T>(args)
	shared_ptr<T> p(q)
	p = q
	p.unique()
	p.use_count()

	::::Other ways to define and change shared_ptr::::

	shared_ptr<T> p(b)			b is a built-in pointer
	shared_ptr<T> p(u)			move: assume ownership from unique_ptr u
	shared_ptr<T> p(b, d)		d is a callable object to delete b
	p.reset()					free p only if p is unique
	p.reset(q)
	p.reset(q, d)

	::::Operations Specific to unique_ptr::::

	unique_ptr<T> u
	unique_ptr<T> u(b)
	unique_ptr<T, D> u(b, d)
	u = nullptr
	u.release()					relinquish control, return pointer held
	u.reset()
	u.reset(b)
	u.reset(nullptr)

*/

// In what follows:
// b 	built-in pointer
// p 	shared pointer
// q 	shared pointer
// u 	unique pointer
// v 	unique pointer
// d 	deleter
// k 	pointer to use count

// Despite the similar appearance, note that the D in shared_ptr is different from that in unique_ptr.

#ifndef SMART_PTR_H
#define SMART_PTR_H

#include "DebugDelete.h"
#include <algorithm>		// for std::swap
#include <cstddef>			// for std::size_t
#include <functional>		// for std::functional
#include <utility>			// for std::forward

template<typename T> class shared_ptr;
template<typename T, typename D = DebugDelete> class unique_ptr;

template<typename T> void swap(shared_ptr<T> &, shared_ptr<T> &);
template<typename T, typename D>
void swap(unique_ptr<T, D> &, unique_ptr<T, D> &);

template<typename T>
class shared_ptr
{
	using S = shared_ptr;
	using D = std::function<void(T *)>;
	using size_t = std::size_t;
	T * b = nullptr;
	size_t * k = new size_t(0);
	D d = D();
public:
	// default constructor
	shared_ptr() = default;
	// copy constructor
	shared_ptr(const S &);
	// copy-assignment operator
	S & operator=(const S &);
	// destructor
	~shared_ptr();
	// construct from a built-in pointer
	explicit shared_ptr(T *);
	// move: assume ownership from a unique_ptr
	template<typename X> explicit shared_ptr(unique_ptr<T, X> &&);
	// construct from a built-in pointer and specify a deleter
	shared_ptr(T *, const D &);
	// used as a condition
	explicit operator bool() const			{ return b != nullptr; }
	// dereference
	T & operator*() const					{ return *b; }
	// member access via pointer
	T * operator->() const					{ return b; }
	// return encapsulated built-in pointer
	T * get() const							{ return b; }
	// delegate to swap(S, S)
	void swap(S & p)						{ ::swap(*this, p); }
	// true if unique
	bool unique() const						{ return *k == 1; }
	// return number of sharing pointers
	size_t use_count() const				{ return *k; }
	// free p only if p is unique
	void reset(T * = nullptr, const D & = D());
private:
	void free();
	void add_count();
friend void ::swap<T>(S &, S &);
};

template<typename T, typename D>			// by default, D = DebugDelete 
class unique_ptr
{
	using U = unique_ptr;
	T * b;
	D d;
public:
	// default and other constructors
	explicit unique_ptr(T * b = nullptr, const D & d = D())	: b(b), d(d) {}
	// copy constructor deleted
	unique_ptr(const U &) = delete;			// no copy
	// copy-assignment operator deleted
	U & operator=(const U &) = delete;		// no copy(-assignment)
	// destructor
	~unique_ptr()								{ free(); }
	// u = nullptr
	U & operator=(decltype(nullptr))			{ free(); }
	// used as a condition
	explicit operator bool() const				{ return b != nullptr; }
	// dereference
	T & operator*() const						{ return *b; }
	// member access via pointer
	T * operator->() const						{ return b; }
	// return encapsulated built-in pointer
	T * get() const								{ return b; }
	// delegate to swap(U, U)
	void swap(U & u)							{ ::swap(*this, u); }
	// relinquish control
	T * release()
	{
		auto old = b;
		b = nullptr;		// set b to nullptr but do not delete b
		return old;
	}
	void reset(T * b = nullptr)
	{
		*this = nullptr;	// call operator=(decltype(nullptr))
		this->b = b;
	}
private:
	void free()
	{
		if (b) {
			d(b);
			b = nullptr;
		}
	}
friend void ::swap<T, D>(U &, U &);
friend class shared_ptr<T>;
};

// Basically, when we use make_shared<T>(a, b, c, d), we get a shared_ptr that points to a dynamically allocated object of type T, which is constructed from args a, b, c, d. It is now clear why we have to explicitly specify template argument T when calling make_shared<T>.
template<typename T, typename ... A>
shared_ptr<T> make_shared(A && ... a)
{
	return shared_ptr<T>(new T(std::forward<A>(a) ...));
}

// copy constructor
template<typename T>
shared_ptr<T>::shared_ptr(const S & p) : b(p.b), k(p.k), d(p.d)
{
	add_count();
}

// Have you considered that this may point to nullptr?
// Have you considered that p may point to nullptr?
// copy-assignment operator
template<typename T>
auto shared_ptr<T>::operator=(const S & p) -> S &
{
	if (this != &p) {
		free();
		b = p.b;
		k = p.k;
		d = p.d;
		add_count();
	}
	return *this;
}

// destructor
template<typename T>
shared_ptr<T>::~shared_ptr()
{
	free();
}

// construct from a built-in pointer
// b could be a nullptr
template<typename T>
shared_ptr<T>::shared_ptr(T * b) : b(b)
{
	add_count();
}

// move: assume ownership from unique_ptr u; no const for &
// u could be a null unique pointer
template<typename T>
template<typename X>
shared_ptr<T>::shared_ptr(unique_ptr<T, X> && u) : b(u.release()), d(u.d)
{
	add_count();
}

// construct from a built-in pointer and specify a deleter
// b could be a nullptr
template<typename T>
shared_ptr<T>::shared_ptr(T * b, const D & d) : b(b), d(d)
{
	add_count();
}

// By default, b = nullptr, d = D()
// this could point to a null shared_ptr
template<typename T>
void shared_ptr<T>::reset(T * b, const D & d)
{
	free();
	this->b = b;
	k = new size_t(0);
	add_count();
	this->d = d;
}

// 1.	if (k == nullptr) do nothing
// 2.	else if (*k == 0) do nothing
// 3.	else --*k, and if (*k == 0)
// 3.1		do delete encapsulated built-in pointer, and
// 3.2		delete k to avoid memory leaks, and
// 3.3		set k to nullptr to avoid dangling pointer
template<typename T>
void shared_ptr<T>::free()
{
	if (k && *k > 0 && --*k == 0) {
		d ? d(b) : delete b;
		delete k;
		k = nullptr;
	}
}

template<typename T>
void shared_ptr<T>::add_count()
{
	if (b)
		++*k;
}

template<typename T>
void swap(shared_ptr<T> & p, shared_ptr<T> & q)
{
	if (&p != &q) {
		std::swap(p.b, q.b);
		std::swap(p.k, q.k);
		std::swap(p.d, q.d);
	}
}

template <typename T, typename D>
void swap(unique_ptr<T, D> & u, unique_ptr<T, D> & v)
{
	// no need and no matching call for std::swap(u.d, v.d)
	std::swap(u.b, v.b);
}

#endif