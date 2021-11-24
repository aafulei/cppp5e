// 18/01/15 = Mon

// Exercise 1.21: Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

// Tip: May use file redirection <../data/records for input.

#include "Sales_item.h"
#include <iostream>

int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    if (item1.isbn() != item2.isbn())
        std::cerr << "Error: ISBNs differ!" << std::endl;
    else
        std::cout << item1 + item2 << std::endl;
    return 0;
}
