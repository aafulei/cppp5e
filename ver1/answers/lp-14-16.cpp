// 18/03/12 = Mon

// Exercise 14.16: Define equality and inequality operators for your StrBlob (§ 12.1.1, p. 456), StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p. 526), and String (§ 13.5, p. 531) classes.

// Equality:
// StrBlob  	: if two objects refer to the same resources
// StrBlobPtr	: if two objects refer to the same resources
// StrVec		: if two objects have the same contents
// String		: if two objects have the same contents

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

	StrVec sv1 = {"a", "an", "the"};
	StrVec sv2 = {"a", "an", "the"};
	StrVec sv3 = {"a", "an"};
	StrVec sv4 = {"a", "and"};
	cout << (sv1 == sv2) << ends;	// 1
	cout << (sv2 == sv3) << ends;	// 0
	cout << (sv3 == sv4) << endl;	// 0

	String s1 = "Hello, World!";
	String s2 = "Hello, World!";
	String s3 = "Hello";
	String s4 = "World";
	cout << (s1 == s2) << ends;	// 1
	cout << (s2 == s3) << ends;	// 0
	cout << (s3 == s4) << endl;	// 0

	return 0;
}
