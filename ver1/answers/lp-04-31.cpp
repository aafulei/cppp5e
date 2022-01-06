// 18/02/03 = Sat

// Exercise 4.31: The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

// vector<int>::size_type cnt = ivec.size();
// // assign values from size... 1 to the elements in ivec
// for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
// 	ivec[ix] = cnt;

// Answer: there is no change to make. In standalone expressions, ++i is no difference to ++i in effect.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> ivec(10);
	vector<int>::size_type cnt = ivec.size();
	for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
		ivec[ix] = cnt;
	for (auto i : ivec)
		cout << i << " ";
	cout << endl;
	return 0;
}