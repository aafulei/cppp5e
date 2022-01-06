// 21/12/18 = Sat
// 18/01/29 = Mon

// Exercise 1.2: Change the program to return -1. A return value of -1 is often
// treated as an indicator that the program failed. Recompile and rerun your
// program to see how your system treats a failure indicator from main.

/* === Compile and Run ===
(Linux/macOS)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-02-main.cpp && ./a.out
echo $?

(Windows)
clang++ -std=c++11 -pedantic -Wall -Wextra 01-02-main.cpp && a
echo %ERRORLEVEL%

=== Output ===
(Linux/macOS)
255

(Windows)
-1
*/

// Modified from 01-01-main.cpp

int main() { return -1; }
