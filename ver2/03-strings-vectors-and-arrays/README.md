# Chapter 3 Strings, Vectors, and Arrays

- [Section 3.1 Namespace `using` Declarations](#section-31-namespace-using-declarations)
  - Exercises [`3.1`](#exercise-31)

- [Section 3.2 Library `string` Type](#section-32-library-string-type)
  - Exercises [`3.2`](#exercise-32) [`3.3`](#exercise-33) [`3.4`](#exercise-34) [`3.5`](#exercise-35)
  - Exercises [`3.6`](#exercise-36) [`3.7`](#exercise-37) [`3.8`](#exercise-38) [`3.9`](#exercise-39) [`3.10`](#exercise-310) [`3.11`](#exercise-311)

- [Section 3.3 Library `vector` Type](#section-33-library-vector-type)
  - Exercises [`3.12`](#exercise-312) [`3.13`](#exercise-313)
  - Exercises [`3.14`](#exercise-314) [`3.15`](#exercise-315)
  - Exercises [`3.16`](#exercise-316) [`3.17`](#exercise-317) [`3.18`](#exercise-318) [`3.19`](#exercise-319) [`3.20`](#exercise-320)

- [Section 3.4 Introducing Iterators](#section-34-introducing-iterators)
  - Exercises [`3.21`](#exercise-321) [`3.22`](#exercise-322) [`3.23`](#exercise-323)
  - Exercises [`3.24`](#exercise-324) [`3.25`](#exercise-325) [`3.26`](#exercise-326)

- [Section 3.5 Arrays](#section-35-arrays)
  - Exercises [`3.27`](#exercise-327) [`3.28`](#exercise-328) [`3.29`](#exercise-329)
  - Exercises [`3.30`](#exercise-330) [`3.31`](#exercise-331) [`3.32`](#exercise-332) [`3.33`](#exercise-333)
  - Exercises [`3.34`](#exercise-334) [`3.35`](#exercise-335) [`3.36`](#exercise-336)
  - Exercises [`3.37`](#exercise-337) [`3.38`](#exercise-338) [`3.39`](#exercise-339) [`3.40`](#exercise-340)
  - Exercises [`3.41`](#exercise-341) [`3.42`](#exercise-342)

- [Section 3.6 Multidimensional Arrays](#section-36-multidimensional-arrays)
  - Exercises [`3.43`](#exercise-343) [`3.44`](#exercise-344)
  - Exercises [`3.45`](#exercise-345)


## Section 3.1 Namespace `using` Declarations

### Exercise 3.1

> Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appropriate using declarations.
>
> *^ i.e. exercises [`1.9`](../01-getting-started/README.md#exercise-19) [`1.10`](../01-getting-started/README.md#exercise-110) [`1.11`](../01-getting-started/README.md#exercise-111) [`2.41`](../02-variables-and-basic-types/README.md#exercise-241)*

**Answers:**

- [`03-01-sum-from-50-to-100.cpp`](03-01-sum-from-50-to-100.cpp) *rewrites* [`01-09-sum-from-50-to-100.cpp`](../01-getting-started/01-09-sum-from-50-to-100.cpp)

- [`03-01-decrement-from-10-to-0.cpp`](03-01-decrement-from-10-to-0.cpp) *rewrites* [`01-10-decrement-from-10-to-0.cpp`](../01-getting-started/01-10-decrement-from-10-to-0.cpp)

- [`03-01-print-numbers-in-range.cpp`](03-01-print-numbers-in-range.cpp) *rewrites* [`01-11-print-numbers-in-range.cpp`](../01-getting-started/01-11-print-numbers-in-range.cpp)

- [`03-01-read-books.cpp`](03-01-read-books.cpp) *rewrites* [`02-41-read-books.cpp`](../02-variables-and-basic-types/02-41-read-books.cpp)

- [`03-01-sum-two-books.cpp`](03-01-sum-two-books.cpp) *rewrites* [`02-41-sum-two-books.cpp`](../02-variables-and-basic-types/02-41-sum-two-books.cpp)

- [`03-01-sum-several-books.cpp`](03-01-sum-several-books.cpp) *rewrites* [`02-41-sum-several-books.cpp`](../02-variables-and-basic-types/02-41-sum-several-books.cpp)

- [`03-01-count-books.cpp`](03-01-count-books.cpp) *rewrites* [`02-41-count-books.cpp`](../02-variables-and-basic-types/02-41-count-books.cpp)

- [`03-01-bookstore.cpp`](03-01-bookstore.cpp) *rewrites* [`02-41-bookstore.cpp`](../02-variables-and-basic-types/02-41-bookstore.cpp)

## Section 3.2 Library `string` Type

### Exercise 3.2

> Write a program to read the standard input a line at a time. Modify your program to read a word at a time.

**Answers:**

- [`03-02-read-lines.cpp`](03-02-read-lines.cpp)

- [`03-02-read-words.cpp`](03-02-read-words.cpp)

### Exercise 3.3

> Explain how whitespace characters are handled in the string input operator and in the `getline` function.

**Answers:**

- Input operator `>>`

  Reads all the characters before the first whitespace character or `EOF`, ignoring leading whitespaces

  *^ Whitespaces characters include spaces, tabs, and newlines*

- `std::getline`

  Reads all the characters before the first newline or `EOF`

### Exercise 3.4

> Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.

**Answers:**

- [`03-04-compare-str.cpp`](03-04-compare-str.cpp)

- [`03-04-compare-str-sizes.cpp`](03-04-compare-str-sizes.cpp)

### Exercise 3.5

> Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.

**Answers:**

- [`03-05-concat-str.cpp`](03-05-concat-str.cpp)

- [`03-05-concat-str-with-spaces.cpp`](03-05-concat-str-with-spaces.cpp)

### Exercise 3.6

> Use a range for to change all the characters in a string to `X`.

**Answers:**

- [`03-06-range-for-str.cpp`](03-06-range-for-str.cpp)

### Exercise 3.7

> What would happen if you define the loop control variable in the previous exercise as type `char`? Predict the results and then change your program to use a char to see if you were right.

**Answers:**

The string would not be changed.

- [`03-07-range-for-str.cpp`](03-07-range-for-str.cpp)

### Exercise 3.8

> Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?

**Answers:**

I prefer the range-for approach because it avoids out-of-rangg subscripting.

- [`03-08-range-for-str.cpp`](03-08-range-for-str.cpp)

### Exercise 3.9

> What does the following program do? Is it valid? If not, why not?
>
> ```c++
> string s;
> cout << s[0] << endl;
> ```

**Answers:**

The program tries to print out the first character in empty string `s`. It is invalid, because subscripting an empty string has *undefined behavior*.

### Exercise 3.10

> Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.

**Answers:**

- [`03-10-remove-punct.cpp`](03-10-remove-punct.cpp)

### Exercise 3.11

> Is the following range for legal? If so, what is the type of `c`?

```c++
const string s = "Keep out!";
for (auto &c : s) { /* ...  */ }
```

**Answers:**

Yes, the range for is legal. The type of `c` is `const char &`.

- [`03-11-range-for-str.cpp`](03-11-range-for-str.cpp)

## Section 3.3 Library `vector` Type

### Exercise 3.12

> Which, if any, of the following `vector` definitions are in error ? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.
>
> (a) `vector<vector<int>> ivec;`
>
> (b) `vector<string> svec = ivec;`
>
> (c) `vector<string> svec(10, "null");`

**Answers:**

(a) legal - a vector of vectors, each of which is an empty `vector<int>`

(b) illegal - cannot initiliaze a `vector<string>` from a `vector<int>`

(c) legal - a `vector<string>` initialized with 10 `string` elements, each of which has value `"null"`

### Exercise 3.13

> How many elements are there in each of the following `vector`s? What are the values of the elements?
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

**Answers:**

(a) 0 `int` elements

(b) 10 `int` elements; each has value `0`

(c) 10 `int` elements; each has value `42`

(d) 1 `int` element; value is `10`

(e) 2 `int` elements; first has value `10`, second has value `42`

(f) 10 `string` elements; each is an empty string

(g) 10 `string` elements; each has value `"hi"`

### Exercise 3.14

> Write a program to read a sequence of `int`s from `cin` and store those values in a `vector`.

**Answers:**

- [`03-14-vector-int.cpp`](03-14-vector-int.cpp)

### Exercise 3.15

> Repeat the previous program but read strings this time.

**Answers:**

- [`03-15-vector-str.cpp`](03-15-vector-str.cpp)

### Exercise 3.16

> Write a program to print the size and contents of the vectors from exercise [`3.13`](#exercise-313). Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.

**Answers:**

- [`03-16-vector-print.cpp`](03-16-vector-print.cpp)

### Exercise 3.17

> Read a sequence of words from `cin` and store the values in a `vector`. After you've read all the words, process the `vector` and change each word to `uppercase`. Print the transformed elements, eight words to a line.

**Answers:**

- [`03-17-uppercase.cpp`](03-17-uppercase.cpp)

### Exercise 3.18

> Is the following program legal? If not, how might you fix it?
>
> ```c++
> vector<int> ivec;
> ivec[0] = 42;
> ```

**Answers:**

No, it is illegal, because subscripting does not add elements.

```c++
vector<int> ivec;
ivec.push_back(42);
```

### Exercise 3.19

> List three ways to define a `vector` and give it ten elements, each with value 42. Indicate whether there is a preferred way to do so and why.

**Answers:**

1.

```c++
std::vector<int> vec(10, 42);
```

2.

```c++
vector<int> vec{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
```

3.

```c++
std::vector<int> vec;
for (decltype(vec.size()) i = 0; i != 10; ++i) {
  vec.push_back(42)
}
```

The first approach is preferred for simplicity.

### Exercise 3.20

> Read a set of integers into a `vector`. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.

**Answers:**

- [`03-20-sum-adjacent-pairs.cpp`](03-20-sum-adjacent-pairs.cpp)

- [`03-20-sum-symmetric-pairs.cpp`](03-20-sum-symmetric-pairs.cpp)

## Section 3.4 Introducing Iterators

### Exercise 3.21

> Redo the first exercise from § 3.3.3 (p. 105) using iterators.
>
> *^ i.e. exercise [`3.16`](#exercise-316)*

**Answers:**

- [`03-21-vector-print.cpp`](03-21-vector-print.cpp) *rewrites* [`03-16-vector-print.cpp`](03-16-vector-print.cpp)

### Exercise 3.22

> Revise the loop that printed the first paragraph in `text` to instead change the elements in `text` that correspond to the first paragraph to all uppercase. After you’ve updated `text`, print its contents.
>
> ```c++
> for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
>   cout << *it << endl;
> }
> ```

**Answers:**

- [`03-22-uppercase.cpp`](03-22-uppercase.cpp)

### Exercise 3.23

> Write a program to create a `vector` with ten `int` elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the `vector`.

**Answers:**

- [`03-23-vector-int.cpp`](03-23-vector-int.cpp)

### Exercise 3.24

> Redo the last exercise from § 3.3.3 (p. 105) using iterators.
>
> *^ i.e. exercise [`3.20`](exercise-320)*

**Answers:**

- [`03-24-sum-adjacent-pairs.cpp`](03-24-sum-adjacent-pairs.cpp) *rewrites* [`03-20-sum-adjacent-pairs.cpp`](03-20-sum-adjacent-pairs.cpp)

- [`03-24-sum-symmetric-pairs.cpp`](03-24-sum-symmetric-pairs.cpp) *rewrites* [`03-20-sum-symmetric-pairs.cpp`](03-20-sum-symmetric-pairs.cpp)

### Exercise 3.25

> Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.

**Answers:**

- [`03-25-grades.cpp`](03-25-grades.cpp)

### Exercise 3.26

> In the binary search program on *page 112*, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) /2;`?

**Answers:**

`beg` and `end` are iterators. It is illegal to add two iterators.

## Section 3.5 Arrays

### Exercise 3.27

> Assuming `txt_size` is a function that takes no arguments and returns an `int` value, which of the following definitions are illegal? Explain why.
>
> `unsigned buf_size = 1024;`
>
> (a) `int ia[buf_size];`
>
> (b) `int ia[4 * 7 - 14];`
>
> (c) `int ia[txt_size()];`
>
> (d) `char st[11] = "fundamental";`

**Answers:**

(a) illegal - `buf_size` is not a constant expression

(b) legal - size of array (14) is known at compile time

(c) illegal - `txt_size` is not a `constexpr` function

(d) illegal - space not enough to store `"fundamental"`, which ends with a null character and takes up 12 characters

### Exercise 3.28

> What are the values in the following arrays?
>
> ```c++
> string sa[10];
> int ia[10];
> int main() {
>   string sa2[10];
>   int    ia2[10];
> }
> ```

**Answers:**

- `sa` - 10 empty strings

- `ia` - 10 zeros

- `sa2` - 10 empty strings

- `ia2` - 10 indeterminate values

### Exercise 3.29

> List some of the drawbacks of using an array instead of a `vector`.

**Answers:**

1. fixed size, which has to be known at compile time

2. no assignment using `=`

3. array-to-pointer conversion leads to a loss in dimension

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

**Answers:**

- [`03-31-array-of-10.cpp`](03-31-array-of-10.cpp)

### Exercise 3.32

> Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors.

**Answers:**

- [`03-32-copy-array.cpp`](03-32-copy-array.cpp)

- [`03-32-copy-vector.cpp`](03-32-copy-vector.cpp)

### Exercise 3.33

> What would happen if we did not initialize the `scores` array in the program on *page 116*?
>
> ```c++
> unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
> unsigned grade;
> while (cin >> grade) {
>   if (grade <= 100)
>   ++scores[grade/10]; // increment the counter for the current cluster
> }
> ```

**Answers:**

`scores` would have 11 `unsigned` elements of indeterminate values.

### Exercise 3.34

> Given that `p1` and `p2` point to elements in the same array, what does the following code do? Are there values of `p1` or `p2` that make this code illegal?
>
> ```c++
> p1 += p2 - p1;
> ```

**Answers:**

It points `p1` to the same element as does `p2`. No.

### Exercise 3.35

> Using pointers, write a program to set the elements in an array to zero.

**Answers:**

- [`03-35-zero-array.cpp`](03-35-zero-array.cpp)

### Exercise 3.36

> Write a program to compare two arrays for equality. Write a similar program to compare two `vector`s.

**Answers:**

- [`03-36-compare-arrays.cpp`](03-36-compare-arrays.cpp)

- [`03-36-compare-vectors.cpp`](03-36-compare-vectors.cpp)

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

**Answers:**

```
h
e
l
l
o
[Disaster]
```

### Exercise 3.38

> In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

**Answers:**

John lives at No.10 New Street. Mary lives at No.13. What's the meaning for adding No.10 and No.13? Pointers represent the physical addresses in the memory.

### Exercise 3.39

> Write a program to compare two `string`s. Now write a program to compare the values of two C-style character strings.

**Answers:**

- [`03-39-compare-std-strings.cpp`](03-39-compare-std-strings.cpp)

- [`03-39-compare-c-strings.cpp`](03-39-compare-c-strings.cpp)


### Exercise 3.40

> Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use `strcpy` and `strcat` to copy the two arrays into the third.

**Answers:**

- [`03-40-concat-char-arrays.cpp`](03-40-concat-char-arrays.cpp)

### Exercise 3.41

> Write a program to initialize a vector from an array of ints.

**Answers:**

- [`03-41-init-vector-from-array.cpp`](03-41-init-vector-from-array.cpp)

### Exercise 3.42

> Write a program to copy a vector of ints into an array of ints.

- [`03-42-copy-vector-into-array.cpp`](03-42-copy-vector-into-array.cpp)

**Answers:**

## Section 3.6 Multidimensional Arrays

### Exercise 3.43

> Write three different versions of a program to print the elements of `ia`. One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, `auto`, or `decltype` to simplify the code.

**Answers:**

- [`03-43-print-multidimentional-array.cpp`](03-43-print-multidimentional-array.cpp)

### Exercise 3.44

> Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.

**Answers:**

- [`03-44-print-multidimentional-array.cpp`](03-44-print-multidimentional-array.cpp)

### Exercise 3.45

> Rewrite the programs again, this time using auto.

**Answers:**

- [`03-45-print-multidimentional-array.cpp`](03-45-print-multidimentional-array.cpp)
