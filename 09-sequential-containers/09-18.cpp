// 22/02/23 = Wed
// 18/01/17 = Wed

// Exercise 9.18: Write a program to read a sequence of strings from the
// standard input into a deque. Use iterators to write a loop to print the
// elements in the deque.

#include <deque>
#include <iostream>
#include <string>

void read(std::deque<std::string> &deq) {
  for (std::string str; std::cin >> str; /* empty */) {
    deq.push_back(str);
  }
}

void print(const std::deque<std::string> &deq) {
  for (std::deque<std::string>::const_iterator it = deq.cbegin();
       it != deq.cend(); ++it) {
    std::cout << *it << std::endl;
  }
}

int main() {
  std::deque<std::string> deq;
  read(deq);
  print(deq);
  return 0;
}
