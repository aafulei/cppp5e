# Chapter 9 Sequential Containers

- [Section 9.1 Overview of the Sequential Containers](#section-91-overview-of-the-sequential-containers)
  - *Exercises* [`9.1`](#exercise-91)

- [Section 9.2 Container Library Overview](#section-92-container-library-overview)
  - *Exercises* [`9.2`](#exercise-92)
  - *Exercises* [`9.3`](#exercise-93) [`9.4`](#exercise-94) [`9.5`](#exercise-95) [`9.6`](#exercise-96)
  - *Exercises* [`9.7`](#exercise-97) [`9.8`](#exercise-98)
  - *Exercises* [`9.9`](#exercise-99) [`9.10`](#exercise-910)
  - *Exercises* [`9.11`](#exercise-911) [`9.12`](#exercise-912) [`9.13`](#exercise-913)
  - *Exercises* [`9.14`](#exercise-914)
  - *Exercises* [`9.15`](#exercise-915) [`9.16`](#exercise-916) [`9.17`](#exercise-917)

- [Section 9.3 Sequential Container Operations](#section-93-sequential-container-operations)
  - *Exercises* [`9.18`](#exercise-918) [`9.19`](#exercise-919) [`9.20`](#exercise-920) [`9.21`](#exercise-921) [`9.22`](#exercise-922)
  - *Exercises* [`9.23`](#exercise-923) [`9.24`](#exercise-924)
  - *Exercises* [`9.25`](#exercise-925) [`9.26`](#exercise-926)
  - *Exercises* [`9.27`](#exercise-927) [`9.28`](#exercise-928)
  - *Exercises* [`9.29`](#exercise-929) [`9.30`](#exercise-930)
  - *Exercises* [`9.31`](#exercise-931) [`9.32`](#exercise-932) [`9.33`](#exercise-933) [`9.34`](#exercise-934)

- [Section 9.4 How a vector Grows](#section-94-how-a-vector-grows)
  - *Exercises* [`9.35`](#exercise-935) [`9.36`](#exercise-936) [`9.37`](#exercise-937) [`9.38`](#exercise-938) [`9.39`](#exercise-939) [`9.40`](#exercise-940)

- [Section 9.5 Additional string Operations](#section-95-additional-string-operations)
  - *Exercises* [`9.41`](#exercise-941) [`9.42`](#exercise-942)
  - *Exercises* [`9.43`](#exercise-943) [`9.44`](#exercise-944) [`9.45`](#exercise-945) [`9.46`](#exercise-946)
  - *Exercises* [`9.47`](#exercise-947) [`9.48`](#exercise-948) [`9.49`](#exercise-949)
  - *Exercises* [`9.50`](#exercise-950) [`9.51`](#exercise-951)

- [Section 9.6 Container Adaptors](#section-96-container-adaptors)
  - *Exercises* [`9.52`](#exercise-952)

## Section 9.1 Overview of the Sequential Containers

### Exercise 9.1

> Which is the most appropriate -- a `vector`, a `deque`, or a `list` -- for the following program tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not.
>
> (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We'll see in the next chapter that associative containers are better suited to this problem.
>
> (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
>
> (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

**Answer:**

(a) use a `list`, because we need to insert/delete elements in the middle of the container

(b) use a `deque`, because we only need to insert/delete elements at the front and the back of the container

(c) use a `vector`, because we only need to insert elements at the back of the container

## Section 9.2 Container Library Overview

### Exercise 9.2

> Define a `list` that holds elements that are `deque`s that hold `int`s.

**Answer:**

- [`09-02.cpp`](09-02.cpp)

### Exercise 9.3

> What are the constraints on the iterators that form iterator ranges?

**Answer:**

A pair of iterators `begin` and `end` form an iterator range if

1. they refer to the same container

2. it is possible to reach `end` by repeatedly incrementing `begin`. In other words, `end` must not precede `begin`.

### Exercise 9.4

> Write a function that takes a pair of iterators to a `vector<int>` and an `int` value. Look for that value in the range and return a `bool` indicating whether it was found.

**Answer:**

- [`09-04.cpp`](09-04.cpp)

### Exercise 9.5

> Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.
>
> *^ i.e. exercise [`9.4`](#exercise-94)*

**Answer:**

- [`09-05.cpp`](09-05.cpp)

### Exercise 9.6

> What is wrong with the following program? How might you correct it?
>
> ```c++
> list<int> lst1;
> list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
> while (iter1 < iter2) /* ... */
> ```

**Answer:**

Problem - operator `<` is not defined for `list<int>::itertor`. Fix -

```c++
while (iter1 != iter2) /* ... */
```

### Exercise 9.7

> What type should be used as the index into a `vector` of `int`s?

**Answer:**

`std::vector<int>::size_type`

### Exercise 9.8

> What type should be used to read elements in a `list` of `string`s? To write them?

**Answer:**

- To read, use `std::list<std::string>::const_iterator`

- To write, use `std::list<std::string>::iterator`

### Exercise 9.9

> What is the difference between the `begin` and `cbegin` functions?

**Answer:**

- `begin` is overloaded

  - `c.begin()` returns `iterator` if the container `c` is non-`const`

  - `c.begin()` returns `const_iterator` if the container `c` is `const`

- `c.cbegin()` always returns a `const_iterator` no matter if the container `c` is `const` or not

### Exercise 9.10

> What are the types of the following four objects?
>
> ```c++
> vector<int> v1;
> const vector<int> v2;
> auto it1 = v1.begin(), it2 = v2.begin();  // WRONG CODE
> auto it3 = v1.cbegin(), it4 = v2.cbegin();
> ```
>
> *The original code is wrong. Should be*
>
> ```c++
> vector<int> v1;
> const vector<int> v2;
> auto it1 = v1.begin();
> auto it2 = v2.begin();
> auto it3 = v1.cbegin();
> auto it4 = v2.cbegin();
> ```

**Answer:**

| Object | Type                               |
| ------ | ---------------------------------- |
| `it1`  | `std::vector<int>::iterator`       |
| `it2`  | `std::vector<int>::const_iterator` |
| `it3`  | `std::vector<int>::const_iterator` |
| `it4`  | `std::vector<int>::const_iterator` |

### Exercise 9.11

> Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.

**Answer:**

- [`09-11.cpp`](09-11.cpp)

### Exercise 9.12

> Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

**Answer:**

- *initialize with a container* -- both the container types and the element types must be identical;

- *initialize with a pair of iterators* -- the container types need *not* be identical, and the element types can be different, too, so long as conversion is possible.

### Exercise 9.13

> How would you initialize a `vector<double>` from a `list<int>`? From a vector<int>? Write code to check your answers.

**Answer:**

```c++
std::vector<double> vec(lst.begin(), lst.end());
```

- [`09-13.cpp`](09-13.cpp)

### Exercise 9.14

> Write a program to assign the elements from a `list` of `char *` pointers to C-style character strings to a vector of strings.

**Answer:**

- [`09-14.cpp`](09-14.cpp)

### Exercise 9.15

> Write a program to determine whether two `vector<int>`s are equal.

**Answer:**

- [`09-15.cpp`](09-15.cpp)

### Exercise 9.16

> Repeat the previous program, but compare elements in a list<int> to a vector<int>.
>
> *^ i.e. exercise [`9.15`](#exercise-915)*

**Answer:**

- [`09-16.cpp`](09-16.cpp)

### Exercise 9.17

> Assuming `c1` and `c2` are containers, what (if any) constraints does the following usage place on the types of `c1` and `c2`?
>
> ```c++
> if (c1 < c2)
> ```

**Answer:**

 `c1` and `c2` must have the same container type. The container type cannot be unordered associative. Besides, `<` must be defined for the element type.

## Section 9.3 Sequential Container Operations

### Exercise 9.18

> Write a program to read a sequence of strings from the standard input into a `deque`. Use iterators to write a loop to print the elements in the `deque`.

**Answer:**

- [`09-18.cpp`](09-18.cpp)

### Exercise 9.19

> Rewrite the program from the previous exercise to use a `list`. List the changes you needed to make.
>
> *^ i.e. exercise [`9.18`](#exercise-918)*

**Answer:**

Only need to change `std::deque` to `std::list`.

- [`09-19.cpp`](09-19.cpp)

### Exercise 9.20

> Write a program to copy elements from a `list<int>` into two `deque`s. The even-valued elements should go into one `deque` and the odd ones into the other.

**Answer:**

- [`09-20.cpp`](09-20.cpp)

### Exercise 9.21

> Explain how the loop from *page 345* that used the return from `insert` to add elements to a `list` would work if we inserted into a `vector` instead.
>
> ```c++
> list<string> lst;
> auto iter = lst.begin();
> while (cin >> word) {
>   iter = lst.insert(iter, word);
> }
> ```

**Answer:**

It would achieve the same effect, but since insertion at the front of a `vector` could be expensive, it might take more time.

### Exercise 9.22

> Assuming `iv` is a `vector` of `int`s, what is wrong with the following program? How might you correct the problem(s)?
>
> ```c++
> vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
> while (iter != mid)
>   if (*iter == some_val)
>     iv.insert(iter, 2 * some_val);
> ```

**Answer:**

Problems -

1. the program should not store the iterator value in `mid`
2. the program should update `iter` using the return value from `insert()`
3. the program should update `iter` at the end of each loop
4. if `mid` means the original middle, the program should count the number of inserted elements and adjust accordingly

Fix -

```c++
vector<int>::iterator iter = iv.begin();
for (int count = 0; iter != iv.begin() + (iv.size() + count) / 2; // adjust
     ++iter) {
  if (*iter == some_val) {
    iter = iv.insert(iter, 2 * some_val) + 1;
    ++count;
  }
}
```

- [`09-22.cpp`](09-22.cpp)

### Exercise 9.23

> In the first program in this section on *page 346*, what would the values of `val`, `val2`, `val3`, and `val4` be if `c.size()` is 1?
>
> ```c++
> if (!c.empty()) {
>     // val and val2 are copies of the value of the first element in c
>     auto val = *c.begin(), val2 = c.front();
>     // val3 and val4 are copies of the of the last element in c
>     auto last = c.end();
>     auto val3 = *(--last); // can't decrement forward_list iterators
>     auto val4 = c.back();  // not supported by forward_list
> }
> ```

**Answer:**

All of them would have the value of the only element in the container.

### Exercise 9.24

> Write a program that fetches the first element in a vector using at, the subscript operator, front, and begin. Test your program on an empty vector.

**Answer:**

- [`09-24.cpp`](09-24.cpp)

### Exercise 9.25

> In the program on *page 349* that erased a range of elements, what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the off-the-end iterator?

**Answer:**

### Exercise 9.26

> Using the following definition of ia, copy ia into a vector and into a list. Use the single-iterator form of erase to remove the elements with odd values from your list and the even values from your vector.
>
> ```c++
> int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
> ```

**Answer:**

### Exercise 9.27

> Write a program to find and remove the odd-valued elements in a forward_list<int>.

**Answer:**

- [`09-27.cpp`](09-27.cpp)

### Exercise 9.28

> Write a function that takes a forward_list<string> and two additional string arguments. The function should find the first string and insert the second immediately following the first. If the first string is not found, then insert the second string at the end of the list.

**Answer:**

- [`09-28.cpp`](09-28.cpp)

### Exercise 9.29

> Given that vec holds 25 elements, what does vec.resize(100) do? What if we next wrote vec.resize(10)?

**Answer:**

### Exercise 9.30

> What, if any, restrictions does using the version of resize that takes a single argument place on the element type?

**Answer:**

### Exercise 9.31

> The program on *page 354* to remove even-valued elements and duplicate odd ones will not work on a list or forward_list. Why? Revise the program so that it works on these types as well.

**Answer:**

- [`09-31.cpp`](09-31.cpp)

### Exercise 9.32

> In the program on *page 354* would it be legal to write the call to insert as follows? If not, why not?
>
> ```c++
> iter = vi.insert(iter, *iter++);
> ```

**Answer:**

### Exercise 9.33

> In the final example in this section what would happen if we did not assign the result of insert to begin? Write a program that omits this assignment to see if your expectation was correct.

**Answer:**

- [`09-33.cpp`](09-33.cpp)

### Exercise 9.34

> Assuming vi is a container of ints that includes even and odd values, predict the behavior of the following loop. After you've analyzed this loop, write a program to test whether your expectations were correct.
>
> ```c++
> iter = vi.begin();
> while (iter != vi.end())
>   if (*iter % 2)
>     iter = vi.insert(iter, *iter);
> ++iter;
> ```

**Answer:**

## Section 9.4 How a vector Grows

### Exercise 9.35

> Explain the difference between a vector's capacity and its size.

**Answer:**

### Exercise 9.36

> Can a container have a capacity less than its size?

**Answer:**

### Exercise 9.37

> Why don't list or array have a capacity member?

**Answer:**

### Exercise 9.38

> Write a program to explore how vectors grow in the library you use.

**Answer:**

- [`09-38.cpp`](09-38.cpp)

### Exercise 9.39

> Explain what the following program fragment does:
>
> ```c++
> vector<string> svec;
> svec.reserve(1024);
> string word;
> while (cin >> word)
>   svec.push_back(word);
> svec.resize(svec.size() + svec.size() / 2);
> ```

**Answer:**

### Exercise 9.40

> If the program in the previous exercise reads 256 words, what is its likely capacity after it is resized? What if it reads 512? 1,000? 1,048?

**Answer:**

## Section 9.5 Additional string Operations

### Exercise 9.41

> Write a program that initializes a string from a vector<char>.

**Answer:**

- [`09-41.cpp`](09-41.cpp)

### Exercise 9.42

> Given that you want to read a character at a time into a string, and you know that you need to read at least 100 characters, how might you improve the performance of your program?

**Answer:**

### Exercise 9.43

> Write a function that takes three strings, s, oldVal, and newVal. Using iterators, and the insert and erase functions replace all instances of oldVal that appear in s by newVal. Test your function by using it to replace common abbreviations, such as "tho" by "though" and "thru" by "through".

**Answer:**

- [`09-43.cpp`](09-43.cpp)

### Exercise 9.44

> Rewrite the previous function using an index and replace.

**Answer:**

- [`09-44.cpp`](09-44.cpp)

### Exercise 9.45

> Write a funtion that takes a string representing a name and two other strings representing a prefix, such as "Mr." or "Ms." and a suffix, such as "Jr." or "III". Using iterators and the insert and append functions, generate and return a new string with the suffix and prefix added to the given name.

**Answer:**

- [`09-45.cpp`](09-45.cpp)

### Exercise 9.46

> Rewrite the previous exercise using a position and length to manage the strings. This time use only the insert function.

**Answer:**

- [`09-46.cpp`](09-46.cpp)

### Exercise 9.47

> Write a program that finds each numeric character and then each alphabetic character in the string "ab2c3d7R4E6". Write two versions of the program. The first should use find_first_of, and the second find_first_not_of.

**Answer:**

- [`09-47.cpp`](09-47.cpp)

### Exercise 9.48

> Given the definitions of name and numbers on *page 365*, what does numbers.find(name) return?

**Answer:**

### Exercise 9.49

> A letter has an ascender if, as with d or f, part of the letter extends above the middle of the line. A letter has a descender if, as with p or g, part of the letter extends below the line. Write a program that reads a file containing words and reports the longest word that contains neither ascenders nor descenders.

**Answer:**

- [`09-49.cpp`](09-49.cpp)

### Exercise 9.50

> Write a program to process a vector<string>s whose elements represent integral values. Produce the sum of all the elements in that vector. Change the program so that it sums of strings that represent floating-point values.

**Answer:**

- [`09-50.cpp`](09-50.cpp)

### Exercise 9.51

> Write a class that has three unsigned members representing year, month, and day. Write a constructor that takes a string representing a date. Your constructor should handle a variety of date formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.

**Answer:**

- [`09-51.cpp`](09-51.cpp)

## Section 9.6 Container Adaptors

### Exercise 9.52

> Use a stack to process parenthesized expressions. When you see an open parenthesis, note that it was seen. When you see a close parenthesis after an open parenthesis, pop elements down to and including the open parenthesis off the stack. push a value onto the stack to indicate that a parenthesized expression was replaced.

**Answer:**

