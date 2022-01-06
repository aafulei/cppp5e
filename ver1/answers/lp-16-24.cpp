// 18/03/25 = Sun

// Exercise 16.24: Add a constructor that takes two iterators to your Blob template.

#include "include\Blob.h"
#include <forward_list>
#include <iostream>

using namespace std;

int main()
{
	forward_list<int> flst = {1, 3, 5, 7, 9};
	Blob<int> b(flst.cbegin(), flst.cend());
	cout << b << endl;
	return 0;
}
