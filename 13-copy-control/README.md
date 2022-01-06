# Chapter 13 Copy Control

- [Section 13.1 Copy, Assign, and Destroy](#section-131-copy-assign-and-destroy)
  - *Exercises* [`13.1`](#exercise-131) [`13.2`](#exercise-132) [`13.3`](#exercise-133) [`13.4`](#exercise-134) [`13.5`](#exercise-135)
  - *Exercises* [`13.6`](#exercise-136) [`13.7`](#exercise-137) [`13.8`](#exercise-138)
  - *Exercises* [`13.9`](#exercise-139) [`13.10`](#exercise-1310) [`13.11`](#exercise-1311) [`13.12`](#exercise-1312) [`13.13`](#exercise-1313)
  - *Exercises* [`13.14`](#exercise-1314) [`13.15`](#exercise-1315) [`13.16`](#exercise-1316) [`13.17`](#exercise-1317)
  - *Exercises* [`13.18`](#exercise-1318) [`13.19`](#exercise-1319) [`13.20`](#exercise-1320) [`13.21`](#exercise-1321)

- [Section 13.2 Copy Control and Resource Management](#section-132-copy-control-and-resource-management)
  - *Exercises* [`13.22`](#exercise-1322)
  - *Exercises* [`13.23`](#exercise-1323) [`13.24`](#exercise-1324) [`13.25`](#exercise-1325) [`13.26`](#exercise-1326)
  - *Exercises* [`13.27`](#exercise-1327) [`13.28`](#exercise-1328)

- [Section 13.3 Swap](#section-133-swap)
  - *Exercises* [`13.29`](#exercise-1329) [`13.30`](#exercise-1330) [`13.31`](#exercise-1331) [`13.32`](#exercise-1332)

- [Section 13.4 A Copy-Control Example](#section-134-a-copycontrol-example)
  - *Exercises* [`13.33`](#exercise-1333) [`13.34`](#exercise-1334) [`13.35`](#exercise-1335) [`13.36`](#exercise-1336) [`13.37`](#exercise-1337) [`13.38`](#exercise-1338)

- [Section 13.5 Classes That Manage Dynamic Memory](#section-135-classes-that-manage-dynamic-memory)
  - *Exercises* [`13.39`](#exercise-1339) [`13.40`](#exercise-1340) [`13.41`](#exercise-1341) [`13.42`](#exercise-1342) [`13.43`](#exercise-1343) [`13.44`](#exercise-1344)

- [Section 13.6 Moving Objects](#section-136-moving-objects)
  - *Exercises* [`13.45`](#exercise-1345) [`13.46`](#exercise-1346) [`13.47`](#exercise-1347) [`13.48`](#exercise-1348)
  - *Exercises* [`13.49`](#exercise-1349) [`13.50`](#exercise-1350) [`13.51`](#exercise-1351) [`13.52`](#exercise-1352) [`13.53`](#exercise-1353) [`13.54`](#exercise-1354)
  - *Exercises* [`13.55`](#exercise-1355) [`13.56`](#exercise-1356) [`13.57`](#exercise-1357) [`13.58`](#exercise-1358)

## Section 13.1 Copy, Assign, and Destroy

### Exercise 13.1

> What is a copy constructor? When is it used?

**Answer:**

### Exercise 13.2

> Explain why the following declaration is illegal:
>
> ```c++
> Sales_data::Sales_data(Sales_data rhs);
> ```

**Answer:**

### Exercise 13.3

> What happens when we copy a StrBlob? What about StrBlobPtrs?

**Answer:**

### Exercise 13.4

> Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:
>
> ```c++
> Point global;
> Point foo_bar(Point arg) {
>   Point local = arg, *heap = new Point(global);
>   *heap = local;
>   Point pa[4] = {local, *heap};
>   return *heap;
> }
> ```

**Answer:**

### Exercise 13.5

> Given the following sketch of a class, write a copy constructor that copies all the members. Your constructor should dynamically allocate a new string (Section 12.1.2, p. 458) and copy the object to which ps points, rather than copying ps itself.
>
> ```c++
> class HasPtr {
> public:
>   HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
>
> private:
>   std::string *ps;
>   int i;
> };
> ```

**Answer:**

### Exercise 13.6

> What is a copy-assignment operator? When is this operator used? What does the synthesized copy-assignment operator do? When is it synthesized?

**Answer:**

### Exercise 13.7

> What happens when we assign one StrBlob to another? What about StrBlobPtrs?

**Answer:**

### Exercise 13.8

> Write the assignment operator for the HasPtr class from exercise 13.5 in Section 13.1.1 (p. 499). As with the copy constructor, your assignment operator should copy the object to which ps points.

**Answer:**

- [`13-08.cpp`](13-08.cpp)

### Exercise 13.9

> What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?

**Answer:**

### Exercise 13.10

> What happens when a StrBlob object is destroyed? What about a StrBlobPtr?

**Answer:**

### Exercise 13.11

> Add a destructor to your HasPtr class from the previous exercises.

**Answer:**

### Exercise 13.12

> How many destructor calls occur in the following code fragment?
>
> ```c++
> bool fcn(const Sales_data *trans, Sales_data accum) {
>   Sales_data item1(*trans), item2(accum);
>   return item1.isbn() != item2.isbn();
> }
> ```

**Answer:**

### Exercise 13.13

> A good way to understand copy-control members and constructors is to define a simple class with these members in which each member prints its name:
>
> ```c++
> struct X {
>   X() { std::cout << "X()" << std::endl; }
>   X(const X &) { std::cout << "X(const X&)" << std::endl; }
> };
> ```
>
> Add the copy-assignment operator and destructor to X and write a program using X objects in various ways: Pass them as nonreference and reference parameters; dynamically allocate them; put them in containers; and so forth. Study the output until you are certain you understand when and why each copy-control member is used. As you read the output, remember that the compiler can omit calls to the copy constructor.

**Answer:**

### Exercise 13.14

> Assume that numbered is a class with a default constructor that generates a unique serial number for each object, which is stored in a data member named mysn. Assuming numbered uses the synthesized copy-control members and given the following function:
>
> ```c++
> void f(numbered s) { cout << s.mysn << endl; }
> ```
>
> what output does the following code produce?
>
> ```c++
> numbered a, b = a, c = b;
> f(a);
> f(b);
> f(c);
> ```

**Answer:**

### Exercise 13.15

> Assume numbered has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?

**Answer:**

### Exercise 13.16

> What if the parameter in f were const numbered&? Does that change the output? If so, why? What output gets generated?

**Answer:**

### Exercise 13.17

> Write versions of numbered and f corresponding to the previous three exercises and check whether you correctly predicted the output.

**Answer:**

- [`13-17.cpp`](13-17.cpp)

### Exercise 13.18

> Define an Employee class that contains an employee name and a unique employee identifier. Give the class a default constructor and a constructor that takes a string representing the employee's name. Each constructor should generate a unique ID by incrementing a static data member.

**Answer:**

- [`13-18.cpp`](13-18.cpp)

### Exercise 13.19

> Does your Employee class need to define its own versions of the copy-control members? If so, why? If not, why not? Implement whatever copy-control members you think Employee needs.

**Answer:**

- [`13-19.cpp`](13-19.cpp)

### Exercise 13.20

> Explain what happens when we copy, assign, or destroy objects of our TextQuery and QueryResult classes from Section 12.3 (p. 484).

**Answer:**

### Exercise 13.21

> Do you think the TextQuery and QueryResult classes need to define their own versions of the copy-control members? If so, why? If not, why not? Implement whichever copy-control operations you think these classes require.

**Answer:**

- [`13-21.cpp`](13-21.cpp)

## Section 13.2 Copy Control and Resource Management

### Exercise 13.22

> Assume that we want HasPtr to behave like a value. That is, each object should have its own copy of the string to which the objects point. We'll show the definitions of the copy-control members in the next section. However, you already know everything you need to know to implement these members. Write the HasPtr copy constructor and copy-assignment operator before reading on.

**Answer:**

- [`13-22.cpp`](13-22.cpp)

### Exercise 13.23

> Compare the copy-control members that you wrote for the solutions to the previous section's exercises to the code presented here. Be sure you understand the differences, if any, between your code and ours.

**Answer:**

### Exercise 13.24

> What would happen if the version of HasPtr in this section didn't define a destructor? What if HasPtr didn't define the copy constructor?

**Answer:**

### Exercise 13.25

> Assume we want to define a version of StrBlob that acts like a value. Also assume that we want to continue to use a shared_ptr so that our StrBlobPtr class can still use a weak_ptr to the vector. Your revised class will need a copy constructor and copy-assignment operator but will not need a destructor. Explain what the copy constructor and copy-assignment operators must do. Explain why the class does not need a destructor.

**Answer:**

### Exercise 13.26

> Write your own version of the StrBlob class described in the previous exercise.

**Answer:**

- [`13-26.cpp`](13-26.cpp)

### Exercise 13.27

> Define your own reference-counted version of HasPtr.

**Answer:**

- [`13-27.cpp`](13-27.cpp)

### Exercise 13.28

> Given the following classes, implement a default constructor and the necessary copy-control members.
>
> (a)
> ```c++
> class TreeNode {
> private:
>   std::string value;
>   int         count;
>   TreeNode    *left;
>   TreeNode    *right;
> };
> ```
>
> (b)
> ```c++
> class BinStrTree {
> private:
>     TreeNode *root;
> };
> ```

**Answer:**

## Section 13.3 Swap

### Exercise 13.29

> Explain why the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion loop.

**Answer:**

### Exercise 13.30

> Write and test a swap function for your valuelike version of HasPtr. Give your swap a print statement that notes when it is executed.

**Answer:**

- [`13-30.cpp`](13-30.cpp)

### Exercise 13.31

> Give your class a < operator and define a vector of HasPtrs. Give that vector some elements and then sort the vector. Note when swap is called.

**Answer:**

### Exercise 13.32

> Would the pointerlike version of HasPtr benefit from defining a swap function? If so, what is the benefit? If not, why not?

**Answer:**

## Section 13.4 A Copy-Control Example

### Exercise 13.33

> Why is the parameter to the save and remove members of Message a Folder&? Why didn't we define that parameter as Folder? Or const Folder&?

**Answer:**

### Exercise 13.34

> Write the Message class as described in this section.

**Answer:**

- [`13-34.cpp`](13-34.cpp)

### Exercise 13.35

> What would happen if Message used the synthesized versions of the copy-control members?

**Answer:**

### Exercise 13.36

> Design and implement the corresponding Folder class. That class should hold a set that points to the Messages in that Folder.

**Answer:**

### Exercise 13.37

> Add members to the Message class to insert or remove a given Folder* into folders. These members are analogous to Folder's addMsg and remMsg operations.

**Answer:**

### Exercise 13.38

> We did not use copy and swap to define the Message assignment operator. Why do you suppose this is so?

**Answer:**

## Section 13.5 Classes That Manage Dynamic Memory

### Exercise 13.39

> Write your own version of StrVec, including versions of reserve, capacity (Section 9.4, p. 356), and resize (Section 9.3.5, p. 352).

**Answer:**

- [`13-39.cpp`](13-39.cpp)

### Exercise 13.40

> Add a constructor that takes an initializer_list<string> to your StrVec class.

**Answer:**

### Exercise 13.41

> Why did we use postfix increment in the call to construct inside push_back? What would happen if it used the prefix increment?

**Answer:**

### Exercise 13.42

> Test your StrVec class by using it in place of the vector<string> in your TextQuery and QueryResult classes (Section 12.3, p. 484).

**Answer:**

### Exercise 13.43

> Rewrite the free member to use for_each and a lambda (Section 10.3.2, p. 388) in place of the for loop to destroy the elements. Which implementation do you prefer, and why?

**Answer:**

- [`13-43.cpp`](13-43.cpp)

### Exercise 13.44

> Write a class named String that is a simplified version of the library string class. Your class should have at least a default constructor and a constructor that takes a pointer to a C-style string. Use an allocator to allocate memory that your String class uses.

**Answer:**

- [`13-44.cpp`](13-44.cpp)

## Section 13.6 Moving Objects

### Exercise 13.45

> Distinguish between an rvalue reference and an lvalue reference.

**Answer:**

### Exercise 13.46

> Which kind of reference can be bound to the following initializers?
>
> ```c++
> int f();
> vector<int> vi(100);
> int ? r1 = f();
> int ? r2 = vi[0];
> int ? r3 = r1;
> int ? r4 = vi[0] * f();
> ```

**Answer:**

### Exercise 13.47

> Give the copy constructor and copy-assignment operator in your String class from exercise 13.44 in Section 13.5 (p. 531) a statement that prints a message each time the function is executed.

**Answer:**

### Exercise 13.48

> Define a vector<String> and call push_back several times on that vector. Run your program and see how often Strings are copied.

**Answer:**

- [`13-48.cpp`](13-48.cpp)

### Exercise 13.49

> Add a move constructor and move-assignment operator to your StrVec, String, and Message classes.

**Answer:**

### Exercise 13.50

> Put print statements in the move operations in your String class and rerun the program from exercise 13.48 in Section 13.6.1 (p. 534) that used a vector<String> to see when the copies are avoided.

**Answer:**

### Exercise 13.51

> Although unique_ptrs cannot be copied, in Section 12.1.5 (p. 471) we wrote a clone function that returned a unique_ptr by value. Explain why that function is legal and how it works.

**Answer:**

### Exercise 13.52

> Explain in detail what happens in the assignments of the HasPtr objects on *page 541*. In particular, describe step by step what happens to values of hp, hp2, and of the rhs parameter in the HasPtr assignment operator.

**Answer:**

### Exercise 13.53

> As a matter of low-level efficiency, the HasPtr assignment operator is not ideal. Explain why. Implement a copy-assignment and move-assignment operator for HasPtr and compare the operations executed in your new move-assignment operator versus the copy-and-swap version.

**Answer:**

- [`13-53.cpp`](13-53.cpp)

### Exercise 13.54

> What would happen if we defined a HasPtr move-assignment operator but did not change the copy-and-swap operator? Write code to test your answer.

**Answer:**

- [`13-54.cpp`](13-54.cpp)

### Exercise 13.55

> Add an rvalue reference version of push_back to your StrBlob.

**Answer:**

### Exercise 13.56

> What would happen if we defined sorted as:
>
> ```c++
> Foo Foo::sorted() const & {
>   Foo ret(*this);
>   return ret.sorted();
> }
> ```

**Answer:**

### Exercise 13.57

> What if we defined sorted as:
>
> ```c++
> Foo Foo::sorted() const & { return Foo(*this).sorted(); }
> ```

**Answer:**

### Exercise 13.58

> Write versions of class Foo with print statements in their sorted functions to test your answers to the previous two exercises.

**Answer:**

- [`13-58.cpp`](13-58.cpp)

