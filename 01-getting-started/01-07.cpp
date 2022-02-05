// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.7: Compile a program that has incorrectly nested comments.

// Note: This program won't compile.

// clang-format off
int main() {
  /* This program won't compile, because it
   * has /* incorrectly nested comments. */
   * Now this line is taken as code instead
   * of a comment.
   */
  return 0;
}
