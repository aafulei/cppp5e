// 18/02/28 = Wed

// Exercise 12.26: Rewrite the program on page 481 using an allocator.

// string * const p = new string[n];
// string s;
// string * q = p;
// while (cin >> s && q != p + n)
//     *q++ = s;
// const size_t size = q - p;
// // use the array
// delete[] p;

// To run, enter, for example, "a <data\spring" or "a <data\summer" in command prompt.

#include <cstddef>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// a pointer satisfies every requirement for a pointer
template<typename Iterator>
void print(Iterator b, Iterator e)
{
	while (b != e)
		cout << *b++ << endl;
	cout << endl;
}

int main()
{
	allocator<string> salloc;
	size_t n = 256;
	string * const p = salloc.allocate(n);
	auto q = p;		// top-level const in p is dismissed
	for (string line; getline(cin, line) && q != p + n;
		salloc.construct(q++, line))
		;
	const size_t size = q - p;
	print(p, q);	// use the array
	clog << "Allocated " << size << " string"
		 << (size > 1 ? "s." : ".") << endl;
	while (q != p)
		salloc.destroy(--q);
	salloc.deallocate(p, n);
	return 0;
}


