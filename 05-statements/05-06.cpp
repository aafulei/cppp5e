// 22/01/29 = Sat
// 18/02/04 = Sun

// Exercise 5.6: Rewrite your grading program to use the conditional operator
// (§ 4.7, p. 151) in place of the if–else statement.

// Exercise 5.5: Using an if–else statement, write your own version of the
// program to generate the letter grade from a numeric grade.

// Grading scheme:
// 100    A++
// 97-99  A+    93-96  A    90-92  A-
// 87-89  B+    83-86  B    80-82  B-
// 77-79  C+    73-76  C    70-72  C-
// 67-69  D+    63-66  D    60-62  D-
// 0-59   F

#include <string>

std::string scoreToGrade(int score) {
  if (score < 60) {
    return "F";
  }
  if (score == 100) {
    return "A++";
  }
  std::string letters = "DCBA";
  std::string grade = {letters[(score - 60) / 10]};
  int r = score % 10;
  // change from 05-05.cpp
  grade += (0 <= r && r <= 2) ? "-" : (7 <= r && r <= 9) ? "+" : "";
  return grade;
}

/* === Output ==================================================================

100 A++
 99 A+   98 A+   97 A+   96 A    95 A    94 A    93 A    92 A-   91 A-   90 A-
 89 B+   88 B+   87 B+   86 B    85 B    84 B    83 B    82 B-   81 B-   80 B-
 79 C+   78 C+   77 C+   76 C    75 C    74 C    73 C    72 C-   71 C-   70 C-
 69 D+   68 D+   67 D+   66 D    65 D    64 D    63 D    62 D-   61 D-   60 D-
 59 F    58 F    57 F    56 F    55 F    54 F    53 F    52 F    51 F    50 F
 49 F    48 F    47 F    46 F    45 F    44 F    43 F    42 F    41 F    40 F
 39 F    38 F    37 F    36 F    35 F    34 F    33 F    32 F    31 F    30 F
 29 F    28 F    27 F    26 F    25 F    24 F    23 F    22 F    21 F    20 F
 19 F    18 F    17 F    16 F    15 F    14 F    13 F    12 F    11 F    10 F
  9 F     8 F     7 F     6 F     5 F     4 F     3 F     2 F     1 F     0 F

============================================================================= */

#include <iomanip>
#include <iostream>

void test() {
  for (int score = 100; score >= 0; --score) {
    std::cout << std::setw(3) << score << " " << scoreToGrade(score);
    if (score % 10 == 0) {
      std::cout << '\n';
    } else {
      std::cout << '\t';
    }
  }
}

int main() {
  test();
  return 0;
}
