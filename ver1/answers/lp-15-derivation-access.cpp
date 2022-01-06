// 18/03/17 = Sat

// Demonstrate derivation access specifiers:
// public inheritance: everyone sees that you inherit from your father
// protected inheritance: only your children see that you inherit from your father
// private inheritance: no one but you see that you inherit from your father

#include <iostream>

using namespace std;

struct B
{
public:
	void a() {}
protected:
	void b() {}
private:
	void c() {}
};

void d(B *) {}

struct D1 : public B
{
	void f() { a(); }
	void g() { b(); }
	void h() { d(this); }
};

struct D2 : protected B
{
	void f() { a(); }
	void g() { b(); }
	void h() { d(this); }
};

struct D3 : private B
{
	void f() { a(); }
	void g() { b(); }
	void h() { d(this); }
};

struct DD : D2
{
	// your child sees that you inherit from your father so that your child may access, as an implementor, your father's public/protected member
	void h() { d(this); }
	void p() { a(); }
	void q() { b(); }
};


int main()
{
	D1 d1;
	D2 d2;
	D3 d3;

	d1.a();
	// d1.b();
	// d1.c();
	// d2.a();
	// d2.b();
	// d2.c();
	// d3.a();
	// d3.b();
	// d3.c();

	DD dd;
	// dd.a();
	// dd.b();
	// dd.c();

	d(&d1);
	// d(&d2);
	// d(&d3);
	// d(&dd);

	return 0;
}