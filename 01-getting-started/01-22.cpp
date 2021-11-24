// 18/01/15 = Mon

// Exercise 1.22: Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions
// that were read.

// Tip: May use file redirection <../data/records for input.

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item, sum;
    std::cin >> item;
    sum = item;
    while (std::cin >> item && item.isbn() == sum.isbn())
        sum += item;
    std::cout << sum << std::endl;
    return 0;
}
