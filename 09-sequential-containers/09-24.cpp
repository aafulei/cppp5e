// 22/02/23 = Wed
// 18/01/17 = Wed

// Exercise 9.24: Write a program that fetches the first element in a vector
// using at, the subscript operator, front, and begin. Test your program on an
// empty vector.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
#ifdef AT
  std::clog << "vec.at(0)" << std::endl;
  std::cout << vec.at(0) << std::endl;
#elif defined(SUBSCRIPT)
  std::clog << "vec[0]" << std::endl;
  std::cout << vec[0] << std::endl;
#elif defined(FRONT)
  std::clog << "vec.front()" << std::endl;
  std::cout << vec.front() << std::endl;
#elif defined(BEGIN)
  std::clog << "*vec.begin()" << std::endl;
  std::cout << *vec.begin() << std::endl;
#else
  std::cerr << "Compile with -D [ AT | SUBSCRIPT | FRONT | BEGIN ]"
            << std::endl;
#endif
  return 0;
}
