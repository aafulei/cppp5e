// 22/02/23 = Wed
// 18/01/17 = Wed

// Exercise 9.19: Rewrite the program from the previous exercise to use a list.
// List the changes you needed to make.

// Exercise 9.18: Write a program to read a sequence of strings from the
// standard input into a deque. Use iterators to write a loop to print the
// elements in the deque.

// Modified from 09-18.cpp

#include <list>
#include <iostream>
#include <string>

void read(std::list<std::string> &lst) {
  for (std::string str; std::cin >> str; /* empty */) {
    lst.push_back(str);
  }
}

void print(const std::list<std::string> &lst) {
  for (std::list<std::string>::const_iterator it = lst.cbegin();
       it != lst.cend(); ++it) {
    std::cout << *it << std::endl;
  }
}

int main() {
  std::list<std::string> lst;
  read(lst);
  print(lst);
  return 0;
}
