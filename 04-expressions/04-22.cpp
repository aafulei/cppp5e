// 22/02/04 = Fri
// 21/12/25 = Sat
// 18/02/03 = Sat

// Exercise 4.22: Extend the program that assigned high pass, pass, and fail
// grades to also assign low pass for grades between 60 and 75 inclusive. Write
// two versions: One version that uses only conditional operators; the other
// should use one or more if statements. Which version do you think is easier to
// understand and why?

// Answer: The version with more if statements is easier to understand, because
// nested conditional operators heavily reduce readability.

// Grading scheme:
// 91-100   high pass
// 76-90    pass
// 60-75    low pass
// 0-59     fail

#include <iostream>
#include <string>

std::string get_grade_cond_op(int grade) {
  return (grade > 90)   ? "high pass"
         : (grade > 75) ? "pass"
         : (grade < 60) ? "fail"
                        : "low pass";
}

std::string get_grade_if_else(int grade) {
  if (grade > 90) {
    return "high pass";
  } else if (grade > 75) {
    return "pass";
  } else if (grade < 60) {
    return "fail";
  } else {
    return "low pass";
  }
}

void test() {
  std::cout << 100 << '\t' << get_grade_cond_op(100) << std::endl;
  std::cout << 100 << '\t' << get_grade_if_else(100) << std::endl;
  std::cout << 90 << '\t' << get_grade_cond_op(90) << std::endl;
  std::cout << 90 << '\t' << get_grade_if_else(90) << std::endl;
  std::cout << 80 << '\t' << get_grade_cond_op(80) << std::endl;
  std::cout << 80 << '\t' << get_grade_if_else(80) << std::endl;
  std::cout << 70 << '\t' << get_grade_cond_op(70) << std::endl;
  std::cout << 70 << '\t' << get_grade_if_else(70) << std::endl;
  std::cout << 60 << '\t' << get_grade_cond_op(60) << std::endl;
  std::cout << 60 << '\t' << get_grade_if_else(60) << std::endl;
  std::cout << 50 << '\t' << get_grade_cond_op(50) << std::endl;
  std::cout << 50 << '\t' << get_grade_if_else(50) << std::endl;
}

int main() {
  test();
  return 0;
}
