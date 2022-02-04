// 22/02/04 = Fri
// 21/12/25 = Sat
// 18/02/03 = Sat

// Exercise 4.31: The program in this section used the prefix increment and
// decrement operators. Explain why we used prefix and not postfix. What changes
// would have to be made to use the postfix versions? Rewrite the program using
// postfix operators.

// vector<int>::size_type cnt = ivec.size();
// for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
//   ivec[ix] = cnt;

// Answer: There is no change to make. In standalone expressions, i++ has no
// difference with ++i in effect.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec(10);
  std::vector<int>::size_type cnt = ivec.size();
  for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
    ivec[ix] = cnt;
  }
  for (int i : ivec) {
    std::cout << i << std::endl;
  }
  return 0;
}
