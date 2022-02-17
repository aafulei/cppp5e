// 22/02/17 = Thu
// 18/01/17 = Wed

// Exercise 9.11: Show an example of each of the six ways to create and
// initialize a vector. Explain what values each vector contains.

#include <iostream>
#include <vector>

void print(const std::vector<int> &v, const std::string &name = "") {
  if (!name.empty()) {
    std::cout << name << ": ";
  }
  for (bool first = true; int elem : v) { // C++20
    if (first) {
      first = false;
    } else {
      std::cout << " ";
    }
    std::cout << elem;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> v1;                       // default init
  std::vector<int> v2(v1);                   // copy init
  std::vector<int> v3{1, 2, 3};              // list init
  std::vector<int> v4(v3.begin(), v3.end()); // copy init from iterator range
  std::vector<int> v5(5);                    // value init with size only
  std::vector<int> v6(6, 6);                 // value init with values
  print(v1, "v1");                           // (empty)
  print(v2, "v2");                           // (empty)
  print(v3, "v3");                           // 1 2 3
  print(v4, "v4");                           // 1 2 3
  print(v5, "v5");                           // 0 0 0 0 0
  print(v6, "v6");                           // 6 6 6 6 6 6
  return 0;
}
