// 22/02/24 = Thu
// 18/02/19 = Mon

// Exercise 9.34: Assuming vi is a container of ints that includes even and odd
// values, predict the behavior of the following loop. After you’ve analyzed
// this loop, write a program to test whether your expectations were correct.

// auto iter = vi.begin();
// while (iter != vi.end()) {
//   if (*iter % 2)
//     iter = vi.insert(iter, *iter);
//   ++iter;
// }

// Note: This program has problems.

#include <vector>

int main() {
  std::vector<int> vi{0, 1};
  auto iter = vi.begin();
  while (iter != vi.end()) {
    if (*iter % 2) {
      iter = vi.insert(iter, *iter);
    }
    ++iter;
  }
  return 0;
}
