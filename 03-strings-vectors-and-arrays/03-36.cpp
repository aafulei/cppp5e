// 21/12/23 = Thu
// 18/01/28 = Sun

// Exercise 3.36: Write a program to compare two arrays for equality. Write a
// similar program to compare two vectors.

#include <cstddef>
#include <iostream>
#include <vector>

bool compare_arrays(int a1[], std::size_t sz1, int a2[], std::size_t sz2) {
  if (sz1 != sz2) {
    return false;
  }
  for (std::size_t i = 0; i != sz1; ++i) {
    if (a1[i] != a2[i]) {
      return false;
    }
  }
  return true;
}

void demo_compare_arrays() {
  int a1[]{1, 2, 3};
  int a2[]{1, 2, 3};
  int a3[]{4, 5, 6};
  int a4[]{4, 5, 6, 7};
  if (compare_arrays(a1, 3, a2, 3)) {
    std::cout << "Arrays a1 and a2 are the same." << std::endl;
  } else {
    std::cout << "Arrays a1 and a2 are different." << std::endl;
  }
  if (compare_arrays(a2, 3, a3, 3)) {
    std::cout << "Arrays a2 and a3 are the same." << std::endl;
  } else {
    std::cout << "Arrays a2 and a3 are different." << std::endl;
  }
  if (compare_arrays(a3, 3, a4, 4)) {
    std::cout << "Arrays a3 and a4 are the same." << std::endl;
  } else {
    std::cout << "Arrays a3 and a4 are different." << std::endl;
  }
}

void demo_compare_vectors() {
  std::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v3{4, 5, 6};
  std::vector<int> v4{4, 5, 6, 7};
  if (v1 == v2) {
    std::cout << "Vectors v1 and v2 are the same." << std::endl;
  } else {
    std::cout << "Vectors v1 and v2 are different." << std::endl;
  }
  if (v2 == v3) {
    std::cout << "Vectors v2 and v3 are the same." << std::endl;
  } else {
    std::cout << "Vectors v2 and v3 are different." << std::endl;
  }
  if (v3 == v4) {
    std::cout << "Vectors v3 and v4 are the same." << std::endl;
  } else {
    std::cout << "Vectors v3 and v4 are different." << std::endl;
  }
}

int main() {
  demo_compare_arrays();
  demo_compare_vectors();
  return 0;
}
