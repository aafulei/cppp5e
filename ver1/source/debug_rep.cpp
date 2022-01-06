// 18/03/28 = Wed: build upon lp-16-48.cpp

// Source code for overloaded set of debug_rep

// for lp-16-56-57.cpp, lp-16-65-67.cpp

#include "..\include\debug_rep.h"
#include <iostream>
#include <string>

using namespace std;

string debug_rep(const string & s)
{
	#ifdef DEBUG
		clog << "Call: debug_rep(const string &)" << endl;
	#endif
	return '"' + s + '"';
}

#ifndef SPEC
string debug_rep(const char * p)
{
	#ifdef DEBUG
		clog << "Call: debug_rep(const char *)" << endl;
	#endif
	return debug_rep(string(p));
}

string debug_rep(char * p)
{
	#ifdef DEBUG
		clog << "Call: debug_rep(char *)" << endl;
	#endif
	return debug_rep(string(p));
}
#endif	// endif for #ifndef SPEC