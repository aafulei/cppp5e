// 18/03/17 = Sat

// Exercise 15.20: Write code to test your answers to the previous two exercises.

// See lp-15-18-19.md for Ex 15.18 and Ex 15.18.

class Base
{
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base
{
	void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base
{
	void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base
{
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv
{
	// void memfcn(Base &b) { b = *this; }							// illegal
};

struct Derived_from_Protected : public Prot_Derv
{
	void memfcn(Base &b) { b = *this; }
};



int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Base * p1 = &d1;		//  d1 has type Pub_Derv
	// Base * p2 = &d2;		//  d2 has type Priv_Derv				// illegal
	// Base * p3 = &d3;		//  d3 has type Prot_Derv				// illegal
	// Base * p4 = &dd1;	//  dd1 has type Derived_from_Public	// illegal
	// Base * p5 = &dd2;	//  dd2 has type Derived_from_Private	// illegal
	// Base * p6 = &dd3;	//  dd3 has type Derived_from_Protected	// illegal
}