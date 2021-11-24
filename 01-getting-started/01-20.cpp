// 18/01/15 = Mon

// Exercise 1.20: http://www.informit.com/title/032174113 contains a copy of Sales_item.h in the Chapter 1 code directory.
// Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing
// each transaction to the standard output.

// Tip: May use file redirection <../data/records for input.

#include "Sales_item.h"
#include <iostream>

int main()
{
    Sales_item item;
    while (std::cin >> item)
        std::cout << item << std::endl;
    return 0;
}
