// 18/01/17 = Wed

// Exercise 9.27: Write a program to find and remove the odd-valued elements in a forward_list<int>.

#include <forward_list>
#include <iostream>

using std::cout;
using std::endl;
using std::forward_list;


void remove(forward_list<int> & flst)
{
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2 == 1) {
			curr = flst.erase_after(prev);
		}
		else {
			prev = curr;
			++curr;
		}
	}
}

template<typename C>
void print(const C & c)
{
	for (const auto & e : c)
		cout << e << " ";
	cout << endl;
}

int main()
{
	forward_list<int> flst = {0, 1, 2, 3, 4};
	print(flst);
	remove(flst);
	print(flst);
	return 0;
}