// 18/03/27 = Tue

// Exercise 16.48: Write your own versions of the debug_rep functions.

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template<typename T> string debug_rep(const T &);
template<typename T> string debug_rep(T *);
string debug_rep(const char *);
string debug_rep(char *);
string debug_rep(const string &);

template<typename T>
string debug_rep(const T & t)
{
	clog << "Inst: debug_rep(const T &)" << endl;
	ostringstream oss;
	oss << t;
	return oss.str();
}

template<typename T>
string debug_rep(T * p)
{
	clog << "Inst: debug_rep(T *)" << endl;
	ostringstream oss;
	oss << "Pointer: ";
	if (p)
		oss << *p;
	else
		oss << "nullptr";
	return oss.str();
}

string debug_rep(const string & s)
{
	clog << "Call: debug_rep(const string &)" << endl;
	return '"' + s + '"';
}

string debug_rep(const char * p)
{
	clog << "Inst: debug_rep(const char *)" << endl;
	return debug_rep(string(p));
}

string debug_rep(char * p)
{
	clog << "Inst: debug_rep(char *)" << endl;
	return debug_rep(string(p));
}

void line()
{
	cout << string(50, '-') << endl;
}

int main()
{
	char a[] = "Hello";
	string s = "World";
	int i = 42;
	double * n = nullptr;
	cout << debug_rep(a) << endl;		line();	// debug_rep(char *)
	cout << debug_rep(s) << endl;		line();	// debug_rep(const string &)
	cout << debug_rep("Hi") << endl;	line();	// debug_rep(const char *)
	cout << debug_rep(i) << endl;		line();	// debug_rep(const T &)
	cout << debug_rep(&i) << endl;		line();	// debug_rep(T *)
	cout << debug_rep(n) << endl;				// debug_rep(T *)
	return 0;
}


/* ---------- postscript ----------

	Q1:	To handle C-style char strings, why cannot we write a template like

	template<size_t N>
	string debug_rep(const char (& a)[N])

	A1: That way this template is only equally good as the other two templates.

	Q2: To handdle C-style char strings, why do we have to provide two overloaded functions, one with char * and the other with const char *?

	A2: Suppose, on one hand, we had provided only the char * version, then it wouldn't work for a char array like char a[] = "Hello". On the other hand, had we provided only the const char * version, then the template with T * would be a better match. Note that the const in const char * is low-level. Binding a non-const char to a const char * would bring the match from tier 1 to tier 2.

	Match tiers: (page 245)

	1. 	Exact match, including:
	1.1	array/function-to-pointer conversion
	1.2 adding/dropping a top-level const
	2.	conversions with low-level const
	3.  integral promotions
	4. 	arithmetic/pointer conversions
	5.	user-defined conversions

----------------------------------- */