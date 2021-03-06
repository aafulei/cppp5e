# Chapter 1 Getting Started

- [Section 1.1 Writing a Simple C++ Program](#section-11-writing-a-simple-c-program)
  - *Exercises* [`1.1`](#exercise-11) [`1.2`](#exercise-12)

- [Section 1.2 A First Look at Input/Output](#section-12-a-first-look-at-inputoutput)
  - *Exercises* [`1.3`](#exercise-13) [`1.4`](#exercise-14) [`1.5`](#exercise-15) [`1.6`](#exercise-16)

- [Section 1.3 A Word about Comments](#section-13-a-word-about-comments)
  - *Exercises* [`1.7`](#exercise-17) [`1.8`](#exercise-18)

- [Section 1.4 Flow of Control](#section-14-flow-of-control)
  - *Exercises* [`1.9`](#exercise-19) [`1.10`](#exercise-110) [`1.11`](#exercise-111)
  - *Exercises* [`1.12`](#exercise-112) [`1.13`](#exercise-113) [`1.14`](#exercise-114) [`1.15`](#exercise-115)
  - *Exercises* [`1.16`](#exercise-116)
  - *Exercises* [`1.17`](#exercise-117) [`1.18`](#exercise-118) [`1.19`](#exercise-119)

- [Section 1.5 Introducing Classes](#section-15-introducing-classes)
  - *Exercises* [`1.20`](#exercise-120) [`1.21`](#exercise-121) [`1.22`](#exercise-122)
  - *Exercises* [`1.23`](#exercise-123) [`1.24`](#exercise-124)

- [Section 1.6 The Bookstore Program](#section-16-the-bookstore-program)
  - *Exercises* [`1.25`](#exercise-125)

## Section 1.1 Writing a Simple C++ Program

### Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from *page 2*.

**Answer:**

- [`01-01-main.cpp`](01-01-main.cpp)

For the Clang/LLVM compiler `clang++`

| System       | Executable File Extension  | How to Run          |
| ------------ | -------------------------- | ------------------- |
| Linux/macOS  | no requirement             | `./a.out`           |
| Windows      | `.exe`                     | `a.exe` or just `a` |

### Exercise 1.2

> Change the program to return `-1`. A return value of `-1` is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from `main`.

**Answer:**

- [`01-02-main.cpp`](01-02-main.cpp)

| Operating System | How to Obtain Exit Status | Result |
| ---------------- | ------------------------- | ------ |
| Linux/macOS      | `echo $?`                 | `255`  |
| Windows          | `echo %ERRORLEVEL%`       | `-1`   |

## Section 1.2 A First Look at Input/Output

### Exercise 1.3

> Write a program to print *Hello, World* on the standard output.

**Answer:**

- [`01-03-hello-world.cpp`](01-03-hello-world.cpp)

### Exercise 1.4

> Our program used the addition operator, `+`, to add two numbers. Write a program that uses the multiplication operator, `*`, to print the product instead.

**Answer:**

- [`01-04-multiplication-operator.cpp`](01-04-multiplication-operator.cpp)

### Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

**Answer:**

- [`01-05-separate-output.cpp`](01-05-separate-output.cpp)

### Exercise 1.6

> Explain whether the following program fragment is legal.
>
> ```c++
> std::cout << "The sum of " << v1;
>           << " and " << v2;
>           << " is " << v1 + v2 << std::endl;
> ```
>
> If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?

**Answer:**

The program is illegal because `;` is only needed at the end of a statement. To fix it, remove the unwanted semicolons.

```c++
std::cout << "The sum of " << v1
          << " and " << v2
          << " is " << v1 + v2 << std::endl;
```

## Section 1.3 A Word about Comments

### Exercise 1.7

> Compile a program that has incorrectly nested comments.

**Answer:**

- [`01-07-comments.cpp`](01-07-comments.cpp)

### Exercise 1.8

> Indicate which, if any, of the following output statements are legal:
>
> ```c++
> std::cout << "/*";
> std::cout << "*/";
> std::cout << /* "*/" */;
> std::cout << /*  "*/" /* "/*"  */;
> ```
>
> After you???ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.

**Answer:**

All the output statements except for the third one are legal.

```c++
std::cout << "/*";                  // legal
std::cout << "*/";                  // legal
std::cout << /* "*/" */;            // illegal
std::cout << /*  "*/" /* "/*"  */;  // legal
```

- [`01-08-comments.cpp`](01-08-comments.cpp)

## Section 1.4 Flow of Control

### Exercise 1.9

> Write a program that uses a while to sum the numbers from 50 to 100.

**Answer:**

- [`01-09-sum-from-50-to-100.cpp`](01-09-sum-from-50-to-100.cpp)

### Exercise 1.10

> In addition to the `++` operator that adds 1 to its operand, there is a decrement operator (`--`) that subtracts 1. Use the decrement operator to write a `while` that prints the numbers from ten down to zero.

**Answer:**

- [`01-10-decrement-from-10-to-0.cpp`](01-10-decrement-from-10-to-0.cpp)

### Exercise 1.11

> Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

**Answer:**

- [`01-11-print-numbers-in-range.cpp`](01-11-print-numbers-in-range.cpp)

### Exercise 1.12

> What does the following `for` loop do? What is the final value of `sum`?
>
> ```c++
> int sum = 0;
> for (int i = -100; i <= 100; ++i)
>     sum += i;
> ```

**Answer:**

It sums integers from `-100` to `100` inclusive. The final value of `sum` is 0.

### Exercise 1.13

> Rewrite the exercises from ?? 1.4.1 (p. 13) using `for` loops.
>
> *^ i.e. exercises [`1.9`](#exercise-19) [`1.10`](#exercise-110) [`1.11`](#exercise-111)*

**Answer:**

- [`01-13-sum-from-50-to-100.cpp`](01-13-sum-from-50-to-100.cpp) *rewrites* [`01-09-sum-from-50-to-100.cpp`](01-09-sum-from-50-to-100.cpp)

- [`01-13-decrement-from-10-to-0.cpp`](01-13-decrement-from-10-to-0.cpp) *rewrites* [`01-10-decrement-from-10-to-0.cpp`](01-10-decrement-from-10-to-0.cpp)

- [`01-13-print-numbers-in-range.cpp`](01-13-print-numbers-in-range.cpp) *rewrites* [`01-11-print-numbers-in-range.cpp`](01-11-print-numbers-in-range.cpp)

### Exercise 1.14

> Compare and contrast the loops that used a `for` with those using a `while`. Are there advantages or disadvantages to using either form?

**Answer:**

- `while` is the basic form to start with
  - when you don't have any clue writing a loop, start with an ugly `while (1) { /* code */ }` and then improve on it
- `for` is more compact, designed for certain patterns. It
  - defines variables local to its scope,
  - separates increment for clarity, and
  - is best suited when
    - the increment step is simple, and
    - the number of iterations is known in advance

### Exercise 1.15

> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

**Answer:**

- [`01-15-error.cpp`](01-15-errors.cpp)

  - Syntax errors

  - Type errors

  - Declaration errors

### Exercise 1.16

> Write your own version of a program that prints the sum of a set of integers read from `cin`.

**Answer:**

- [`01-16-sum-numbers-in-range.cpp`](01-16-sum-numbers-in-range.cpp)

### Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

**Answer:**

- [`01-17-count-numbers.cpp`](01-17-count-numbers.cpp)

  - If the input values are all equal, upon end of file, the program will print that value occurs N times.

  - If there no duplicated values, each time a new value is read, or upon end of file, the program will print that the last value occurs 1 time(s).

### Exercise 1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

**Answer:**

See the answer to exercise [`1.17`](#exercise-117)

### Exercise 1.19

> Revise the program you wrote for the exercises in ?? 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.
>
> *^ i.e. exercise [`1.11`](#exercise-111)*

**Answer:**

- [`01-19-print-numbers-in-range.cpp`](01-19-print-numbers-in-range.cpp)

## Section 1.5 Introducing Classes

### Exercise 1.20

> http://www.informit.com/title/032174113 contains a copy of `Sales_item.h` in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

**Answer:**

- [`01-20-read-books.cpp`](01-20-read-books.cpp)

  - [`Sales_item.h`](Sales_item.h)

### Exercise 1.21

> Write a program that reads two `Sales_item` objects that have the same ISBN and produces their sum.

**Answer:**

- [`01-21-sum-two-books.cpp`](01-21-sum-two-books.cpp)

  - [`Sales_item.h`](Sales_item.h)

### Exercise 1.22

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

**Answer:**

- [`01-22-sum-several-books.cpp`](01-22-sum-several-books.cpp)

  - [`Sales_item.h`](Sales_item.h)

### Exercise 1.23

> Write a program that reads several transactions and counts how many transactions occur for each ISBN.

**Answer:**

- [`01-23-count-books.cpp`](01-23-count-books.cpp)

  - [`Sales_item.h`](Sales_item.h)

### Exercise 1.24

> Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

**Answer:**

See the answer to exercise [`1.23`](#exercise-123)

## Section 1.6 The Bookstore Program

### Exercise 1.25

> Using the `Sales_item.h` header from the Web site, compile and execute the bookstore program presented in this section.

**Answer:**

- [`01-25-bookstore.cpp`](01-25-bookstore.cpp)

  - [`Sales_item.h`](Sales_item.h)
