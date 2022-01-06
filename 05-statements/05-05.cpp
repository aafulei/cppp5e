// 18/02/04 = Sun

// Exercise 5.5: Using an if–else statement, write your own version of the
// program to generate the letter grade from a numeric grade.

// Letter scheme:
// 100    A++
// 97-99  A+
// 93-96  A
// 90-92  A-
// 87-89  B+
// 83-86  B
// 80-82  B-
// 77-79  C+
// 73-76  C
// 70-72  C-
// 67-69  D+
// 63-66  D
// 60-62  D-
// 0-59   F

#include <iostream>
#include <string>

std::string letter(int n) {
  const std::string A = "ABCDF";
  const int N = A.size();
  std::string a;
  if (n < 60)
    a = A[N - 1];
  else if (n >= 100) {
    a = A[0];
    a += "++";
  } else {
    a = A[(99 - n) / 10];
    int r = n % 10;
    if (r < 3)
      a += '-';
    else if (r > 6)
      a += '+';
  }
  return a;
}

int main() {
  for (int score = 100; score >= 0; --score)
    std::cout << score << " " << letter(score) << (score % 10 ? '\t' : '\n');
  return 0;
}
