# Chapter 11 Associative Containers

- [Section 11.1 Using an Associative Container](#section-111-using-an-associative-container)
  - *Exercises* [`11.1`](#exercise-111) [`11.2`](#exercise-112) [`11.3`](#exercise-113) [`11.4`](#exercise-114)

- [Section 11.2 Overview of the Associative Containers](#section-112-overview-of-the-associative-containers)
  - *Exercises* [`11.5`](#exercise-115) [`11.6`](#exercise-116) [`11.7`](#exercise-117) [`11.8`](#exercise-118)
  - *Exercises* [`11.9`](#exercise-119) [`11.10`](#exercise-1110) [`11.11`](#exercise-1111)
  - *Exercises* [`11.12`](#exercise-1112) [`11.13`](#exercise-1113) [`11.14`](#exercise-1114)

- [Section 11.3 Operations on Associative Containers](#section-113-operations-on-associative-containers)
  - *Exercises* [`11.15`](#exercise-1115) [`11.16`](#exercise-1116) [`11.17`](#exercise-1117) [`11.18`](#exercise-1118) [`11.19`](#exercise-1119)
  - *Exercises* [`11.20`](#exercise-1120) [`11.21`](#exercise-1121) [`11.22`](#exercise-1122) [`11.23`](#exercise-1123)
  - *Exercises* [`11.24`](#exercise-1124) [`11.25`](#exercise-1125) [`11.26`](#exercise-1126)
  - *Exercises* [`11.27`](#exercise-1127) [`11.28`](#exercise-1128) [`11.29`](#exercise-1129) [`11.30`](#exercise-1130) [`11.31`](#exercise-1131) [`11.32`](#exercise-1132)
  - *Exercises* [`11.33`](#exercise-1133) [`11.34`](#exercise-1134) [`11.35`](#exercise-1135) [`11.36`](#exercise-1136)

- [Section 11.4 The Unordered Containers](#section-114-the-unordered-containers)
  - *Exercises* [`11.37`](#exercise-1137) [`11.38`](#exercise-1138)

## Section 11.1 Using an Associative Container

### Exercise 11.1

> Describe the differences between a map and a vector.

**Answer:**

### Exercise 11.2

> Give an example of when each of list, vector, deque, map, and set might be most useful.

**Answer:**

### Exercise 11.3

> Write your own version of the word-counting program.

**Answer:**

- [`11-03.cpp`](11-03.cpp)

### Exercise 11.4

> Extend your program to ignore case and punctuation. For example, "example." "example," and "Example" should all increment the same counter.

**Answer:**

## Section 11.2 Overview of the Associative Containers

### Exercise 11.5

> Explain the difference between a map and a set. When might you use one or the other?

**Answer:**

### Exercise 11.6

> Explain the difference between a set and a list. When might you use one or the other?

**Answer:**

### Exercise 11.7

> Define a map for which the key is the family's last name and the value is a vector of the children's names. Write code to add new families and to add new children to an existing family.

**Answer:**

- [`11-07.cpp`](11-07.cpp)

### Exercise 11.8

> Write a program that stores the excluded words in a vector instead of in a set. What are the advantages to using a set?

**Answer:**

- [`11-08.cpp`](11-08.cpp)

### Exercise 11.9

> Define a map that associates words with a list of line numbers on which the word might occur.

**Answer:**

- [`11-09.cpp`](11-09.cpp)

### Exercise 11.10

> Could we define a map from vector<int>::iterator to `int`?
>
> What about from list<int>::iterator to `int`? In each case, if not, why not?

**Answer:**

### Exercise 11.11

> Redefine bookstore without using `decltype`.

**Answer:**

### Exercise 11.12

> Write a program to read a sequence of strings and ints, storing each into a pair. Store the pairs in a vector.

**Answer:**

- [`11-12.cpp`](11-12.cpp)

### Exercise 11.13

> There are at least three ways to create the pairs in the program for the previous exercise. Write three versions of that program, creating the pairs in each way. Explain which form you think is easiest to write and understand, and why.

**Answer:**

- [`11-13.cpp`](11-13.cpp)

### Exercise 11.14

> Extend the map of children to their family name that you wrote for the exercises in Section 11.2.1 (p. 424) by having the vector store a pair that holds a child's name and birthday.

**Answer:**

## Section 11.3 Operations on Associative Containers

### Exercise 11.15

> What are the mapped_type, key_type, and value_type of a map from `int` to vector<int>?

**Answer:**

### Exercise 11.16

> Using a map iterator write an expression that assigns a value to an element.

**Answer:**

### Exercise 11.17

> Assuming c is a multiset of strings and v is a vector of strings, explain the following calls. Indicate whether each call is legal: copy(v.begin(), copy(v.begin(), copy(c.begin(), copy(c.begin(),

**Answer:**

### Exercise 11.18

> Write the type of map_it from the loop on *page 430* without using `auto` or `decltype`.

**Answer:**

- [`11-18.cpp`](11-18.cpp)

### Exercise 11.19

> Define a variable that you initialize by calling begin() on the multiset named bookstore from Section 11.2.2 (p. 425). Write the variable's type without using `auto` or `decltype`.

**Answer:**

- [`11-19.cpp`](11-19.cpp)

### Exercise 11.20

> Rewrite the word-counting program from Section 11.1 (p. 421) to use insert instead of subscripting. Which program do you think is easier to write and read? Explain your reasoning.

**Answer:**

- [`11-20.cpp`](11-20.cpp)

### Exercise 11.21

> Assuming word_count is a map from string to size_t and word is a string, explain the following loop:
>
> ```c++
> while (cin >> word)
>   ++word_count.insert({word, 0}).first->second;
> ```

**Answer:**

### Exercise 11.22

> Given a map<string, vector<int>>, write the types used as an argument and as the return value for the version of insert that inserts one element.

**Answer:**

### Exercise 11.23

> Rewrite the map that stored vectors of children's names with a key that is the family last name for the exercises in Section 11.2.1 (p. 424) to use a multimap.

**Answer:**

- [`11-23.cpp`](11-23.cpp)

### Exercise 11.24

> What does the following program do?
>
> ```c++
> map<int, int> m;
> m[0] = 1;
> ```

**Answer:**

### Exercise 11.25

> Contrast the following program with the one in the previous exercise vector<int> v;
>
> ```c++
> v[0] = 1;
> ```

**Answer:**

### Exercise 11.26

> What type can be used to subscript a map? What type does the subscript operator return? Give a concrete example -- that is, define a map and then write the types that can be used to subscript the map and the type that would be returned from the subscript operator.

**Answer:**

### Exercise 11.27

> What kinds of problems would you use count to solve? When might you use find instead?

**Answer:**

### Exercise 11.28

> Define and initialize a variable to hold the result of calling find on a map from string to vector of `int`.

**Answer:**

- [`11-28.cpp`](11-28.cpp)

### Exercise 11.29

> What do upper_bound, lower_bound, and equal_range return when you pass them a key that is not in the container?

**Answer:**

### Exercise 11.30

> Explain the meaning of the operand pos.first->second used in the output expression of the final program in this section.

**Answer:**

### Exercise 11.31

> Write a program that defines a multimap of authors and their works. Use find to find an element in the multimap and erase that element. Be sure your program works correctly if the element you look for is not in the map.

**Answer:**

- [`11-31.cpp`](11-31.cpp)

### Exercise 11.32

> Using the multimap from the previous exercise, write a program to print the list of authors and their works alphabetically.

**Answer:**

### Exercise 11.33

> Implement your own version of the word-transformation program.

**Answer:**

- [`11-33.cpp`](11-33.cpp)

### Exercise 11.34

> What would happen if we used the subscript operator instead of find in the transform function?

**Answer:**

### Exercise 11.35

> In buildMap, what effect, if any, would there be from rewriting trans_map[key] = value.substr(1); as trans_map.insert({key, value.substr(1)})?

**Answer:**

### Exercise 11.36

> Our program does no checking on the validity of either input file. In particular, it assumes that the rules in the transformation file are all sensible. What would happen if a line in that file has a key, one space, and then the end of the line? Predict the behavior and then check it against your version of the program.

**Answer:**

## Section 11.4 The Unordered Containers

### Exercise 11.37

> What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?

**Answer:**

### Exercise 11.38

> Rewrite the word-counting (Section 11.1, p. 421) and word-transformation (Section 11.3.6, p. 440) programs to use an unordered_map.

**Answer:**

- [`11-38.cpp`](11-38.cpp)

