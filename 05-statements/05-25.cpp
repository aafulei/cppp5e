// 22/01/29 = Sat
// 21/12/25 = Sat
// 18/02/05 = Mon

// Exercise 5.25: Revise your program from the previous exercise to use a try
// block to catch the exception. The catch clause should print a message to the
// user and ask them to supply a new number and repeat the code inside the try.

// Exercise 5.24: Revise your program to throw an exception if the second number
// is zero. Test your program with a zero input to see what happens on your
// system if you don’t catch an exception.

// Exercise 5.23: Write a program that reads two integers from the standard
// input and prints the result of dividing the first number by the second.

// Modified from 05-24.cpp

#include <exception>
#include <iostream>

int main() {
  int a, b;
  while (true) {
    try {
      std::cin >> a >> b;
      if (std::cin && b == 0) {
        throw std::runtime_error("Divide by zero");
      }
      break;
    } catch (const std::runtime_error &e) {
      std::cout << "Can't divide by zero. Please Enter again: ";
    }
  }
  if (std::cin) {
    std::cout << a / b << std::endl;
  }
  return 0;
}
