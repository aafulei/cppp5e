// 18/03/03 = Sat

// Exercise 13.17: Write versions of numbered and f corresponding to the previous three exercises and check whether you correctly predicted the output.

// Exercise 13.14: Assume that numbered is a class with a default constructor that generates a unique serial number for each object, which is stored in a data member named mysn. Assuming numbered uses the synthesized copy-control members and given the following function:

// void f (numbered s) { cout << s.mysn << endl; }

// what output does the following code produce?

//     numbered a, b = a, c = b;
//     f(a); f(b); f(c);

// Exercise 13.15: Assume numbered has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?

// Exercise 13.16: What if the parameter in f were const numbered &? Does that change the output? If so, why? What output gets generated? 

#include <iostream>

using namespace std;

static int serial_ex_13_14 = 0;
static int serial_ex_13_15 = 0;
static int serial_ex_13_16 = 0;

class numbered_ex_13_14
{
	int mysn;
public:
	numbered_ex_13_14() : mysn(++serial_ex_13_14) {}
friend
	void f_ex_13_14 (numbered_ex_13_14 s) { cout << s.mysn << endl; }
};

class numbered_ex_13_15
{
	int mysn;
public:
	numbered_ex_13_15() : mysn(++serial_ex_13_15) {}
	numbered_ex_13_15(const numbered_ex_13_15 & s)
						: mysn(++serial_ex_13_15) {}
friend
	void f_ex_13_15 (numbered_ex_13_15 s) { cout << s.mysn << endl; }
};

class numbered_ex_13_16
{
	int mysn;
public:
	numbered_ex_13_16() : mysn(++serial_ex_13_16) {}
	numbered_ex_13_16(const numbered_ex_13_16 & s)
						: mysn(++serial_ex_13_16) {}
friend
	void f_ex_13_16 (const numbered_ex_13_16 & s) { cout << s.mysn << endl; }
};

void f_ex_13_14 (numbered_ex_13_14);
void f_ex_13_15 (numbered_ex_13_15);
void f_ex_13_16 (const numbered_ex_13_16 &);

void process_ex_13_14()
{
	numbered_ex_13_14 a, b = a, c = b;
	f_ex_13_14(a);
	f_ex_13_14(b);
	f_ex_13_14(c);
	cout << endl;
}

void process_ex_13_15()
{
	numbered_ex_13_15 a, b = a, c = b;
	f_ex_13_15(a);
	f_ex_13_15(b);
	f_ex_13_15(c);
	cout << endl;
}

void process_ex_13_16()
{
	numbered_ex_13_16 a, b = a, c = b;
	f_ex_13_16(a);
	f_ex_13_16(b);
	f_ex_13_16(c);
	cout << endl;
}

int main()
{
	process_ex_13_14();
	process_ex_13_15();
	process_ex_13_16();
	return 0;
}