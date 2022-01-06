// 18/02/11 = Sun

// Exercise 7.53: Define your own version of Debug.

#include <iostream>

using std::cerr;
using std::endl;

class Debug
{
	bool hw;	// hardware errors other than IO errors
	bool io;	// IO errors
	bool ot;	// others
public:
	constexpr Debug(bool b = true) : hw(b), io(b), ot(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), ot(o) {}
	// Important: By C++14, const cannot be omitted. Why?
	constexpr bool any() const
	{	return hw || io || ot; }
	void set_hw(bool b) {	hw = b; }
	void set_io(bool b) {	io = b; }
	void set_ot(bool b) {	ot = b; }
};

int main()
{
	constexpr Debug dio(false, true, false);
	if (dio.any())
		cerr << "Print error messages." << endl;
	return 0;
}