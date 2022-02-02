// 22/02/02 = Wed
// 18/02/06 = Tue

// Exercise 6.4: Write a function that interacts with the user, asking for a
// number and generating the factorial of that number. Call this function from
// main.

#include <iostream>

int fact(int val) {
  if (val == 0) {
    return 1;
  }
  int res = 1;
  for (int i = 1; i <= val; ++i) {
    res *= i;
  }
  return res;
}

void interact() {
  std::cout << "Please enter a number: ";
  int i;
  std::cin >> i;
  std::cout << "fact(" << i << ") = " << fact(i) << std::endl;
}

int main() {
  interact();
  return 0;
}
