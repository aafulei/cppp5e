// 18/03/08 = Thu

// Exercise 13.50: Put print statements in the move operations in your String class and rerun the program from exercise 13.48 in  §  13.6.1  (p. 534) that used a vector<String> to see when the copies are avoided.

// We've done the job in lp-13-47-48.cpp.

// To see how it runs without move operations:
// g++ lp-13-50.cpp -D DEBUG_COPY

// To see how it runs move operations:
// g++ lp-13-50.cpp -D DEBUG_MOVE

#include "lp-13-47-48.cpp"