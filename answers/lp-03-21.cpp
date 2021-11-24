// 17/10/23 = Mon

// Exercise 3.21: Redo the first exercise from § 3.3.3 (p. 105) using iterators.

// Exercise 3.16: Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template<typename V>
void vprint(V const& v)		// no need to spell out std::vector here
{
	for (auto it = v.cbegin(); it != v.cend(); ++it)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	vector<int> v1;
	cout << "v1 size = " << v1.size() << ";\t" << "contents: "; vprint(v1);
	vector<int> v2(10);
	cout << "v2 size = " << v2.size() << ";\t" << "contents: "; vprint(v2);
	vector<int> v3(10, 42);
	cout << "v3 size = " << v3.size() << ";\t" << "contents: "; vprint(v3);
	vector<int> v4 {10};
	cout << "v4 size = " << v4.size() << ";\t" << "contents: "; vprint(v4);
	vector<int> v5{10, 42};
	cout << "v5 size = " << v5.size() << ";\t" << "contents: "; vprint(v5);
	vector<string> v6{10};
	cout << "v6 size = " << v6.size() << ";\t" << "contents: "; vprint(v6);
	vector<string> v7{10, "hi"};
	cout << "v7 size = " << v7.size() << ";\t" << "contents: "; vprint(v7);
	return 0;
}