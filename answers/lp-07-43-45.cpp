// 18/02/10 = Sat

// Exercise 7.43: Assume we have a class named NoDefault that has a constructor that takes an int, but has no default constructor. Define a class C that has a member of type NoDefault. Define the default constructor for C.

// Exercise 7.44: Is the following declaration legal? If not, why not?
 
// vector<NoDefault> vec(10);

// Answer: No. Because when vec is value initialized, its elements are default initialized. However, there is no default constructor in class NoDefault.
 
// Exercise 7.45: What if we defined the vector in the previous exercise to hold objects of type C?

// Answer: Yes, that's legal. Because C has a valid default constructor.

class NoDefault
{
public:
	NoDefault(int) {}
};

class C
{
	NoDefault nd;
public:
	C() : nd{0} {}
	// alternatively:
	// C() : nd(0) {}
	// C() : nd(NoDefault(0)) {}
};

int main()
{
	C c;
	return 0;
}