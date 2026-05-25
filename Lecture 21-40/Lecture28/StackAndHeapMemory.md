# Dynamic Memory in C++ 🚀

When a C++ program runs, memory is mainly divided into two types:

1. **Static (Stack) Memory**
2. **Dynamic (Heap) Memory**

---

# Stack Memory vs Heap Memory ⚔️

| Feature    | Stack Memory     | Heap Memory     |
| ---------- | ---------------- | --------------- |
| Size       | Small            | Large           |
| Speed      | Faster           | Slightly slower |
| Cleanup    | Automatic        | Manual          |
| Allocation | Compile-time     | Runtime         |
| Access     | Direct variables | Pointers        |
| Risk       | Stack overflow   | Memory leak     |

---

# 1. Static / Stack Memory 📦

Static memory (commonly called **stack memory**) is automatically managed by the compiler.

Example:

```cpp
int a = 10;
int arr[100];
```

Here, variables are created inside stack memory.

## Features of Stack Memory

✅ Fast access  
✅ Automatically cleaned up when function ends  
❌ Limited in size  
❌ Large allocations may crash the program

---

## Problem with Variable Size Arrays ⚠️

```cpp
int num;
cin >> num;

int arr[num];
```

This is considered bad practice in C++ because:

- `arr` is created in stack memory.
- Stack memory is limited.
- If user enters a very large number, memory overflow can happen.
- Program may crash due to **stack overflow**.

Example:

```cpp
num = 100000000;
```

This may try to allocate huge memory on stack and crash the program.

---

# 2. Dynamic / Heap Memory 🧠

Dynamic memory is allocated during runtime using the `new` keyword.

Heap memory is much larger compared to stack memory.

Example:

```cpp
int *p = new int;
```

---

## What Happens Here? 🤔

```cpp
int *p = new int;
```

### Step-by-step:

1. `new int`
   - Allocates memory of size `int` inside heap memory.

2. It returns the address of allocated memory.

3. That address gets stored inside pointer `p`.

Visualization:

```text
Heap Memory
+-------+
|   ?   |  ← allocated int memory
+-------+
     ^
     |
     p
```

---

# Dynamic Array Example 📚

```cpp
int n;
cin >> n;

int *arr = new int[n];
```

Here:

- Array size is decided at runtime.
- Memory is allocated in heap.
- Much safer for large sizes compared to stack allocation.

---

# Important Points About Dynamic Memory ⚡

## 1. Dynamic memory is accessed using pointers

You cannot directly access heap memory without pointers.

Correct:

```cpp
int *p = new int;
```

Wrong:

```cpp
new int; // memory allocated but address lost
```

---

## 2. Memory is NOT cleaned automatically ❌

Unlike stack memory, heap memory is not automatically released.

You must manually free it using `delete`.

---

# Memory Leak 🚨

If you forget to free heap memory:

```cpp
int *p = new int;
```

memory remains occupied even after it is no longer needed.

This is called a **memory leak**.

Too many memory leaks can slow down or crash programs.

---

# Releasing Dynamic Memory 🧹

## For Single Variable

```cpp
int *p = new int;

delete p;
```

---

## For Arrays

```cpp
int *arr = new int[100];

delete[] arr;
```

⚠️ Always use:

- `delete` → for single variable
- `delete[]` → for arrays

---

# Full Example ✅

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    // Dynamic array allocation
    int *arr = new int[n];

    // Input
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Output
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Free memory
    delete[] arr;

    return 0;
}
```
