// 18/01/29 = Mon

// Exercise 1.16: Write your own version of a program that prints the sum of a set of integers read from cin.

// Tip: May use file redirection <../data/digits for input.

#include <iostream>

int main()
{
    int sum = 0, num;
    while (std::cin >> num)
        sum += num;
    std::cout << sum << std::endl;
    return 0;
}
