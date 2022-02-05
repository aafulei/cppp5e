// 21/12/18 = Sat
// 19/07/02 = Tue
// 19/05/28 = Tue
// 18/01/29 = Mon

// Exercise 1.17: What happens in the program presented in this section if the
// input values are all equal? What if there are no duplicated values?

// Copied from the textbook

#include <iostream>

int main() {
  int currVal = 0, val = 0;
  if (std::cin >> currVal) {
    int cnt = 1;
    while (std::cin >> val) {
      if (val == currVal) {
        ++cnt;
      } else {
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
        currVal = val;
        cnt = 1;
      }
    }
    std::cout << currVal << " occurs " << cnt << " times" << std::endl;
  }
  return 0;
}
