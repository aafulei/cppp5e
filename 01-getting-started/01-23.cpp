// 18/01/15 = Mon

// Exercise 1.23: Write a program that reads several transactions and counts how many transactions occur for each ISBN.

// Important: Assume items with the same ISBN are grouped together.

// Tip: May use file redirection <../data/records for input.

#include "Sales_item.h"
#include <iostream>

int main()
{
    Sales_item item;
    if (std::cin >> item) {
        Sales_item sum = item;
        int count = 1;
        while (std::cin >> item) {
            if (item.isbn() == sum.isbn())
                count += 1;
            else {
                std::cout << sum.isbn() << " # " << count << std::endl;
                sum = item;
                count = 1;
            }
        }
        std::cout << sum.isbn() << " # " <<  count << std::endl;
    }
    return 0;
}
