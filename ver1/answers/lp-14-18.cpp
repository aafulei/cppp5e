// 18/03/12 = Mon

// Exercise 14.18: Define relational operators for your StrBlob, StrBlobPtr, StrVec, and String classes.

// std::lexicographical_compare: the kind of comparison generally used to sort words alphabetically in dictionaries

// We refuse to define < and the like for the StrBlob class, because we treat a StrBlob as pointer-like. (For value-like containers, use StrVec or just vector<string>.) For two StrBlobs, sb1 == sb2 if and only if they refer to the same resoures. In this regard, we cannot find a proper strict weak ordering in consistency with the == we defined in lp-14-16.cpp.

// Relationship:
// StrBlob  	: undefined
// StrBlobPtr	: compare position, must refer to the same StrBlob
// StrVec		: compare lexicographically
// String		: compare lexicographically

#include "include\StrBlob.h"
#include "include\StrBlobPtr.h"
#include "include\String.h"
#include "include\StrVec.h"
#include "source\StrBlob.cpp"
#include "source\StrBlobPtr.cpp"
#include "source\String.cpp"
#include "source\StrVec.cpp"
#include <iostream>

using namespace std;

int main()
{
	StrBlob sb = {"a", "an", "the"};
	StrBlobPtr p1(sb);
	StrBlobPtr p2 = sb.begin();
	StrBlobPtr p3 = sb.end();
	// 0011 1010
	cout << (p1 < p2)  << (p1 > p2)
	 	 << (p1 <= p2) << (p1 >= p2) << " "
	 	 << (p2 < p3)  << (p2 > p3)
	 	 << (p2 <= p3) << (p2 >= p3) << endl;

	StrVec sv1 = {"a", "an", "the"};
	StrVec sv2 = {"a", "an", "the"};
	StrVec sv3 = {"a", "an"};
	// 0011 0101
	cout << (sv1 < sv2)	 << (sv1 > sv2)
		 << (sv1 <= sv2) << (sv1 >= sv2) << " "
		 << (sv2 < sv3)	 << (sv2 > sv3)
		 << (sv2 <= sv3) << (sv2 >= sv3) << endl;

	String s1 = "Hello, World!";
	String s2 = "Hello, World!";
	String s3 = "Hello,";
	String s4 = "World!";
	// 0011 0101 1010
	cout << (s1 < s2)  << (s1 > s2)
		 << (s1 <= s2) << (s1 >= s2) << " "
		 << (s2 < s3)  << (s2 > s3)
		 << (s2 <= s3) << (s2 >= s3) << " "
		 << (s3 < s4)  << (s3 > s4)
		 << (s3 <= s4) << (s3 >= s4) << endl;

	return 0;
}

