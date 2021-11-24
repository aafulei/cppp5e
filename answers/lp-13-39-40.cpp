// 18/03/05 = Mon
// 18/03/06 = Tue: Exercise 13.40 & redo

// Exercise 13.39: Write your own version of StrVec, including versions of reserve, capacity (§ 9.4, p. 356), and resize (§ 9.3.5, p. 352).

// Exercise 13.40: Add a constructor that takes an initializer_list<string> to your StrVec class.

// To turn on debug information: g++ lp-13-39-40.cpp -D DEBUG
// To turn it off: compile as usual

#include "include\StrVec.h"
#include "source\StrVec.cpp"

using namespace std;

template<typename V>
void print(const V & v)
{
	for (const auto & e : v)
		cout << e << " ";
	cout << "." << endl;
}

void line()
{
#ifdef DEBUG
	cout << string(50, '-') << endl;
#endif
}

void test()
{
	StrVec sv; 										line();
	sv.push_back("Apple"); 							line();
	sv.push_back("Boy"); 							line();
	sv.push_back("Cake"); 							line();
	sv.push_back("Dog"); 							line();
	StrVec sv2 = sv; 								line();
	print(sv); 										line();
	sv2.at(2) = "Cat";								line();
	print(sv2); 									line();
	StrVec sv3;										line();
	sv3 = sv2; 										line();
	sv.reserve(2); 									line();
	sv2.reserve(100); 								line();
	sv3.resize(100); 								line();
	print(sv3); 									line();
	sv3.resize(2); 									line();
	print(sv3); 									line();
	StrVec sv4 = {"Apple", "Boy", "Cat", "Duke"};	line();
	print(sv4); 									line();
}

int main()
{
	test();
	return 0;
}