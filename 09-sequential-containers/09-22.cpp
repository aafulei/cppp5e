// 22/02/23 = Wed
// 18/02/18 = Sun
// 18/01/17 = Wed

// Exercise 9.22: Assuming iv is a vector of ints, what is wrong with the
// following program? How might you correct the problem(s)?

// vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
// while (iter != mid)
//   if (*iter == some_val)
//     iv.insert(iter, 2 * some_val);

// Answer:
//
// Problems -
//
// 1. the program should not store the iterator value in mid
// 2. the program should update iter using the return value from insert()
// 3. the program should update iter at the end of each loop
// 4. if `mid` means the original middle, the program should count the number of
// inserted elements and adjust accordingly

#include <iostream>
#include <vector>

void print(const std::vector<int> &vec) {
  for (int i = 0; int elem : vec) { // C++20
    std::cout << (i++ == 0 ? "" : " ") << elem;
  }
  std::cout << std::endl;
}

void test(std::vector<int> iv) {
  std::cout << "Original: ";
  print(iv);
  int some_val = 1;
  std::vector<int>::iterator iter = iv.begin();
  for (int count = 0; iter != iv.begin() + (iv.size() + count) / 2; // adjust
       ++iter) {
    if (*iter == some_val) {
      iter = iv.insert(iter, 2 * some_val) + 1;
      ++count;
    }
  }
  std::cout << "Inserted: ";
  print(iv);
}

int main() {
  test({1, 0});
  test({1, 1, 0});
  test({0, 0, 1, 1, 0, 1, 1, 0});
  return 0;
}
