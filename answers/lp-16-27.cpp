// 18/03/25 = Sun

// Exercise 16.27: For each labeled statement explain what, if any, instantiations happen. If a template is instantiated, explain why; if not, explain why not.

#include <string>

using namespace std;

template <typename T>
class Stack
{
	using whatever = typename T::i_am_sure_you_don_t_have_a_name_like_this;
};

void f1(Stack<char>);	// (a): no instantiation - only declaraion

class Exercise
{
    Stack<double> &rsd;	// (b): no instantiation - only reference to
    // Stack<int> si;	// (c): instantiation - must know size to allocate
};

int main()
{
    Stack<char> *sc;	// (d): no instantiation - only pointer to
    // f1(*sc);			// (e): instantiation - call the function
    // int iObj = sizeof(Stack<string>); // (f): instantiation - to know size
    return 0;
}