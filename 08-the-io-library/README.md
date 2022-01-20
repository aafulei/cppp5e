# Chapter 8 The IO Library

- [Section 8.1 The IO Classes](#section-81-the-io-classes)
  - *Exercises* [`8.1`](#exercise-81) [`8.2`](#exercise-82) [`8.3`](#exercise-83)

- [Section 8.2 File Input and Output](#section-82-file-input-and-output)
  - *Exercises* [`8.4`](#exercise-84) [`8.5`](#exercise-85) [`8.6`](#exercise-86)
  - *Exercises* [`8.7`](#exercise-87) [`8.8`](#exercise-88)

- [Section 8.3 string Streams](#section-83-string-streams)
  - *Exercises* [`8.9`](#exercise-89) [`8.10`](#exercise-810) [`8.11`](#exercise-811) [`8.12`](#exercise-812)
  - *Exercises* [`8.13`](#exercise-813) [`8.14`](#exercise-814)

## Section 8.1 The IO Classes

### Exercise 8.1

> Write a function that takes and returns an `istream &`. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.

**Answer:**

- [`08-01.cpp`](08-01.cpp)

### Exercise 8.2

> Test your function by calling it, passing `cin` as an argument.

**Answer:**

### Exercise 8.3

> What causes the following `while` to terminate?
>
> ```c++
> while (cin >> i)
> /* ...
> ```

**Answer:**

## Section 8.2 File Input and Output

### Exercise 8.4

> Write a function to open a file for input and read its contents into a `vector` of `string`s, storing each line as a separate element in the `vector`.

**Answer:**

- [`08-04.cpp`](08-04.cpp)

### Exercise 8.5

> Rewrite the previous program to store each word in a separate element.

**Answer:**

- [`08-05.cpp`](08-05.cpp)

### Exercise 8.6

> Rewrite the bookstore program from Section 7.1.1 (p. 256) to read its transactions from a file. Pass the name of the file as an argument to `main` (Section 6.2.5, p. 218).

**Answer:**

- [`08-06.cpp`](08-06.cpp)

### Exercise 8.7

> Revise the bookstore program from the previous section to write its output to a file. Pass the name of that file as a second argument to `main`.

**Answer:**

- [`08-07.cpp`](08-07.cpp)

### Exercise 8.8

> Revise the program from the previous exercise to append its output to its given file. Run the program on the same output file at least twice to ensure that the data are preserved.

**Answer:**

- [`08-08.cpp`](08-08.cpp)

## Section 8.3 string Streams

### Exercise 8.9

> Use the function you wrote for the first exercise in Section 8.1.2 (p. 314) to print the contents of an `istringstream` object.

**Answer:**

- [`08-09.cpp`](08-09.cpp)

### Exercise 8.10

> Write a program to store each line from a file in a `vector<string>`. Now use an `istringstream` to read each element from the `vector` a word at a time.

**Answer:**

- [`08-10.cpp`](08-10.cpp)

### Exercise 8.11

> The program in this section defined its `istringstream` object inside the outer `while` loop. What changes would you need to make if `record` were defined outside that loop? Rewrite the program, moving the definition of `record` outside the `while`, and see whether you thought of all the changes that are needed.

**Answer:**

- [`08-11.cpp`](08-11.cpp)

### Exercise 8.12

> Why didn't we use in-class initializers in `PersonInfo`?

**Answer:**

### Exercise 8.13

> Rewrite the phone number program from this section to read from a named file rather than from `cin`.

**Answer:**

- [`08-13.cpp`](08-13.cpp)

### Exercise 8.14

> Why did we declare `entry` and `nums` as `const auto &`?

**Answer:**

