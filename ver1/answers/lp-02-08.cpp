// 18/01/30 = Tue

// Exercise 2.8: Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.

#include <iostream>

// std::endl inserts a newline and flush the stream
// std::ends inserts a null character but does not flush the stream
// std::flush just flushes the stream

int main()
{
	std::cout << "\062\115\012" << std::flush;
	std::cout << '\062' << '\011'	// alternatively: '\t'
			  << '\115' << '\012'	// alternatively: '\n'
		 	  << std::flush;
	return 0;
}