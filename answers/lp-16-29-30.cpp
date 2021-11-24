// 18/03/26 = Mon

// Exercise 16.29: Revise your Blob class to use your version of shared_ptr rather than the library version.

// Exercise 16.30: Rerun some of your programs to verify your shared_ptr and revised Blob classes. (Note: Implementing the weak_ptr type is beyond the scope of this Primer, so you will not be able to use the BlobPtr class with your revised Blob.)

// Partial Blob class template: no BlobPtr/ConstBlobPtr

// Modified from lp-12-02-03.cpp

#include "include\smart_ptr.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Blob
{
	using initializer = initializer_list<T>;
	using size_type = typename vector<T>::size_type;
	using vec = vector<T>;

	shared_ptr<vec> sptr;
public:
	Blob();
	Blob(initializer_list<T>);
	bool empty() const;
	size_type size() const;
	T & front();
	const T & front() const;
	T & back();
	const T & back() const;
	void push_back(const T &);
	void pop_back();
private:
	void check(const string &, size_type pos = 0) const;
};

template<typename T>
Blob<T>::Blob() : sptr(new vec) {}	// modified: no make_shared yet

template<typename T>
Blob<T>::Blob(initializer i) : sptr(new vec(i)) {}		// modified

template<typename T>
bool Blob<T>::empty() const
{
	return sptr->empty();
}

template<typename T>
auto Blob<T>::size() const -> size_type
{
	return sptr->size();
}

template<typename T>
auto Blob<T>::front() -> T &
{	
	check("front() on empty StrBlob!");
	return sptr->front();
}

template<typename T>
auto Blob<T>::front() const -> const T &
{	
	check("front() on empty StrBlob!");
	return sptr->front();
}

template<typename T>
auto Blob<T>::back() -> T &
{	
	check("back() on empty StrBlob!");
	return sptr->back();
}

template<typename T>
auto Blob<T>::back() const -> const T & 
{	
	check("back() on empty StrBlob!");
	return sptr->back();
}

template<typename T>
void Blob<T>::push_back(const T & s)
{
	sptr->push_back(s);
}

template<typename T>
void Blob<T>::pop_back()
{	
	check("pop_back() on empty StrBlob!");
	return sptr->pop_back();
}

template<typename T>
void Blob<T>::check(const string & msg, size_type pos) const
{
	if (size() <= pos)
		throw out_of_range(msg);
}

int main()
{
	using StrBlob = Blob<string>;
	StrBlob a;
	cout << a.empty() << endl;		// 1
	StrBlob b({"a", "an", "the"});
	b.pop_back();
	cout << b.size() << endl;		// 2
	StrBlob c(b);
	c.push_back("the");
	cout << b.size() << endl;		// 3
	cout << c.front() << endl;		// a
	cout << b.back() << endl;		// the
	return 0;
}