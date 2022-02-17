// 22/02/17 = thu
// 18/01/17 = Wed
// 17/10/25 = Wed

// Exercise 9.13: How would you initialize a vector<double> from a list<int>?
// From a vector<int>? Write code to check your answers.

#include <vector>
#include <list>
#include <iostream>

int main() {
  std::list<int> lst {1,2,3};
  std::vector<double> vec(lst.begin(), lst.end());
  for (double elem : vec) {
    std::cout << elem << std::endl;
  }
  return 0;
}
