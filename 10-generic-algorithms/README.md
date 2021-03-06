# Chapter 10 Generic Algorithms

- [Section 10.1 Overview](#section-101-overview)
  - *Exercises* [`10.1`](#exercise-101) [`10.2`](#exercise-102)

- [Section 10.2 A First Look at the Algorithms](#section-102-a-first-look-at-the-algorithms)
  - *Exercises* [`10.3`](#exercise-103) [`10.4`](#exercise-104) [`10.5`](#exercise-105)
  - *Exercises* [`10.6`](#exercise-106) [`10.7`](#exercise-107) [`10.8`](#exercise-108)
  - *Exercises* [`10.9`](#exercise-109) [`10.10`](#exercise-1010)

- [Section 10.3 Customizing Operations](#section-103-customizing-operations)
  - *Exercises* [`10.11`](#exercise-1011) [`10.12`](#exercise-1012) [`10.13`](#exercise-1013)
  - *Exercises* [`10.14`](#exercise-1014) [`10.15`](#exercise-1015) [`10.16`](#exercise-1016) [`10.17`](#exercise-1017) [`10.18`](#exercise-1018) [`10.19`](#exercise-1019)
  - *Exercises* [`10.20`](#exercise-1020) [`10.21`](#exercise-1021)
  - *Exercises* [`10.22`](#exercise-1022) [`10.23`](#exercise-1023) [`10.24`](#exercise-1024) [`10.25`](#exercise-1025)

- [Section 10.4 Revisiting Iterators](#section-104-revisiting-iterators)
  - *Exercises* [`10.26`](#exercise-1026) [`10.27`](#exercise-1027) [`10.28`](#exercise-1028)
  - *Exercises* [`10.29`](#exercise-1029) [`10.30`](#exercise-1030) [`10.31`](#exercise-1031) [`10.32`](#exercise-1032) [`10.33`](#exercise-1033)
  - *Exercises* [`10.34`](#exercise-1034) [`10.35`](#exercise-1035) [`10.36`](#exercise-1036) [`10.37`](#exercise-1037)

- [Section 10.5 Structure of Generic Algorithms](#section-105-structure-of-generic-algorithms)
  - *Exercises* [`10.38`](#exercise-1038) [`10.39`](#exercise-1039) [`10.40`](#exercise-1040)
  - *Exercises* [`10.41`](#exercise-1041)

- [Section 10.6 Container-Specific Algorithms](#section-106-containerspecific-algorithms)
  - *Exercises* [`10.42`](#exercise-1042)

## Section 10.1 Overview

### Exercise 10.1

> The algorithm header defines a function named count that, like find, takes a pair of iterators and a value. count returns a count of how often that value appears. Read a sequence of ints into a vector and print the count of how many elements have a given value.

**Answer:**

### Exercise 10.2

> Repeat the previous program, but read values into a list of strings.

**Answer:**

## Section 10.2 A First Look at the Algorithms

### Exercise 10.3

> Use accumulate to sum the elements in a vector<int>.

**Answer:**

### Exercise 10.4

> Assuming v is a vector<double>, what, if anything, is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?

**Answer:**

### Exercise 10.5

> In the call to equal on rosters, what would happen if both rosters held C-style strings, rather than library strings?

**Answer:**

### Exercise 10.6

> Using fill_n, write a program to set a sequence of `int` values to 0.

**Answer:**

### Exercise 10.7

> Determine if there are any errors in the following programs and, if so, correct the error(s):
>
> (a)
> ```c++
> vector<int> vec; list<int> lst; int i;
> while (cin >> i)
>     lst.push_back(i);
> copy(lst.cbegin(), lst.cend(), vec.begin());
> ```
>
> (b)
> ```c++
> vector<int> vec;
> vec.reserve(10); // reserve is covered in Section 9.4 (p. 356)
> fill_n(vec.begin(), 10, 0);
> ```

**Answer:**

### Exercise 10.8

> We said that algorithms do not change the size of the containers over which they operate. Why doesn't the use of back_inserter invalidate this claim?

**Answer:**

### Exercise 10.9

> Implement your own version of elimDups. Test your program by printing the vector after you read the input, after the call to unique, and after the call to erase.

**Answer:**

- [`10-09.cpp`](10-09.cpp)

### Exercise 10.10

> Why do you think the algorithms don't change the size of containers?

**Answer:**

## Section 10.3 Customizing Operations

### Exercise 10.11

> Write a program that uses stable_sort and isShorter to sort a vector passed to your version of elimDups. Print the vector to verify that your program is correct.

**Answer:**

- [`10-11.cpp`](10-11.cpp)

### Exercise 10.12

> Write a function named compareIsbn that compares the isbn() members of two `Sales_data` objects. Use that function to sort a vector that holds `Sales_data` objects.

**Answer:**

- [`10-12.cpp`](10-12.cpp)

### Exercise 10.13

> The library defines an algorithm named partition that takes a predicate and partitions the container so that values for which the predicate is true appear in the first part and those for which the predicate is false appear in the second part. The algorithm returns an iterator just past the last element for which the predicate returned true. Write a function that takes a string and returns a bool indicating whether the string has five characters or more. Use that function to partition words. Print the elements that have five or more characters.

**Answer:**

- [`10-13.cpp`](10-13.cpp)

### Exercise 10.14

> Write a lambda that takes two ints and returns their sum.

**Answer:**

- [`10-14.cpp`](10-14.cpp)

### Exercise 10.15

> Write a lambda that captures an `int` from its enclosing function and takes an `int` parameter. The lambda should return the sum of the captured `int` and the `int` parameter.

**Answer:**

- [`10-15.cpp`](10-15.cpp)

### Exercise 10.16

> Write your own version of the biggies function using lambdas.

**Answer:**

- [`10-16.cpp`](10-16.cpp)

### Exercise 10.17

> Rewrite exercise 10.12 from Section 10.3.1 (p. 387) to use a lambda in the call to sort instead of the compareIsbn function.

**Answer:**

- [`10-17.cpp`](10-17.cpp)

### Exercise 10.18

> Rewrite biggies to use partition instead of find_if. We described the partition algorithm in exercise 10.13 in Section 10.3.1 (p. 387).

**Answer:**

- [`10-18.cpp`](10-18.cpp)

### Exercise 10.19

> Rewrite the previous exercise to use stable_partition, which like stable_sort maintains the original element order in the paritioned sequence.

**Answer:**

- [`10-19.cpp`](10-19.cpp)

### Exercise 10.20

> The library defines an algorithm named count_if. Like find_if, this function takes a pair of iterators denoting an input range and a predicate that it applies to each element in the given range. count_if returns a count of how often the predicate is true. Use count_if to rewrite the portion of our program that counted how many words are greater than length 6.

**Answer:**

### Exercise 10.21

> Write a lambda that captures a local `int` variable and decrements that variable until it reaches 0. Once the variable is 0 additional calls should no longer decrement the variable. The lambda should return a bool that indicates whether the captured variable is 0.

**Answer:**

- [`10-21.cpp`](10-21.cpp)

### Exercise 10.22

> Rewrite the program to count words of size 6 or less using functions in place of the lambdas.

**Answer:**

- [`10-22.cpp`](10-22.cpp)

### Exercise 10.23

> How many arguments does bind take?

**Answer:**

### Exercise 10.24

> Use bind and check_size to find the first element in a vector of ints that has a value greater than the length of a specified string value.

**Answer:**

### Exercise 10.25

> In the exercises for Section 10.3.2 (p. 392) you wrote a version of biggies that uses partition. Rewrite that function to use check_size and bind.

**Answer:**

- [`10-25.cpp`](10-25.cpp)

## Section 10.4 Revisiting Iterators

### Exercise 10.26

> Explain the differences among the three kinds of insert iterators.

**Answer:**

### Exercise 10.27

> In addition to unique (Section 10.2.3, p. 384), the library defines function named unique_copy that takes a third iterator denoting a destination into which to copy the unique elements. Write a program that uses unique_copy to copy the unique elements from a vector into an initially empty list.

**Answer:**

- [`10-27.cpp`](10-27.cpp)

### Exercise 10.28

> Copy a vector that holds the values from 1 to 9 inclusive, into three other containers. Use an inserter, a back_inserter, and a front_inserter, respectivly to add elements to these containers. Predict how the output sequence varies by the kind of inserter and verify your predictions by running your programs.

**Answer:**

### Exercise 10.29

> Write a program using stream iterators to read a text file into a vector of strings.

**Answer:**

- [`10-29.cpp`](10-29.cpp)

### Exercise 10.30

> Use stream iterators, sort, and copy to read a sequence of integers from the standard input, sort them, and then write them back to the standard output.

**Answer:**

### Exercise 10.31

> Update the program from the previous exercise so that it prints only the unique elements. Your program should use unqiue_copy (Section 10.4.1, p. 403).

**Answer:**

- [`10-31.cpp`](10-31.cpp)

### Exercise 10.32

> Rewrite the bookstore problem from Section 1.6 (p. 24) using a vector to hold the transactions and various algorithms to do the processing. Use sort with your compareIsbn function from Section 10.3.1 (p. 387) to arrange the transactions in order, and then use find and accumulate to do the sum.

**Answer:**

- [`10-32.cpp`](10-32.cpp)

### Exercise 10.33

> Write a program that takes the names of an input file and two output files. The input file should hold integers. Using an istream_iterator read the input file. Using ostream_iterators, write the odd numbers into the first output file. Each value should be followed by a space. Write the even numbers into the second file. Each of these values should be placed on a separate line.

**Answer:**

- [`10-33.cpp`](10-33.cpp)

### Exercise 10.34

> Use reverse_iterators to print a vector in reverse order.

**Answer:**

### Exercise 10.35

> Now print the elements in reverse order using ordinary iterators.

**Answer:**

### Exercise 10.36

> Use find to find the last element in a list of ints with value 0.

**Answer:**

### Exercise 10.37

> Given a vector that has ten elements, copy the elements from positions 3 through 7 in reverse order to a list.

**Answer:**

## Section 10.5 Structure of Generic Algorithms

### Exercise 10.38

> List the five iterator categories and the operations that each supports.

**Answer:**

### Exercise 10.39

> What kind of iterator does a list have? What about a vector?

**Answer:**

### Exercise 10.40

> What kinds of iterators do you think copy requires? What about reverse or unique?

**Answer:**

### Exercise 10.41

> Based only on the algorithm and argument names, describe the operation that the each of the following library algorithms performs:
>
> ```c++
> replace(beg, end, old_val, new_val);
> replace_if(beg, end, pred, new_val);
> replace_copy(beg, end, dest, old_val, new_val);
> replace_copy_if(beg, end, dest, pred, new_val);
> ```

**Answer:**

## Section 10.6 Container-Specific Algorithms

### Exercise 10.42

> Reimplement the program that eliminated duplicate words that we wrote in Section 10.2.3 (p. 383) to use a list instead of a vector.

**Answer:**

- [`10-42.cpp`](10-42.cpp)

