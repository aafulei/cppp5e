# Chapter 3 Strings, Vectors, and Arrays

- [Section 3.1 Namespace using Declarations](#section-31-namespace-using-declarations)
  - *Exercises* [`3.1`](#exercise-31)

- [Section 3.2 Library `string` Type](#section-32-library-string-type)
  - *Exercises* [`3.2`](#exercise-32) [`3.3`](#exercise-33) [`3.4`](#exercise-34) [`3.5`](#exercise-35)
  - *Exercises* [`3.6`](#exercise-36) [`3.7`](#exercise-37) [`3.8`](#exercise-38) [`3.9`](#exercise-39) [`3.10`](#exercise-310) [`3.11`](#exercise-311)

- [Section 3.3 Library `vector` Type](#section-33-library-vector-type)
  - *Exercises* [`3.12`](#exercise-312) [`3.13`](#exercise-313)
  - *Exercises* [`3.14`](#exercise-314) [`3.15`](#exercise-315)
  - *Exercises* [`3.16`](#exercise-316) [`3.17`](#exercise-317) [`3.18`](#exercise-318) [`3.19`](#exercise-319) [`3.20`](#exercise-320)

- [Section 3.4 Introducing Iterators](#section-34-introducing-iterators)
  - *Exercises* [`3.21`](#exercise-321) [`3.22`](#exercise-322) [`3.23`](#exercise-323)
  - *Exercises* [`3.24`](#exercise-324) [`3.25`](#exercise-325) [`3.26`](#exercise-326)

- [Section 3.5 Arrays](#section-35-arrays)
  - *Exercises* [`3.27`](#exercise-327) [`3.28`](#exercise-328) [`3.29`](#exercise-329)
  - *Exercises* [`3.30`](#exercise-330) [`3.31`](#exercise-331) [`3.32`](#exercise-332) [`3.33`](#exercise-333)
  - *Exercises* [`3.34`](#exercise-334) [`3.35`](#exercise-335) [`3.36`](#exercise-336)
  - *Exercises* [`3.37`](#exercise-337) [`3.38`](#exercise-338) [`3.39`](#exercise-339) [`3.40`](#exercise-340)
  - *Exercises* [`3.41`](#exercise-341) [`3.42`](#exercise-342)

- [Section 3.6 Multidimensional Arrays](#section-36-multidimensional-arrays)
  - *Exercises* [`3.43`](#exercise-343) [`3.44`](#exercise-344) [`3.45`](#exercise-345)

## Section 3.1 Namespace using Declarations

### Exercise 3.1

> Rewrite the exercises from Section 1.4.1 (p. 13) and Section 2.6.2 (p. 76) with appropriate using declarations.
>
> *^ i.e. exercises [`1.9`](../01-getting-started/README.md#exercise-19) [`1.10`](../01-getting-started/README.md#exercise-110) [`1.11`](../01-getting-started/README.md#exercise-111) [`2.41`](../02-variables-and-basic-types/README.md#exercise-241)*

**Answer:**

- [`03-01.cpp`](03-01.cpp)

## Section 3.2 Library `string` Type

### Exercise 3.2

> Write a program to read the standard input a line at a time. Modify your program to read a word at a time.

**Answer:**

- [`03-02.cpp`](03-02.cpp)

### Exercise 3.3

> Explain how whitespace characters are handled in the string input operator and in the `getline` function.

**Answer:**

- string input operator `is >> str`

  - Leading whitespaces are ignored.
  - Read and store all the characters until a whitespace character or the EOF is reached.
  - The ending whitespace character, if there is one, is not stored.

- `getline` function `getline(is, str)`

  - Do not ignore leading whitespaces, e.g. spaces or tabs.
  - Read and store all the characters until a newline or the EOF is reached.
  - The ending newline, if there is one, is not stored.

### Exercise 3.4

> Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.

**Answer:**

- [`03-04.cpp`](03-04.cpp)

### Exercise 3.5

> Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.

**Answer:**

- [`03-05.cpp`](03-05.cpp)

### Exercise 3.6

> Use a range `for` to change all the characters in a string to `X`.

**Answer:**

- [`03-06.cpp`](03-06.cpp)

### Exercise 3.7

> What would happen if you define the loop control variable in the previous exercise as type `char`? Predict the results and then change your program to use a char to see if you were right.

**Answer:**

 The string would not be changed.

- [`03-07.cpp`](03-07.cpp)

### Exercise 3.8

> Rewrite the program in the first exercise, first using a `while` and again using a traditional `for` loop. Which of the three approaches do you prefer and why?
>
> *^ i.e. exercise [`3.6`](#exercise-36)*

**Answer:**

In this particular example, I prefer the range `for` approach because it is simple and avoids out-of-range subscripting. However, in my opinion, range `for` loop only becomes useful after `init-statement` was introduced in C++20, because it is all too often that we need to know the element position in a `for` loop.

```c++
// C++20: print a space between each char in string
for (int i = 0; char c : str) {
  std::cout << (i++ == 0 ? "" : " ") << c;
}
std::cout << endl;
```

- [`03-08.cpp`](03-08.cpp)

### Exercise 3.9

> What does the following program do? Is it valid? If not, why not?
>
> ```c++
> string s;
> cout << s[0] << endl;
> ```

**Answer:**

The program tries to print out the first element in an empty string, which is invalid, because the subscripting goes out of range.

### Exercise 3.10

> Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.

**Answer:**

- [`03-10.cpp`](03-10.cpp)

### Exercise 3.11

> Is the following range `for` legal? If so, what is the type of `c`?
>
> ```c++
> const string s = "Keep out!";
> for (auto &c : s) { /* ... */
> }
> ```

**Answer:**

Yes, the range `for` is legal. The type of `c` is `const char &`. That is, a reference to `const char`.

- [`03-11.cpp`](03-11.cpp)

## Section 3.3 Library `vector` Type

### Exercise 3.12

> Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.
>
> (a) `vector<vector<int>> ivec;`
>
> (b) `vector<string> svec = ivec;`
>
> (c) `vector<string> svec(10, "null");`

**Answer:**

(a) legal - an empty vector of vectors. Each element of the vector is a vector of `int`.

(b) illegal - given that `ivec` is a `vector<int>`, it can't be assigned to a `vector<string>`

(c) legal - `svec` is a vector of 10 strings, each of which has value `"null"`

### Exercise 3.13

> How many elements are there in each of the following vectors? What are the values of the elements?
>
> (a) `vector<int> v1;`
>
> (b) `vector<int> v2(10);`
>
> (c) `vector<int> v3(10, 42);`
>
> (d) `vector<int> v4{10};`
>
> (e) `vector<int> v5{10, 42};`
>
> (f) `vector<string> v6{10};`
>
> (g) `vector<string> v7{10, "hi"};`

**Answer:**

(a) 0 elements

(b) 10 elements, each has value 0

(c) 10 elements, each has value 42

(d) 1 element, with value 10

(e) 2 elements, with values 10 and 42

(f) 10 elements, each is an empty string

(g) 10 elements, each has value `"hi"`

### Exercise 3.14

> Write a program to read a sequence of ints from `cin` and store those values in a vector.

**Answer:**

- [`03-14.cpp`](03-14.cpp)

### Exercise 3.15

> Repeat the previous program but read strings this time.

**Answer:**

- [`03-15.cpp`](03-15.cpp)

### Exercise 3.16

> Write a program to print the size and contents of the vectors from exercise [`3.13`](#exercise-313). Check whether your answers to that exercise were correct. If not, restudy Section 3.3.1 (p. 97) until you understand why you were wrong.

**Answer:**

- [`03-16.cpp`](03-16.cpp)

### Exercise 3.17

> Read a sequence of words from `cin` and store the values a vector. After you've read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.

**Answer:**

- [`03-17.cpp`](03-17.cpp)

### Exercise 3.18

> Is the following program legal? If not, how might you fix it?
>
> ```c++
> vector<int> ivec;
> ivec[0] = 42;
> ```

**Answer:**

No, the program is illegal, because `ivec` is an empty vector, and it is illegal to try to access its "first" element. Fix -

```c++
vector<int> ivec;
ivec.push_back(42);
```

### Exercise 3.19

> List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.

**Answer:**

1. start with an empty vector and push 10 elements to its back

  ```c++
  std::vector<int> vec1;
  int num = 10;
  while (num-- > 0) {
    vec1.push_back(42);
  }
  ```

2. value initialize a vector with 10 elements of value 42

  ```c++
  std::vector<int> vec2(10, 42);
  ```

3. list initialze a vector with 10 elements

  ```c++
  std::vector<int> vec3{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  ```

The second approach is preferred in this case, because it fits the purpose here - a given number of elements, each with the same value.

### Exercise 3.20

> Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.

**Answer:**

- [`03-20.cpp`](03-20.cpp)

## Section 3.4 Introducing Iterators

### Exercise 3.21

> Redo the first exercise from Section 3.3.3 (p. 105) using iterators.
>
> *^ i.e. exercise [`3.16`](#exercise-316)*

**Answer:**

- [`03-21.cpp`](03-21.cpp)

### Exercise 3.22

> Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you've updated text, print its contents.
>
> ```c++
> for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
>   cout << *it << endl;
> ```

**Answer:**

- [`03-22.cpp`](03-22.cpp)

### Exercise 3.23

> Write a program to create a vector with ten `int` elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.

**Answer:**

- [`03-23.cpp`](03-23.cpp)

### Exercise 3.24

> Redo the last exercise from Section 3.3.3 (p. 105) using iterators.
>
> *^ i.e. exercise [`3.20`](#exercise-320)*

**Answer:**

- [`03-24.cpp`](03-24.cpp)

### Exercise 3.25

> Rewrite the grade clustering program from Section 3.3.3 (p. 104) using iterators instead of subscripts.

**Answer:**

- [`03-25.cpp`](03-25.cpp)

### Exercise 3.26

> In the binary search program on *page 112*, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) /2;`?

**Answer:**

Because operator `+` is not defined between iterators.

## Section 3.5 Arrays

### Exercise 3.27

> Assuming `txt_size` is a function that takes no arguments and returns an `int` value, which of the following definitions are illegal? Explain why.
>
> ```c++
> unsigned buf_size = 1024;
> ```
>
> (a) `int ia[buf_size];`
>
> (b) `int ia[4 * 7 - 14];`
>
> (c) `int ia[txt_size()];`
>
> (d) `char st[11] = "fundamental";`

**Answer:**

(a) illegal - the dimension of an array must be a constant expression in declaration

(b) legal

(c) illegal, unless `txt_size()` is a `constexpr` function, otherwise the return value of `txt_size()` is not known at compile time

(d) illegal - `char` array `st` does not have enough room to hold `"fundamental"`, which ends with a null character `'\0'`, and has a size of 12

### Exercise 3.28

> What are the values in the following arrays?
>
> ```c++
> string sa[10];
> int ia[10];
> int main() {
>   string sa2[10];
>   int ia2[10];
> }
> ```

**Answer:**

- `sa` has 10 empty strings

- `ia` has 10 `int` elements, each with value `0`

- `sa2` has 10 empty strings

- `ia2` has 10 `int` elements, whose values are indeterministic

### Exercise 3.29

> List some of the drawbacks of using an array instead of a vector.

**Answer:**

1. an array has a fixed size, which has to be known at compile time

2. an array can't be directly passed to and returned from functions

3. an array can't be directly compared using operator `==` and can't be assigned using operator `=`

### Exercise 3.30

> Identify the indexing errors in the following code:
>
> ```c++
> constexpr size_t array_size = 10;
> int ia[array_size];
> for (size_t ix = 1; ix <= array_size; ++ix)
>   ia[ix] = ix;
> ```

**Answer:**

Accessing `ia[array_size]` has undefined behavior.

### Exercise 3.31

> Write a program to define an array of ten `int`s. Give each element the same value as its position in the array.

**Answer:**

- [`03-31.cpp`](03-31.cpp)

### Exercise 3.32

> Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors.
>
> *^ i.e. exercise [`3.31`](#exercise-331)*

**Answer:**

- [`03-32.cpp`](03-32.cpp)

### Exercise 3.33

> What would happen if we did not initialize the `scores` array in the program on *page 116*?

**Answer:**

The `scores` array would have 11 `unsigned` elements of indeterministic values.

### Exercise 3.34

> Given that `p1` and `p2` point to elements in the same array, what does the following code do? Are there values of `p1` or `p2` that make this code illegal?
>
> ```c++
> p1 += p2 - p1;
> ```

**Answer:**

Moving `p1` so that it points to the same element as does `p2`. No.

### Exercise 3.35

> Using pointers, write a program to set the elements in an array to zero.

**Answer:**

- [`03-35.cpp`](03-35.cpp)

### Exercise 3.36

> Write a program to compare two arrays for equality. Write a similar program to compare two vectors.

**Answer:**

- [`03-36.cpp`](03-36.cpp)

### Exercise 3.37

> What does the following program do?
>
> ```c++
> const char ca[] = {'h', 'e', 'l', 'l', 'o'};
> const char *cp = ca;
> while (*cp) {
>   cout << *cp << endl;
>   ++cp;
> }
> ```

**Answer:**

This program tries to print out all the characters in `char` array `ca`, each in one line. However, it has a bug. The one element past the end of `ca` has an indeterministic value, not necessarily `0`. Therefore, the `while` loop might not terminate as `cp` loops over `ca`.

### Exercise 3.38

> In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

**Answer:** Pointers are addresses in the physical memory. The difference between two addresses describes the distance between them. The sum of two addresses are just meaningless.

### Exercise 3.39

> Write a program to compare two strings. Now write a program to compare the values of two C-style character strings.

**Answer:**

- [`03-39.cpp`](03-39.cpp)

### Exercise 3.40

> Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use `strcpy` and `strcat` to copy the two arrays into the third.

**Answer:**

- [`03-40.cpp`](03-40.cpp)

### Exercise 3.41

> Write a program to initialize a vector from an array of `int`s.

**Answer:**

- [`03-41.cpp`](03-41.cpp)

### Exercise 3.42

> Write a program to copy a vector of ints into an array of ints.

**Answer:**

- [`03-42.cpp`](03-42.cpp)

## Section 3.6 Multidimensional Arrays

### Exercise 3.43

> Write three different versions of a program to print the elements of ia. One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, `auto`, or `decltype` to simplify the code.

**Answer:**

- [`03-43.cpp`](03-43.cpp)

### Exercise 3.44

> Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.

**Answer:**

- [`03-44.cpp`](03-44.cpp)

### Exercise 3.45

> Rewrite the programs again, this time using `auto`.

**Answer:**

- [`03-45.cpp`](03-45.cpp)

