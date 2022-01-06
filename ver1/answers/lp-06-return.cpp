// 18/01/26 = Fri

#include <iostream>

int foo() {}

int main()
{
	std::cout << "Undefined value: " << foo() << std::endl;
	std::cout << "C++11: If control reaches the end of main without "
	"encountering a return statement, the effect is that of executing return 0; "
	"Flowing off the end of a function is equivalent to a return with no value; "
	"this results in undefined behavior in a value-returning function." << std::endl;
}