// 18/03/06 = Tue

// To call a non-static member function, we should capture this.
// To call a static member function, we only need to be in scope.

#include <iostream>

using namespace std;

struct A
{
	void f()
	{
		cout << __func__ << endl;
	}
    static void g()
    {
        cout << __func__ << endl;
    }
    void h()
    {
    	[this](){f();}();
    	// Alternatively:
    	// [&](){f();}()
    	[](){g();}();
    }
};

int main() 
{  
	A().h();
} 