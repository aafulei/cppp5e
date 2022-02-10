// 21/12/23 = Thu
// 17/10/22 = Sun

// Exercise 3.21: Redo the first exercise from § 3.3.3 (p. 105) using iterators.

// Exercise 3.16: Write a program to print the size and contents of the vectors
// from exercise 3.13. Check whether your answers to that exercise were correct.
// If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.

// Exercise 3.13: How many elements are there in each of the following
// vectors? What are the values of the elements?

// (a) vector<int> v1;
// (b) vector<int> v2(10);
// (c) vector<int> v3(10, 42);
// (d) vector<int> v4{10};
// (e) vector<int> v5{10, 42};
// (f) vector<string> v6{10};
// (g) vector<string> v7{10, "hi"};

// Modified from 03-16.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename V> std::string str(const V &vec) {
  std::ostringstream oss;
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) {
      oss << ",";
    }
    oss << *it;
  }
  return oss.str();
}

int main() {
  std::vector<int> v1;
  std::vector<int> v2(10);
  std::vector<int> v3(10, 42);
  std::vector<int> v4{10};
  std::vector<int> v5{10, 42};
  std::vector<std::string> v6{10};
  std::vector<std::string> v7{10, "hi"};
  std::cout << "v1: " << v1.size() << "\t[" << str(v1) << "]" << std::endl;
  std::cout << "v2: " << v2.size() << "\t[" << str(v2) << "]" << std::endl;
  std::cout << "v3: " << v3.size() << "\t[" << str(v3) << "]" << std::endl;
  std::cout << "v4: " << v4.size() << "\t[" << str(v4) << "]" << std::endl;
  std::cout << "v5: " << v5.size() << "\t[" << str(v5) << "]" << std::endl;
  std::cout << "v6: " << v6.size() << "\t[" << str(v6) << "]" << std::endl;
  std::cout << "v7: " << v7.size() << "\t[" << str(v7) << "]" << std::endl;
  return 0;
}
