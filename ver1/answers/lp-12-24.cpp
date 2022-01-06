// 18/02/28 = Wed

// Exercise 12.24: Write a program that reads a string from the standard input into a dynamically allocated character array. Describe how your program handles varying size inputs. Test your program by giving it a string of data that is longer than the array size you’ve allocated.

// Like a vector, double the size of the dynamic array whenever it's full.

// To run, enter, for example, "a <data\spring" or "a <data\gatsby" in command prompt.

#include <cstddef>
#include <cstdio>		// for getchar() and EOF
#include <cstring>
#include <iostream>
#include <stdexcept>

using namespace std;

char * reallocate(char * src, size_t n)
{
	try {
		char * dest = new char[n]{};
		strcpy(dest, src);
		delete[] src;
		return dest;
	}
	catch(bad_alloc & ba) {
		cerr << ba.what() << endl;
	}
}

char * read(size_t & n)
{
	char * a = new char[n]{};
	size_t i = 0;
	// C-style: read everything including whitespaces until EOF
	// c is an int rather than char so as to understand EOF
	for (int c; (c = getchar()) != EOF; a[i++] = c) {
		if (i == n - 1) {
			n *= 2;
			a = reallocate(a, n);
		}
	}
	return a;
}

void process(const char * a, const size_t & n)
{
	string s(a);
	delete[] a;
	int pos = s.size() - 100;
	if (pos <= 0)
		cout << s << endl << endl;
	else {
		cout << "Last 100 characters:\n..." << endl;
		cout << s.substr(pos) << endl << endl;
	}
	clog << "Size of dynamically allocated array = " << n << endl;
	clog << "Legnth of string = " << s.size() << endl;
}

int main()
{
	size_t n = 256;
	char * a = read(n);
	process(a, n);
	return 0;
}