// 19/05/26 = Sun

// Exercise 18.6: Given the following exception types and catch clauses, write a throw expression
// that creates an exception object that can be caught by each catch clause:

// (a) class exceptionType { }; catch(exceptionType *pet) { }
// (b) catch(...) { }
// (c) typedef int EXCPTYPE; catch(EXCPTYPE) { }

#include <iostream>
#include <string>

using namespace std;

class exceptionType
{
    string msg;
public:
    exceptionType(string m) : msg(m) {}
    string what() { return msg; }
};

void throw_an_exceptionType()
{
    throw new exceptionType("message");
}

typedef int EXCPTYPE;

int main()
{
    // question (a)
    try {
        throw_an_exceptionType();
    }
    catch (exceptionType * pet) {
        cerr << pet->what() << endl;
        delete pet;
    }
    // question (b)
    // catch (...) would catch any object: here []{} is a trivial lambda, which is an object
    try {
        throw []{};
    }
    catch (...) {
        cerr << "exception caught" << endl;
    }
    // question (c)
    try {
        throw 42;
    }
    catch (EXCPTYPE e) {
        cerr << e << endl;
    }
    return 0;
}
