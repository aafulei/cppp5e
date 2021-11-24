// 19/05/28 = Tue

// Exercise 1.15: Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself
// with the messages the compiler generates.

// Note: This program won't compile.

#include <iostream>

void print(int a)
{
    std::cout << a << std::endl;
}

// syntax error: missing ) in parameter list for main
int main ( {
    // syntax error: used colon, not a semicolon, after endl
    std::cout << "Read each file." << std::endl:
    // syntax error: missing quotes around string literal
    std::cout << Update master. << std::endl;
    // syntax error: second output operator is missing
    std::cout << "Write new master." std::endl;
    // type error: passing a string literal to a function that expects an int argument
    print("Hello, World!");
    // declaration error: forgetting to use std:: for a name from the library
    cout << "Hello, World!" << endl;
    // declaration error: misspelling the name of an identifier:
    std::count << "Hello, World!" << std::end;
    // syntax error: missing ; on return statement
    return 0
}
