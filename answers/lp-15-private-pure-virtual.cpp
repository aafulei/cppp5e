// 18/03/19 = Mon

#include <iostream>

using namespace std;

struct A
{
private:
	virtual void f() = 0;
};

void A::f()
{
	clog << "A::f()" << endl;
}

struct B : A
{
	virtual void f()
	{
		// A::f();
		clog << "B::f()" << endl;
	}
};


int main()
{
	B b;
	b.f();
	return 0;
}