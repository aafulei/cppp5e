## Chapter 1 Getting Started

- [Section 1.1 Writing a Simple C++ Program](#exercise-11) (exercises 1.1-1.2)
- [Section 1.2 A First Look at Input/Output](#exercise-13) (exercises 1.3-1.6)
- [Section 1.3 A Word about Comments](#exercise-17) (exercises 1.7-1.8)
- [Section 1.4 Flow of Control](#exercise-19) (exercises 1.9-1.19)
- [Section 1.5 Introducing Classes](#exercise-120) (exercises 1.20-1.24)
- [Section 1.6 The Bookstore Program](#exercise-125) (exercise 1.25)

### [Exercise 1.1](01-01.cpp)

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

**Answer:** For the GCC compiler

| system  | source file extension | executable file extension | how to run |
| ------- | --------------------- | ------------------------- | ---------- |
| Windows | `.cpp`                | `.exe`                    | `a.exe`    |
| Linux   | `.cpp`                | `.out`                    | `./a.out`  |

### [Exercise 1.2](01-02.cpp)

> Change the program to return `-1`. A return value of `-1` is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from `main`.

**Answer:** To check the status, enter in the console

| Linux terminal | Windows command prompt |
|--------------- | ---------------------- |
| `echo $?`      | `echo %ERRORLEVEL%`    |

### [Exercise 1.3](01-03.cpp)

> Write a program to print *Hello, World* on the standard output.

### [Exercise 1.4](01-04.cpp)

> Our program used the addition operator, `+`, to add two numbers. Write a program that uses the multiplication operator, `*`, to print the product instead.

### [Exercise 1.5](01-05.cpp)

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

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

**Answer:** The program is illegal because `;` is not needed at the end of the first and second lines. To fix it, remove them.

```c++
std::cout << "The sum of " << v1
       << " and " << v2
       << " is " << v1 + v2 << std::endl;
```

### [Exercise 1.7](01-07.cpp)

> Compile a program that has incorrectly nested comments.

### [Exercise 1.8](01-08.cpp)

> Indicate which, if any, of the following output statements are legal:
>
> ```c++
> std::cout << "/*";
> std::cout << "*/";
> std::cout << /* "*/" */;
> std::cout << /*  "*/" /* "/*"  */;
> ```
>
> After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.

**Answer:** All are legal except for the third one.

```c++
std::cout << "/*";                  // legal
std::cout << "*/";                  // legal
std::cout << /* "*/" */;            // illegal
std::cout << /*  "*/" /* "/*"  */;  // legal
```
### [Exercise 1.9](01-09.cpp)

> Write a program that uses a while to sum the numbers from 50 to 100.

### [Exercise 1.10](01-10.cpp)

> In addition to the `++` operator that adds 1 to its operand, there is a decrement operator (`--`) that subtracts 1. Use the decrement operator to write a `while` that prints the numbers from ten down to zero.

### [Exercise 1.11](01-11.cpp)

> Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

### Exercise 1.12

> What does the following `for` loop do? What is the final value of `sum`?
>
> ```c++
> int sum = 0;
> for (int i = -100; i <= 100; ++i)
>        sum += i;
> ```

**Answer:** It sums integers in `[-100, 100]`. The final value of `sum` is 0.

### [Exercise 1.13](01-13.cpp)

> Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

### Exercise 1.14

> Compare and contrast the loops that used a `for` with those using a `while`. Are there advantages or disadvantages to using either form?

**Answer:**

- `while` is the most primitive loop form. It tests the condition before doing anything.
- `for` is a second form to write a loop. It is designed for certain patterns. It defines a control variable local to the loop and it separates the increment for clarity. It is more frequently used when the number of iterations is known in advance, and the increment following an iteration is simple.

### [Exercise 1.15](01-15.cpp)

> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

### [Exercise 1.16](01-16.cpp)

> Write your own version of a program that prints the sum of a set of integers read from `cin`.

### [Exercise 1.17](01-17.cpp)

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?
>
> ```c++
> #include <iostream>
>
> int main()
> {
>     // currVal is the number we're counting; we'll read new values into val
>     int currVal = 0, val = 0;
>     // read first number and ensure that we have data to process
>     if (std::cin >> currVal) {
>         int cnt = 1;  // store the count for the current value we're processing
>         while (std::cin >> val) { // read the remaining numbers
>             if (val == currVal)   // if the values are the same
>                 ++cnt;            // add 1 to cnt
>             else { // otherwise, print the count for the previous value
>                 std::cout << currVal << " occurs "
>                           << cnt << " times" << std::endl;
>                 currVal = val;    // remember the new value
>                 cnt = 1;          // reset the counter
>             }
>         }  // while loop ends here
>         // remember to print the count for the last value in the file
>         std::cout << currVal <<  " occurs "
>                   << cnt << " times" << std::endl;
>         } // outermost if statement ends here
>        return 0;
> }
> ```

**Answer:** At first glance, the output is just as expected.

- If input values are all equal

Given input `42 42 42`, the output would be

```
42 occurs 3 times
```

- If no duplicated values

Given input `42 43 44`, the output would be

```
42 occurs 1 times.
43 occurs 1 times.
44 occurs 1 times.
```

However, there are subtleties in the process of input and output.

Let `EOF` stand for `Ctrl-D` for Linux and `Ctrl-Z + ENTER` for Windows. The real input/output process on a console (Linux terminal/Windows command prompt) is

```
Input : 42 42 42 [Enter]
Output:
Input : [EOF]
Output: 42 occurs 3 times
```

and

```
Input : 42 43 44 [Enter]
Output: 42 occurs 1 times
        43 occurs 1 times
Input : [EOF]
Output: 44 occurs 1 times
```

*Q: Why does the last line not show up until `EOF` is hit?*

*A: In the case of `42 42 42`, `std::cin` is still good after the three `42` are entered. It awaits an `EOF` to fail it, or to terminate the input process, and then the result is printed out.*

*In the case of `42 43 44`, the first two numbers (`42` `43`) are immediately printed out, because the program sees a different value later. The last number (`44`) is not immediately printed out by the same token -- `std::cin` is still good, awaiting an `EOF` to terminate the input process.*

*By the way, is it possible that the first two numbers (`42` `43`) are buffered and not printed out immediately? No. Because the library ties `std::cout` to `std::cin`, and an attempt to read by `std::cin >> val` will cause the buffer associated with `std::cout` to flush (see page 315, 8.1.3 Managing the Output Buffer).*


### [Exercise 1.18](01-18.cpp)

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

### [Exercise 1.19](01-19.cpp)

> Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

### [Exercise 1.20](01-20.cpp)

> http://www.informit.com/title/032174113 contains a copy of `Sales_item.h` in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

### [Exercise 1.21](01-21.cpp)

> Write a program that reads two `Sales_item` objects that have the same ISBN and produces their sum.

### [Exercise 1.22](01-22.cpp)

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

### [Exercise 1.23](01-23.cpp)

> Write a program that reads several transactions and counts how many transactions occur for each ISBN.

### Exercise 1.24

> Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

**Answer:** The previous [program](01-23.cpp) can be tested against the input data in [records](../data/records) using *file redirection*.

```
[command] <[input filename] >[output filename]
```

For example, on a Linux Terminal, with executable file `01-23` in the `binary` directory, enter

```
./01-23 <../data/records
```

Or, on a Windows command prompt, with executable file `01-23.exe` in the `binary` folder, enter

```
01-23.exe <../data/records
```

### [Exercise 1.25](01-25.cpp)

> Using the [`Sales_item.h`](../include/Sales_item.h) header from the Web site, compile and execute the bookstore program presented in this section.

[Back to Top](#chapter-1-getting-started)

