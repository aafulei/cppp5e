// 18/03/25 = Sun

// Exercise 16.19: Write a function that takes a reference to a container and prints the elements in that container. Use the container’s size_type and size members to control the loop that prints the elements.

#include <deque>
#include <forward_list>
#include <iostream>
#include <list>

using namespace std;

// forward_list does not support push_back() and size()
// at this moment, my_forward_list is not yet a template
class my_forward_list : public forward_list<char>
{
public:
	void push_back(char e)
	{
		auto it = before_begin();
		for (auto & _ :  *this)
			++it;
		insert_after(it, e);
	}
	size_type size() const
	{
		size_type n = 0;
		for (auto & _ : *this)
			++n;
		return n;
	}
};

template<typename C>
ostream & print(const C & c, ostream & os = cout)
{
	typename C::size_type n = c.size();
	auto it = c.cbegin();
	while (n-- > 0)
		os << *it++ << " ";
	return os;
}

int main()
{
	deque<char> d;
	list<char> l;
	my_forward_list m;
	for (char a = 'a'; a <= 'z'; ++a) {
		d.push_back(a);
		l.push_back(a);
		m.push_back(a);
	}
	print(d) << endl;	// print 'a' to 'z'
	print(l) << endl;	// print 'a' to 'z'
	print(m) << endl;	// print 'a' to 'z'
	return 0;
}