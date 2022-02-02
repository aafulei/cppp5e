// 22/02/02 = Wed
// 18/02/07 = Wed

// Exercise 6.38: Revise the arrPtr function on to return a reference to the
// array.

// int odd[] = {1,3,5,7,9};
// int even[] = {0,2,4,6,8};
// decltype(odd) *arrPtr(int i) {
//   return (i % 2) ? &odd : &even;
// }

#include <iostream>

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype((odd)) arrRef(int i) { return (i % 2) ? odd : even; }

// double elements in the arrays and print them out:
// 0 4 8 12 16
// 2 6 10 14 18
void test() {
  for (int &i : arrRef(0)) {
    i *= 2;
  }
  for (int i : arrRef(0)) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  for (int &i : arrRef(1)) {
    i *= 2;
  }
  for (int i : arrRef(1)) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main() {
  test();
  return 0;
}
