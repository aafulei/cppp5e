# Chapter 5 Statements

- [Section 5.1 Simple Statements](#section-51-simple-statements)
    - Exercises [`5.1`](#exercise-51) [`5.2`](#exercise-52) [`5.3`](#exercise-53)

- [Section 5.2 Statement Scope](#section-52-statement-scope)
    - Exercises [`5.4`](#exercise-54)

- [Section 5.3 Conditional Statements](#section-53-conditional-statements)
    - Exercises [`5.5`](#exercise-55) [`5.6`](#exercise-56) [`5.7`](#exercise-57) [`5.8`](#exercise-58)
    - Exercises [`5.9`](#exercise-59) [`5.10`](#exercise-510) [`5.11`](#exercise-511) [`5.12`](#exercise-512) [`5.13`](#exercise-513)

- [Section 5.4 Iterative Statements](#section-54-iterative-statements)
    - Exercises [`5.14`](#exercise-514)
    - Exercises [`5.15`](#exercise-515) [`5.16`](#exercise-516) [`5.17`](#exercise-517)
    - Exercises [`5.18`](#exercise-518) [`5.19`](#exercise-519)

- [Section 5.5 Jump Statements](#section-55jump-statements)
    - Exercises [`5.20`](#exercise-520)
    - Exercises [`5.21`](#exercise-521)
    - Exercises [`5.22`](#exercise-522)

- [Section 5.6 `try` Blocks and Exception Handling](#section-56-try-blocks-and-exception-handling)
    - Exercises [`5.23`](#exercise-523) [`5.24`](#exercise-524) [`5.25`](#exercise-525)

## Section 5.1 Simple Statements

## Exercise 5.1

> What is a null statement? When might you use a null statement?

**Answer:**

An empty statement `;`. Equivalently, an empty block, `{}`. When the program requires a statement but the logic does not.

## Exercise 5.2

> What is a block? When might you might use a block?

**Answer:**

A sequence of zero or more statement enclosed by a pair of curly braces. When the program requires a statement but the logic needs more than one.

## Exercise 5.3

> Use the comma operator (§ 4.10, *p. 157*) to rewrite the while loop from § 1.4.1 (*p. 11*) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.
>
> ```c++
> #include <iostream>
> int main()
> {
>     int sum = 0, val  = 1;
>     // keep executing the while as long as val is less than or equal to 10
>     while (val <= 10)  {
>         sum += val;   // assigns sum + val to sum
>         ++val;        // add 1 to val
>     }
>     std::cout << "Sum of 1 to 10 inclusive is "
>               << sum << std::endl;
>     return 0;
> }
> ```

**Answer:**


```c++
while (val <= 10)
    sum += val, ++val;
```

It diminishes the readability for it violates the principle that one statement is dedicated to one purpose.

## Section 5.2 Statement Scope

## Exercise 5.4

> Explain each of the following examples, and correct any problems you detect.
>
> (a)
>
> ```c++
> while (string::iterator iter != s.end()) { /* . . . */ }
> ```
>
> (b)
>
> ```c++
> while (bool status = find(word)) { /* . . . */ }
>     if (!status) { /* . . . */ }
> ```

**Answer:**


(a) `iter` is not properly initialized.

```c++
for (string::iterator iter = s.begin(); iter != s.end(); /* ... */) {/* ... */}
```

(b) `status` has only statement scope and is thus invisible to `if`.

```c++
while (bool status = find(word)) {
    if (!status) {/* . . . */}
}
```

## Exercise 5.5

> Using an if–else statement, write your own version of the program to generate the letter grade from a numeric grade.

**Answer:**

- [`05-05-letter-to-num.cpp`](05-05-letter-to-num.cpp)

## Exercise 5.6

> Rewrite your grading program to use the conditional operator (§ 4.7, p. 151) in place of the if–else statement.

**Answer:**

- [`05-06-letter-to-num.cpp`](05-06-letter-to-num.cpp)


## Section 5.3 Conditional Statements

## Exercise 5.7

> Correct the errors in each of the following code fragments:
>
> (a)
>
> ```c++
> if (ival1 != ival2)
>     ival1 = ival2
> else ival1 = ival2 = 0;
> ```
>
> (b)
>
> ```c++
> if (ival < minval)
>     minval = ival;
>     occurs = 1;
> ```
> (c)
>
> ```c++
> if (int ival = get_value())
>     cout << "ival = " << ival << endl;
> if (!ival)
>     cout << "ival = 0\n";
> ```
>
> (d)
>
> ```c++
> if (ival = 0)
>     ival = get_value();
> ```

**Answer:**


(a)

```c++
if (ival1 != ival2)
    ival1 = ival2;
else
    ival1 = ival2 = 0;
```

(b)

```c++
if (ival < minval) {
    minval = ival;
    occurs = 1;
}
```

(c)

```c++
if (int ival = get_value())
    cout << "ival = " << ival << endl;
else
    cout << "ival = 0\n";
```

(d)

```c++
if (ival == 0)
    ival = get_value();
```

## Exercise 5.8

> What is a “dangling `else`”? How are `else` clauses resolved in C++?

**Answer:**

An issue that arises when there are more `if` than `else`. In C++, `else` corresponds to the closest preceding unmatched `if`.18/02/04 = Sun

## Exercise 5.9

> Write a program using a series of if statements to count the number of vowels in text read from cin.

**Answer:**

- [`05-09-count-vowels.cpp`](05-09-count-vowels.cpp)

## Exercise 5.10

> There is one problem with our vowel-counting program as we’ve implemented it: It doesn’t count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel—that is, your program should count both 'a' and 'A' as part of aCnt, and so forth.

**Answer:**

- [`05-10-count-vowels.cpp`](05-10-count-vowels.cpp)


## Exercise 5.11

> Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.

**Answer:**

- [`05-11-count-vowels-and-whitespaces.cpp`](05-11-count-vowels-and-whitespaces.cpp)


## Exercise 5.12

> Modify our vowel-counting program so that it counts the number of occurrences of the following two-character sequences: ff, fl, and fi.

**Answer:**

- [`05-12-count-double-chars.cpp`](05-12-count-double-chars.cpp)



## Exercise 5.13

> Each of the programs in the highlighted text on *page 184* contains a common programming error. Identify and correct each error.
>
> (a)
> ```c++
> unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
> char ch = next_text();
> switch (ch) {
>     case 'a': aCnt++;
>     case 'e': eCnt++;
>     default: iouCnt++;
> }
> ```
>
> **Answer:**

Missing `break`.
>
> (b)
>
> ```c++
> unsigned index = some_value();
> switch (index) {
>     case 1:
>         int ix = get_value();
>         ivec[ ix ] = index;
>         break;
>     default:
>         ix = ivec.size()-1;
>         ivec[ ix ] = index;
> }
> ```

**Answer:**

Improperly defining initialized variable `ix` in `case 1`.

(c)

```c++
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break;
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
}
```

**Answer:**

==Wrong syntax.== Should be

```c++
switch (digit) {
    case 1: case 3: case 5: case 7: case 9: oddcnt++; break;
    case 2: case 4: case 6: case 8: case 0: evencnt++; break;
}
```

(d)

```c++
unsigned ival=512, jval=1024, kval=4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```

**Answer:**

==Case labels must be a constant expression.==

## Section 5.4 Iterative Statements

## Exercise 5.14

> Write a program to read strings from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is "how now now now brown cow cow" the output should indicate that the word "now" occurred three times.


## Exercise 5.15

> Explain each of the following loops. Correct any problems you detect.
>
> (a)
>
> ```c++
> for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
> if (ix != sz)
>    // . . .
> ```
>
> (b)
>
> ```c++
> int ix;
> for (ix != sz; ++ix) { /* . . . */ }
> ```
>
> (c)
>
> ```c++
> for (int ix = 0; ix != sz; ++ix, ++ sz) { /* . . . */ }
> ```

**Answer:**

(a) `ix`, local to `for`, cannot be accessed after the loop.
```c++
int ix = 0;
for (ix = 0; ix != sz; ++ix) { /* . . . */ }
if (ix != sz)
    // . . .
```

(b) Wrong syntax. `for` must have

1. a declaration statement, or
2. an expression statement, or
3. a null statement

in the first of the three slots in the header.

```c++
int ix;
for (; ix != sz; ++ix) { /* . . . */ }
```

(c) Infinite loop.

```c++
for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
```

## Exercise 5.16

> The `while` loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The `for` loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?

**Answer:**

```c++
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> text;
string word;
// using while to read words into a vector of strings
while (cin >> word)
    text.push_back(word);
// is the same as
for (string word; cin >> word; text.push_back(word))
    ;
```

```c++
int sum = 0;
// using for to sum from 1 to 10
for (int i = 1; i <= 10; ++i)
    sum += i;
// is the same as
sum = 0;
int i = 1;
while (i <= 10) {
    sum += i;
    ++i;
}
// alternatively:
i = 1;
while (i <= 10)
    sum += i++;
```

I usually prefer `for` loop, which is more compact.18/02/04 = Sun

## Exercise 5.17

> Given two vectors of ints, write a program to determine whether one vector is a prefix of the other. For vectors of unequal length, compare the number of elements of the smaller vector. For example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.

**Answer:**

- [`05-17-prefix.cpp`](05-17-prefix.cpp)


## Exercise 5.18

> Explain each of the following loops. Correct any problems you detect.
>
> (a)
>
> ```c++
> do
>     int v1, v2;
>     cout << "Please enter two numbers to sum:" ;
>     if (cin >> v1 >> v2)
>         cout << "Sum is: " << v1 + v2 << endl;
> while (cin);
> ```

**Answer:**

Missing `{}` for `do`

(b)

```c++
 do {
    // . . .
} while (int ival = get_response());
```

(c)

```c++
do {
    int ival = get_response();
   } while (ival);
```

## Exercise 5.19

> Write a program that uses a do while loop to repetitively request two strings from the user and report which string is less than the other.

**Answer:**

- [`05-19-compare-str.cpp`](05-19-compare-str.cpp)

## Section 5.5 Jump Statements

## Exercise 5.20

> Write a program to read a sequence of strings from the standard input until either the same word occurs twice in succession or all the words have been read. Use a while loop to read the text one word at a time. Use the break statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.

- [`05-20-dedup.cpp`](05-20-dedup.cpp)

## Exercise 5.21

> Revise the program from the exercise in § 5.5.1 (p. 191) so that it looks only for duplicated words that start with an uppercase letter.

- [`05-21-dedup-uppercase.cpp`](05-21-dedup-uppercase.cpp)

## Exercise 5.22

> The last example in this section that jumped back to begin could be better written using a loop. Rewrite the code to eliminate the goto.
>
> ```c++
> // backward jump over an initialized variable definition is okay
> begin:
> int sz = get_size();
> if (sz <= 0) {
>       goto begin;
> }
> ```

**Answer:**


```c++
int sz;
while ((sz = get_size()) <= 0) ;
```

## Section 5.6 `try` Blocks and Exception Handling

## Exercise 5.23

> Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.

**Answer:**

- [`05-23-divide.cpp`](05-23-divide.cpp)

## Exercise 5.24

> Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don’t catch an exception.

**Answer:**

- [`05-24-zero-except.cpp`](05-24-zero-except.cpp)

## Exercise 5.25

> Revise your program from the previous exercise to use a try block to catch the exception. The catch clause should print a message to the user and ask them to supply a new number and repeat the code inside the try.

**Answer:**

- [`05-25-try-catch.cpp`](05-25-try-catch.cpp)
