// 18/02/14 = Wed
// 18/02/28 = Wed: minor changes to stay consistent with lp-12-19-20.cpp

// Exercise 12.2: Write your own version of the StrBlob class including the const versions of front and back.

// Exercise 12.3: Does this class need const versions of push_back and pop_back? If so, add them. If not, why aren’t they needed?

// Answer: No. Functions push_back() and pop_back() change the object that the shared pointer points to. Though it could be legal to do so, it would break the const promise made by the implicit this pointer that it won't make any changes.

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
using initializer = initializer_list<string>;
using size_type = vector<string>::size_type;
using svec = vector<string>;

class StrBlob
{
	shared_ptr<svec> sptr;
public:
	StrBlob();
	StrBlob(initializer_list<string>);
	bool empty() const;
	size_type size() const;
	string & front();
	const string & front() const;
	string & back();
	const string & back() const;
	void push_back(const string &);
	void pop_back();
private:
	void check(const string &, size_type pos = 0) const;
};

StrBlob::StrBlob() : sptr(make_shared<svec>()) {}

StrBlob::StrBlob(initializer i) : sptr(make_shared<svec>(i)) {}

bool StrBlob::empty() const
{
	return sptr->empty();
}

size_type StrBlob::size() const
{
	return sptr->size();
}

string & StrBlob::front()
{	
	check("front() on empty StrBlob!");
	return sptr->front();
}

const string & StrBlob::front() const
{	
	check("front() on empty StrBlob!");
	return sptr->front();
}

string & StrBlob::back()
{	
	check("back() on empty StrBlob!");
	return sptr->back();
}

const string & StrBlob::back() const
{	
	check("back() on empty StrBlob!");
	return sptr->back();
}

void StrBlob::push_back(const string & s)
{
	sptr->push_back(s);
}

void StrBlob::pop_back()
{	
	check("pop_back() on empty StrBlob!");
	return sptr->pop_back();
}

// verify that pos is valid in vector<string>
// by default, pos = 0, which checks the vector is non-empty
void StrBlob::check(const string & msg, size_type pos) const
{
	if (size() <= pos)
		throw out_of_range(msg);
}

int main()
{
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