// 18/03/24 = Sat
 
// Exercise 16.12: Write your own version of the Blob and BlobPtr templates. including the various const members that were not shown in the text.

// Test code taken form lp-14-27-32.cpp, lp-14-16.cpp and lp-14-18.cpp, using StrBlob = Blob<string>, using StrBlobPtr = BlobPtr<string>

#include "include\Blob.h"
#include "include\BlobPtr.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

using StrBlob = Blob<string>;
using StrBlobPtr = BlobPtr<string>;

class StrBlobPtrPtr
{
	StrBlobPtr * p;
public:
	StrBlobPtrPtr(StrBlobPtr sbp) : p(&sbp) {}
	StrBlobPtr & operator*()  const			{ return *p;}
	StrBlobPtr * operator->() const 		{ return p;	}
};

class NestedPtr
{
	StrBlobPtr * p;
public:
	NestedPtr(StrBlobPtr sbp) : p(&sbp)		{}
	StrBlobPtr operator->() const 			{ return *p;}
	// Alternatively:
	// StrBlobPtr & operator->() const 		{ return *p;}
};

void line()
{
	cout << string(50, '-') << endl;
}


int main()
{
	// lp-14-27-32.cpp
	StrBlob sb = {"a", "an", "the", "that", "these", "theirs"};

	for (auto it = sb.begin(); it != sb.end(); ++it)// it is a StrBlobPtr
		cout << *it << endl;
	line();

	auto it = sb.cend() - 1;					// it is a ConstStrBlobPtr
	do
		cout << *it << endl;
	while (it-- != sb.cbegin());
	line();

	cout << "There are " << sb.cend() - sb.cbegin() << " words in { ";
	for (const auto & s : sb)
		cout << s << " ";
	cout << "}" << endl;
	line();

	for (auto it = sb.cbegin(); it != sb.cend(); ++it)
		cout << it->size() << endl;
	line();

	for (auto it = sb.begin(); it != sb.end(); ++it)
		transform(it->cbegin(), it->cend(), it->begin(), ::toupper);
	for (const auto & s : sb)
		cout << s << endl;
	line();

	for (auto it = sb.begin(), it2 = sb.end() - 1;
		it != sb.begin() + (sb.end() - sb.begin()) / 2; ++it, --it2)
		swap(*it, *it2);
	for (const auto & s : sb)
		cout << s << endl;
	line();

	StrBlobPtrPtr pp(sb.begin());
	cout << **pp << " has "
		 << (*pp)->size() << " letters." << endl;
	line();

	NestedPtr np(sb.end() - 3);
	cout << *(np.operator->()) << " has "
		 << np->size() << " letters." << endl;
	line();

	// lp-14-16.cpp
	StrBlob sb1 = {"a", "an", "the"};
	StrBlob sb2 = sb1;
	StrBlob sb3 = {"a", "an", "the"};
	cout << (sb1 == sb2) << ends;	// 1
	cout << (sb2 == sb3) << endl;	// 0

	StrBlobPtr sbp1(sb1);
	StrBlobPtr sbp2(sb2);
	StrBlobPtr sbp3(sb3);
	StrBlobPtr sbp4 = sb3.begin();
	cout << (sbp1 == sbp2) << ends;	// 1
	cout << (sbp2 == sbp3) << ends;	// 0
	cout << (sbp3 == sbp4) << endl;	// 1
	line();

	// lp-14-18.cpp
	StrBlobPtr p1(sb);
	StrBlobPtr p2 = sb.begin();
	StrBlobPtr p3 = sb.end();
	// 0011 1010
	cout << (p1 < p2)  << (p1 > p2)
	 	 << (p1 <= p2) << (p1 >= p2) << " "
	 	 << (p2 < p3)  << (p2 > p3)
	 	 << (p2 <= p3) << (p2 >= p3) << endl;

	return 0;
}