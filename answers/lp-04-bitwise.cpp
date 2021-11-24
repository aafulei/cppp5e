// 18/02/03 = Sat

// textbook's application of bitwise operations

#include <iostream>

using std::cout;
using std::endl;


int main()
{
	unsigned long quiz1 = 0; // we'll use this value as a collection of bits
	1UL << 27; // generate a value with only bit number 27 set
	quiz1 |= 1UL << 27; // indicate student number 27 passed
	quiz1 &= ~(1UL << 27); // student number 27 failed
	bool status = quiz1 & (1UL << 27); // how did student number 27 do?
	cout << status << endl;	// 0 (false)
	return 0;
}