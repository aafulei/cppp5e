# Chapter 5 Statements

- [Section 5.1 Simple Statements](#section-51-simple-statements)
  - *Exercises* [`5.1`](#exercise-51) [`5.2`](#exercise-52) [`5.3`](#exercise-53)

- [Section 5.2 Statement Scope](#section-52-statement-scope)
  - *Exercises* [`5.4`](#exercise-54)

- [Section 5.3 Conditional Statements](#section-53-conditional-statements)
  - *Exercises* [`5.5`](#exercise-55) [`5.6`](#exercise-56) [`5.7`](#exercise-57) [`5.8`](#exercise-58)
  - *Exercises* [`5.9`](#exercise-59) [`5.10`](#exercise-510) [`5.11`](#exercise-511) [`5.12`](#exercise-512) [`5.13`](#exercise-513)

- [Section 5.4 Iterative Statements](#section-54-iterative-statements)
  - *Exercises* [`5.14`](#exercise-514)
  - *Exercises* [`5.15`](#exercise-515) [`5.16`](#exercise-516) [`5.17`](#exercise-517)
  - *Exercises* [`5.18`](#exercise-518) [`5.19`](#exercise-519)

- [Section 5.5 Jump Statements](#section-55-jump-statements)
  - *Exercises* [`5.20`](#exercise-520)
  - *Exercises* [`5.21`](#exercise-521)
  - *Exercises* [`5.22`](#exercise-522)

- [Section 5.6 try Blocks and Exception Handling](#section-56-try-blocks-and-exception-handling)
  - *Exercises* [`5.23`](#exercise-523) [`5.24`](#exercise-524) [`5.25`](#exercise-525)

## Section 5.1 Simple Statements

### Exercise 5.1

> What is a null statement? When might you use a null statement?

**Answer:**

A null statement is an empty statement that has only a semicolon. It might be used when, for example, a loop's work can be done within its condition.


```c++
while (cin >> s && s != sought)
  ;  // null statement
```

### Exercise 5.2

> What is a block? When might you might use a block?

**Answer:**

A block is a compound statement that surrounds a (possibly empty) sequence of statements and declarations with a pair of curly braces.

### Exercise 5.3

> Use the comma operator (Section 4.10, p. 157) to rewrite the `while` loop from Section 1.4.1 (p. 11) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.

**Answer:**

- *Original*

```c++
while (val <= 10) {
  sum += val;
  ++val;
}
```

- *Rewrite*

```c++
while (val <= 10)
  sum += val, ++val;
```

The rewrite diminishes the readability, because each line should serve only one purpose.

## Section 5.2 Statement Scope

### Exercise 5.4

> Explain each of the following examples, and correct any problems you detect.
>
> (a) `while (string::iterator iter != s.end()) { /* . . . */ }`
>
> (b) `while (bool status = find(word)) { /* . . . */ } if (!status) { /* . . . */ }`

**Answer:**

(a) Loop over string `s`, until the iterator `iter` reaches the end of `s`.

(b) Repeat the loop until we find `word`, in which case `status` would be `true`. However, since `status` is defined in the statement scope, it is illegal to access it after the `while` loop finishes. The code should be

```c++
bool status = false;
while (status = find(word)) {
  /* ... */
}
if (!status) {
  /* ... */
}

```

## Section 5.3 Conditional Statements

### Exercise 5.5

> Using an if-else statement, write your own version of the program to generate the letter grade from a numeric grade.

**Answer:**

- [`05-05.cpp`](05-05.cpp)

### Exercise 5.6

> Rewrite your grading program to use the conditional operator (Section 4.7, p. 151) in place of the if-else statement.

**Answer:**

- [`05-06.cpp`](05-06.cpp)

### Exercise 5.7

> Correct the errors in each of the following code fragments:
>
> (a)
> ```c++
> if (ival1 != ival2)
>   ival1 = ival2
> else ival1 = ival2 = 0;
> ```
>
> (b)
> ```c++
> if (ival < minval)
>   minval = ival;
>   occurs = 1;
> ```
>
> (c)
> ```c++
> if (int ival = get_value())
>   cout << "ival = " << ival << endl;
> if (!ival)
>   cout << "ival = 0\n";
> ```
>
> (d)
> ```c++
> if (ival = 0)
>   ival = get_value();
> ```

**Answer:**

(a) Problem - missing `;` in the `if` statement. Fix -

```c++
if (ival1 != ival2)
  ival1 = ival2;
else
  ival1 = ival2 = 0;
```

(b) Problem - code does not express what indentation indicates. Fix -

```c++
if (ival < minval) {
  minval = ival;
  occurs = 1;
}
```

(c) Problem - `ival` goes out of scope after the `if` statement finishes. Fix -

```c++
if (int ival = get_value())
  cout << "ival = " << ival << endl;
else
  cout << "ival = 0\n";
```

(d) Problem - using `=` for `==` in condition. Fix -

```c++
if (ival == 0)
  ival = get_value();
```

### Exercise 5.8

> What is a "dangling `else`"? How are `else` clauses resolved in C++?

**Answer:**

The dangling `else` describes a problem when there are multiple `if` branches preceding an `else` branch. The `else` branch needs to decide which `if` branch it belongs to. In C++, an `else` branch is matched with the closest unmatched `if` branch before it.

### Exercise 5.9

> Write a program using a series of `if` statements to count the number of vowels in text read from `cin`.

**Answer:**

- [`05-09.cpp`](05-09.cpp)

### Exercise 5.10

> There is one problem with our vowel-counting program as we've implemented it: It doesn't count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel -- that is, your program should count both `'a'` and `'A'` as part of `aCnt`, and so forth.

**Answer:**

- [`05-10.cpp`](05-10.cpp)

### Exercise 5.11

> Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.

**Answer:**

- [`05-11.cpp`](05-11.cpp)

### Exercise 5.12

> Modify our vowel-counting program so that it counts the number of occurrences of the following two-character sequences: `ff`, `fl`, and `fi`.

**Answer:**

- [`05-12.cpp`](05-12.cpp)

### Exercise 5.13

> Each of the programs in the highlighted text on *page 184* contains a common programming error. Identify and correct each error.
>
> (a)
>
> ```c++
> unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
> char ch = next_text();
> switch (ch) {
>   case 'a': aCnt++;
>   case 'e': eCnt++;
>   default: iouCnt++;
> }
> ```
>
> (b)
>
> ```c++
> unsigned index = some_value();
> switch (index) {
> case 1:
>   int ix = get_value();
>   ivec[ix] = index;
>   break;
> default:
>   ix = ivec.size() - 1;
>   ivec[ix] = index;
> }
> ```
>
> (c)
>
> ```c++
> unsigned evenCnt = 0, oddCnt = 0;
> int digit = get_num() % 10;
> switch (digit) {
> case 1, 3, 5, 7, 9:
>   oddcnt++;
>   break;
> case 2, 4, 6, 8, 10:
>   evencnt++;
>   break;
> }
> ```
>
> (d)
>
> ```c++
> unsigned ival = 512, jval = 1024, kval = 4096;
> unsigned bufsize;
> unsigned swt = get_bufCnt();
> switch (swt) {
> case ival:
>   bufsize = ival * sizeof(int);
>   break;
> case jval:
>   bufsize = jval * sizeof(int);
>   break;
> case kval:
>   bufsize = kval * sizeof(int);
>   break;
> }
> ```

**Answer:**

(a) Problem - Missing `break`. Fix -

```c++
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
case 'a':
  aCnt++;
  break;
case 'e':
  eCnt++;
  break;
default:
  iouCnt++;
}
```

(b) Problem - trying to jump over the initialization of `ix`, which would be in scope at the `default` label. Fix -

```c++
unsigned index = some_value();
int ix;
switch (index) {
case 1:
  ix = get_value();
  ivec[ix] = index;
  break;
default:
  ix = ivec.size() - 1;
  ivec[ix] = index;
}
```

(c) Problem - syntax error in case labels. Fix -

```c++
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
case 1:
case 3:
case 5:
case 7:
case 9:
  oddcnt++;
  break;
case 2:
case 4:
case 6:
case 8:
case 10:
  evencnt++;
  break;
}
```

(d) Problem - Case labels must be constant expressions. Fix -

```c++
constexpr unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch (swt) {
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

## Section 5.4 Iterative Statements

### Exercise 5.14

> Write a program to read strings from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is
>
> ```
> how now now now brown cow cow
> ```
>
> the output should indicate that the word now occurred three times.

**Answer:**

- [`05-14.cpp`](05-14.cpp)

### Exercise 5.15

> Explain each of the following loops. Correct any problems you detect.
>
> (a)
> ```c++
> for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
> if (ix != sz)
>     // . . .
> ```
>
> (b)
> ```c++
> int ix;
> for (ix != sz; ++ix) { /* . . . */ }
> ```
>
> (c)
> ```c++
> for (int ix = 0; ix != sz; ++ix, ++sz) { /* . . . */ }
> ```

**Answer:**

(a) Loop over range `[0, sz)` with `ix`. Problem - trying to access `ix` after the `for` loop finishes. Fix -

```c++
int ix = 0;
for (/* empty */; ix != sz; ++ix) {
  // ...
}
if (ix != sz) {
  // ...
}
```

(b) Loop until `ix` reaches `sz`.

Problem (1) - `ix` is not initialized; it has indeterminate value.

Problem (2) - syntax error - missing the init-statement part in the `for` loop.

Fix -

```c++
for (int ix = 0; ix != sz; ++ix) {
  // ...
}
```

(c) Loop over range `[0, sz)` with `ix`. Problem - by unnecessarily incrementing `sz`, loop might never terminate. Fix -

```c++
for (int ix = 0; ix != sz; ++ix) {
  // ...
}
```

### Exercise 5.16

> The `while` loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The `for` loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?

**Answer:**

An idiomatic use of the `while` loop - read one line each time

```c++
std::string line;
while (std::getline(std::cin, line)) {
  process(line);
}
```

The equivalent `for` loop -

```c++
for (std::string line; std::getline(std::cin, line); /* empty */) {
  process(line);
}
```

An idiomatic use of the `for` loop - using an index to loop over a sequence

```c++
// assume s is a std::string
for (decltype(s.size()) i = 0; i != s.size(); ++i) {
  process(s[i]);
}
```

The equivalent `while` loop -

```c++
// assume s is a std::string
decltype(s.size()) i = 0;
while (i != s.size()) {
  process(s[i]);
  ++i;
}
```

If I could use only one loop, I would choose the `while` loop, as it has the most basic form.

### Exercise 5.17

> Given two `vector`s of `int`s, write a program to determine whether one `vector` is a prefix of the other. For `vector`s of unequal length, compare the number of elements of the smaller `vector`. For example, given the `vector`s containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.

**Answer:**

- [`05-17.cpp`](05-17.cpp)

### Exercise 5.18

> Explain each of the following loops. Correct any problems you detect.
>
> (a)
>
> ```c++
> do
>   int v1, v2;
>   cout << "Please enter two numbers to sum:" ;
>   if (cin >> v1 >> v2)
>     cout << "Sum is: " << v1 + v2 << endl;
> while (cin);
> ```
>
> (b)
>
> ```c++
> do {
>   // . . .
> } while (int ival = get_response());
> ```
>
> (c)
>
> ```c++
> do {
>   int ival = get_response();
> } while (ival);
> ```

**Answer:**

(a) Prompt for input. Read two numbers. Print out the sum. Repeat the above steps.

Problem - missing curly braces for the `do` part.

Fix -

```c++
do {
  int v1, v2;
  cout << "Please enter two numbers to sum:" ;
  if (cin >> v1 >> v2) {
    cout << "Sum is: " << v1 + v2 << endl;
  }
}
while (cin);
```

(b) Do something. If the response is non-zero, repeat the above steps.

Problem - variable definitions are not allowed inside the condition of a `do while` loop.

Fix -

```c++
do {
  // ...
} while (get_response());
```

(c) Get response. If the response is non-zero, repeat the above steps.

Problem - `ival` defined in the `do` part goes out of scope and is thus inaccessible in the `while` condition.

Fix -

```c++
int ival;
do {
  ival = get_response();
} while (ival);
```

### Exercise 5.19

> Write a program that uses a `do while` loop to repetitively request two `string`s from the user and report which `string` is less than the other.

**Answer:**

- [`05-19.cpp`](05-19.cpp)

## Section 5.5 Jump Statements

### Exercise 5.20

> Write a program to read a sequence of `string`s from the standard input until either the same word occurs twice in succession or all the words have been read. Use a `while` loop to read the text one word at a time. Use the break statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.

**Answer:**

- [`05-20.cpp`](05-20.cpp)

### Exercise 5.21

> Revise the program from the exercise in Section 5.5.1 (p. 191) so that it looks only for duplicated words that start with an uppercase letter.

**Answer:**

- [`05-21.cpp`](05-21.cpp)

### Exercise 5.22

> The last example in this section that jumped back to begin could be better written using a loop. Rewrite the code to eliminate the goto.

**Answer:**

- [`05-22.cpp`](05-22.cpp)

## Section 5.6 try Blocks and Exception Handling

### Exercise 5.23

> Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.

**Answer:**

- [`05-23.cpp`](05-23.cpp)

### Exercise 5.24

> Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don't catch an exception.

**Answer:**

- [`05-24.cpp`](05-24.cpp)

### Exercise 5.25

> Revise your program from the previous exercise to use a try block to catch the exception. The catch clause should print a message to the user and ask them to supply a new number and repeat the code inside the try.

**Answer:**

- [`05-25.cpp`](05-25.cpp)

