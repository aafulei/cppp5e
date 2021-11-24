// 18/02/28 = Wed

// Exercise 12.19: Define your own version of StrBlobPtr and update your StrBlob class with the appropriate friend declaration and begin and end members.

// Exercise 12.20: Write a program that reads an input file a line at a time into a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.

// Built incrementally on lp-12-02-03.cpp

// To run, enter, for example, "a data\spring" or "a data\summer" in command prompt.

#include <cstddef>
#include <fstream>
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

class StrBlobPtr;

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
	StrBlobPtr begin();	// defined outside, otherwise type is incomplete
	StrBlobPtr end();	// defined outside, otherwise type is incomplete
private:
	void check(const string &, size_type pos = 0) const;
friend class StrBlobPtr;
};

class StrBlobPtr
{
	weak_ptr<svec> wptr;
	size_t pos;
public:
	StrBlobPtr();
	StrBlobPtr(StrBlob &, size_t pos = 0);
	string & derefer() const;
	StrBlobPtr & increment();
	bool operator==(const StrBlobPtr &);	// for sb.begin() != sb.end()
	bool operator!=(const StrBlobPtr &);
private:
	shared_ptr<svec> check(const string &, size_type pos = 0) const;
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

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, sptr->size());
}

// check that pos is valid in vector<string>
// by default, i = 0, which checks the vector is non-empty
void StrBlob::check(const string & msg, size_type pos) const
{
	if (size() <= pos)
		throw out_of_range(msg);
}

StrBlobPtr::StrBlobPtr() : pos(0) {}

StrBlobPtr::StrBlobPtr(StrBlob & sb, size_t pos) : wptr(sb.sptr), pos(pos) {}

string & StrBlobPtr::derefer() const
{
	auto sptr = check("Dereference past the end!");
	return (*sptr)[pos];
}

StrBlobPtr & StrBlobPtr::increment()
{
	check("Increment past the end!");
	++pos;
	return *this;
}

bool StrBlobPtr::operator==(const StrBlobPtr & sb)
{
	return pos == sb.pos && wptr.lock() == sb.wptr.lock();
}

bool StrBlobPtr::operator!=(const StrBlobPtr & sb)
{
	return !(*this == sb);
}

shared_ptr<svec> StrBlobPtr::check(const string & msg, size_type pos) const
{
	auto sptr = wptr.lock();
	if (!sptr)
		throw runtime_error("Unbound StrBlobPtr!");
	if (pos >= sptr->size())
		throw out_of_range(msg);
	return sptr;
}

StrBlob read(const string & filename)
{
	StrBlob sb;
	ifstream ifs(filename);
	if (!ifs)
		throw runtime_error("Cannot open " + filename + "!");
	for (string line; getline(ifs, line); sb.push_back(line))
		;
	ifs.close();
	return sb;
}

// StrBlob & cannot be const, because StrBlobPtr is not pointer-to-const
void print(StrBlob & sb)
{
	for (auto sbp = sb.begin(); sbp != sb.end(); sbp.increment())
		cout << sbp.derefer() << endl;
}

int main(int argc, char ** argv)
{
	if (argc == 1) {
		cerr << "Error: Format is [command][filename]!" << endl;
		return -1;
	}
	auto sb = read(argv[1]);
	print(sb);
	return 0;
}