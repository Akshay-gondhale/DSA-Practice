# C++ Structure Padding, Alignment & Dynamic Data Members

One of the most common interview questions in C++ is:

> **Why does a class containing an `int` and a `char` occupy 8 bytes instead of 5 bytes?**

Example:

```cpp
#include <iostream>
using namespace std;

class Human
{
public:
    int age;
    char gender;
};

int main()
{
    cout << sizeof(Human);
}
```

**Output**

```
8
```

At first glance:

```
int  -> 4 bytes
char -> 1 byte
----------------
Total = 5 bytes
```

So why does `sizeof(Human)` print **8**?

The answer lies in **Memory Alignment** and **Padding**.

---

# 1. Memory Alignment

## What is Alignment?

Every data type has a preferred memory boundary where it should start.

| Data Type | Size    | Preferred Starting Address |
| --------- | ------- | -------------------------- |
| char      | 1 byte  | Anywhere                   |
| short     | 2 bytes | Multiple of 2              |
| int       | 4 bytes | Multiple of 4              |
| double    | 8 bytes | Multiple of 8              |

For example, an `int` prefers to start at addresses like:

```
0
4
8
12
16
20
...
```

instead of

```
1
2
3
5
6
7
...
```

---

## Why does the CPU care?

Modern CPUs read memory in fixed-size chunks.

### Properly aligned `int`

```
Address

100 101 102 103
----------------
| A | B | C | D |
----------------
```

The CPU can fetch all 4 bytes in **one memory access**.

---

### Misaligned `int`

```
Address

100 101 102 103
104

| ? | A | B | C |
| D |
```

Now the integer spans two memory blocks.

The CPU may need **two memory accesses** instead of one.

This is slower.

To avoid this, compilers automatically align data.

---

# 2. Padding

Padding is the **extra unused memory inserted by the compiler** to satisfy alignment rules.

Consider:

```cpp
class Human
{
public:
    int age;
    char gender;
};
```

Memory layout:

```
Address

100 101 102 103 104 105 106 107

 age age age age  G   P   P   P
```

```
G = gender
P = Padding
```

Total size:

```
4 + 1 + 3 = 8 bytes
```

Although only 5 bytes store actual data, the compiler adds **3 padding bytes**.

---

# 3. Why Tail Padding?

Suppose the compiler didn't add padding.

```
Object Size = 5 bytes
```

Now create an array.

```cpp
Human arr[2];
```

Memory:

```
Object 1

100 101 102 103 104

 age age age age G

Object 2

105 106 107 108 109

 age age age age G
```

Notice the second object's `age` starts at **105**.

```
105 is NOT divisible by 4
```

So the second object's integer becomes misaligned.

---

Instead, the compiler makes the object **8 bytes**.

```
Object 1

100 101 102 103 104 105 106 107

 age age age age G P P P

Object 2

108 109 110 111 112 113 114 115

 age age age age G P P P
```

Now every object's `int` begins at a multiple of 4.

This extra padding added at the end of a class is called **Tail Padding**.

---

# 4. Internal Padding

Padding can also be inserted **between members**.

Example:

```cpp
class Example
{
public:
    char grade;
    int marks;
};
```

Memory layout:

```
grade P P P marks marks marks marks
```

Explanation:

```
char occupies 1 byte.

The next member is int.

int requires an address divisible by 4.

Compiler inserts 3 padding bytes.
```

Total size:

```
1 + 3 + 4 = 8 bytes
```

---

# 5. Greedy Alignment

A class follows the alignment requirement of the member that needs the **largest alignment**.

Example:

```cpp
class Example
{
public:
    char a;
    double b;
    int c;
};
```

Alignment requirements:

```
char    -> 1 byte
int     -> 4 bytes
double  -> 8 bytes
```

The largest requirement is:

```
double -> 8-byte alignment
```

So the entire object size must also be a multiple of **8**.

This behavior is commonly referred to as **Greedy Alignment**.

---

# 6. Dynamic Data Members (`vector` & `string`)

Many beginners think a `vector` stores all of its elements inside the object.

That is **not true**.

The object only stores **metadata**.

The actual elements are stored on the **heap**.

---

## Example: `vector`

```cpp
class Student
{
public:
    vector<int> marks;
};
```

Conceptually, a vector object contains:

```
+----------------------+
| Pointer              |
| Size                 |
| Capacity             |
+----------------------+
```

These members point to dynamically allocated memory.

```
Student Object

+----------------------+
| pointer ------------+|
| size = 5            ||
| capacity = 8        ||
+----------------------+|
                        |
                        |
                        v

Heap

+---------------------------+
|10|20|30|40|50|...         |
+---------------------------+
```

The object stays the same size.

Only the heap memory grows.

---

### Example

```cpp
vector<int> v;

cout << sizeof(v);
```

Typical output on a 64-bit system:

```
24
```

Now insert elements:

```cpp
v.push_back(10);
v.push_back(20);
v.push_back(30);
v.push_back(40);
```

The output is still:

```
24
```

Why?

Because `sizeof()` measures only the **vector object**, not the heap memory.

---

# 7. `std::string`

A `string` works similarly.

```cpp
class Human
{
public:
    string name;
};
```

Conceptually:

```
Human Object

+----------------------+
| string metadata      |
+----------------------+
          |
          |
          v

Heap

A k s h a y
```

Again,

`sizeof(string)` measures only the object itself.

It does **not** depend on how many characters are stored.

---

## Small String Optimization (SSO)

Most modern C++ compilers optimize small strings.

Example:

```cpp
string name = "Akshay";
```

Instead of allocating heap memory, the compiler stores short strings directly inside the string object.

So small strings may not use the heap at all.

For longer strings, heap memory is used automatically.

> **Note:** SSO is an optimization and its implementation varies between standard library implementations.

---

# 8. Padding with Dynamic Members

Padding rules still apply because `vector` and `string` are normal class members.

Example:

```cpp
class Example
{
public:
    char grade;
    vector<int> marks;
};
```

Memory layout:

```
grade P P P P P P P vector object
```

The compiler aligns the **vector object**, not the heap data.

The actual integers remain on the heap.

---

# 9. Object Memory vs Heap Memory

This is one of the most important concepts.

## Object Memory

Stored where the object is created (stack, global memory, or heap if allocated with `new`).

Contains:

```
age
pointer
size
capacity
...
```

This is what `sizeof()` measures.

---

## Heap Memory

Allocated dynamically.

Contains:

```
10
20
30
40
50
```

or

```
A
k
s
h
a
y
```

Heap memory is **not counted** by `sizeof()`.

---

# Interview Questions

### Q1. Why is `sizeof(Human)` 8 instead of 5?

Because the compiler inserts padding to satisfy alignment requirements.

---

### Q2. Why doesn't `sizeof(vector<int>)` change after inserting 1000 elements?

Because `sizeof()` measures only the vector object (pointer, size, capacity).

The elements are stored separately on the heap.

---

### Q3. Does `sizeof(string)` return the number of characters?

No.

It returns the size of the string object itself, not the length of the stored text.

---

### Q4. Does padding apply to `vector` and `string`?

Yes.

The **object** is aligned like any other class member.

The dynamically allocated heap memory is separate.

---

# Summary

| Concept          | Meaning                                                                                                              |
| ---------------- | -------------------------------------------------------------------------------------------------------------------- |
| Alignment        | Storing data at preferred memory boundaries for faster CPU access                                                    |
| Padding          | Extra bytes inserted by the compiler to satisfy alignment                                                            |
| Internal Padding | Padding inserted between members                                                                                     |
| Tail Padding     | Padding added at the end so arrays remain properly aligned                                                           |
| Greedy Alignment | The class follows the largest alignment requirement among its members                                                |
| `vector`         | Object stores pointer, size and capacity; elements are stored on the heap                                            |
| `string`         | Object stores metadata; characters are usually stored on the heap (or inside the object for small strings using SSO) |
| `sizeof()`       | Measures only the object size, **not** dynamically allocated heap memory                                             |

---

# Key Takeaways

- `sizeof(class)` is **not** always the sum of its member sizes.
- Alignment helps the CPU access memory efficiently.
- The compiler automatically inserts padding when needed.
- Tail padding ensures arrays of objects remain correctly aligned.
- The largest aligned member determines the alignment requirement of the whole class.
- `vector` and `string` store metadata inside the object, while their data is usually stored separately on the heap.
- `sizeof(vector)` and `sizeof(string)` remain constant regardless of how many elements or characters they contain.
