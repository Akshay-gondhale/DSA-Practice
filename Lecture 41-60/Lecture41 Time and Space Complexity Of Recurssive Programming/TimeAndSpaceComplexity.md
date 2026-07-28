# Time & Space Complexity Analysis of Recursive Algorithms (C++)

> This document explains **how to derive Time Complexity (TC)** and **Space Complexity (SC)** directly from recursive pseudocode.  
> Instead of memorizing formulas, learn how to derive them.

---

# General Steps to Calculate Time Complexity

Whenever you see a recursive function, answer these questions:

### Step 1: How many recursive calls are made?

Look for recursive function calls.

Example:

```cpp
func(n)
{
    func(n-1);
}
```

Only **1 recursive call**.

---

Example:

```cpp
func(n)
{
    func(n-1);
    func(n-1);
}
```

**2 recursive calls**.

---

Example:

```cpp
func(n)
{
    func(n/2);
}
```

Still **1 recursive call**.

---

### Step 2: What is the work done outside recursion?

Everything except recursive calls.

Example:

```cpp
cout << n;
sum++;
swap(a,b);
for(...)
```

All these contribute to **non-recursive work**.

Represent it as:

```
O(1)
```

or

```
O(n)
```

depending on the operations.

---

### Step 3: Write the Recurrence Relation

General form:

```
T(n) =
work outside recursion
+
recursive calls
```

Examples:

```
T(n) = T(n-1) + O(1)
```

```
T(n) = 2T(n-1) + O(1)
```

```
T(n) = 2T(n/2) + O(n)
```

---

### Step 4: Solve the Recurrence

Use one of these methods:

- Expansion
- Recursion Tree
- Master Theorem

---

### Step 5: Calculate Space Complexity

Space consists of:

```
Recursive Call Stack
+
Extra Data Structures
```

Recursive stack:

```
Depth × Memory per call
```

Usually each call stores:

- parameters
- local variables
- return address

Which is constant memory.

Therefore

```
Space = recursion depth
```

unless additional arrays/vectors are created.

---

---

# Problem 1 : Factorial

## Recursive Code

```cpp
int factorial(int n)
{
    if(n==0)
        return 1;

    return n * factorial(n-1);
}
```

---

## Step 1

How many recursive calls?

```
factorial(n-1)
```

Only one.

---

## Step 2

Outside work

```
n *
```

One multiplication.

```
O(1)
```

---

## Step 3

Recurrence

```
T(n)=T(n-1)+O(1)
```

---

## Step 4

Expand

```
T(n)

= T(n-1)+1

= T(n-2)+1+1

= T(n-3)+1+1+1

...

= T(0)+n

= 1+n
```

Therefore

```
T(n)=O(n)
```

---

## Recursion Tree

```
factorial(5)
      |
factorial(4)
      |
factorial(3)
      |
factorial(2)
      |
factorial(1)
      |
factorial(0)
```

Only one branch.

Depth = n

---

## Space Complexity

Call stack

```
factorial(5)
factorial(4)
factorial(3)
factorial(2)
factorial(1)
factorial(0)
```

Maximum calls simultaneously

```
6
```

Approximately

```
n
```

Therefore

```
Space = O(n)
```

---

# Final Complexity

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n)  |
| Space      | O(n)  |

---

# Problem 2 : Fibonacci

## Recursive Code

```cpp
int fib(int n)
{
    if(n<=1)
        return n;

    return fib(n-1)+fib(n-2);
}
```

---

## Step 1

Recursive calls

```
fib(n-1)

fib(n-2)
```

Two recursive calls.

---

## Step 2

Outside work

```
+
```

One addition.

```
O(1)
```

---

## Step 3

Recurrence

Exact recurrence

```
T(n)=T(n-1)+T(n-2)+1
```

For complexity analysis

```
≈2T(n-1)+1
```

---

## Step 4

Expansion intuition

Each function creates roughly two more.

```
                    n

              /           \

          n-1             n-2

        /    \          /     \

     n-2    n-3      n-3     n-4

...
```

Nodes approximately

```
1

2

4

8

16

...
```

Geometric progression

```
1+2+4+8+...
```

Number of levels

```
n
```

Total nodes

```
≈2^n
```

Therefore

```
Time = O(2^n)
```

The exact bound is closer to **O(φⁿ)** (where φ ≈ 1.618), but **O(2ⁿ)** is the commonly accepted upper bound in interviews and introductory analysis.

---

## Space Complexity

Only one branch executes at a time.

Longest branch

```
fib(5)

↓

fib(4)

↓

fib(3)

↓

fib(2)

↓

fib(1)
```

Depth

```
n
```

Therefore

```
Space = O(n)
```

---

# Final Complexity

| Complexity | Value                 |
| ---------- | --------------------- |
| Time       | O(2ⁿ) (exactly O(φⁿ)) |
| Space      | O(n)                  |

---

# Problem 3 : Binary Search (Recursive)

## Recursive Code

```cpp
int binarySearch(int arr[], int s, int e, int key)
{
    if(s>e)
        return -1;

    int mid=(s+e)/2;

    if(arr[mid]==key)
        return mid;

    if(key<arr[mid])
        return binarySearch(arr,s,mid-1,key);

    return binarySearch(arr,mid+1,e,key);
}
```

---

## Step 1

Recursive calls

Only ONE branch executes.

```
binarySearch(left)

or

binarySearch(right)
```

---

## Step 2

Outside work

Calculate

```
mid

comparison

if statements
```

Constant work.

```
O(1)
```

---

## Step 3

Problem size

Each recursion

```
n

↓

n/2

↓

n/4

↓

n/8
```

Recurrence

```
T(n)=T(n/2)+1
```

---

## Step 4

Expansion

```
T(n)

=T(n/2)+1

=T(n/4)+2

=T(n/8)+3

...
```

Stop when

```
n/2^k=1
```

Solve

```
2^k=n

k=log₂n
```

Therefore

```
T(n)=O(log n)
```

---

## Recursion Tree

```
n

|

n/2

|

n/4

|

n/8

|

1
```

Height

```
log₂n
```

---

## Space Complexity

Maximum recursive depth

```
log₂n
```

Therefore

```
O(log n)
```

---

# Final Complexity

| Complexity | Value    |
| ---------- | -------- |
| Time       | O(log n) |
| Space      | O(log n) |

---

# Problem 4 : Merge Sort

## Recursive Code

```cpp
void mergeSort(arr,l,r)
{
    if(l>=r)
        return;

    int mid=(l+r)/2;

    mergeSort(left);

    mergeSort(right);

    merge(left,right);
}
```

---

## Step 1

Recursive calls

```
Left

Right
```

Two recursive calls.

---

## Step 2

Outside work

Merge

Needs to visit every element.

```
O(n)
```

---

## Step 3

Recurrence

```
T(n)=2T(n/2)+n
```

---

## Step 4

Recursion Tree

Level 0

```
n
```

---

Level 1

```
n/2 + n/2

=n
```

---

Level 2

```
n/4+n/4+n/4+n/4

=n
```

---

Every level

```
Total work = n
```

---

Height

Each level halves the problem size.

```
n

↓

n/2

↓

n/4

↓

...

↓

1
```

Height

```
log₂n
```

---

Total

```
n+n+n+n...

log n times
```

Therefore

```
Time

=n×logn

O(nlogn)
```

---

## Space Complexity

### Recursive Stack

Depth

```
log n
```

---

### Merge Array

Temporary arrays

```
Left

Right
```

Combined

```
n
```

Extra memory

```
O(n)
```

---

Overall

```
O(logn)+O(n)

=

O(n)
```

The auxiliary array dominates the recursion stack.

---

# Final Complexity

| Complexity | Value      |
| ---------- | ---------- |
| Time       | O(n log n) |
| Space      | O(n)       |

---

# Quick Summary

| Problem       | Recurrence           | Time                  | Space    |
| ------------- | -------------------- | --------------------- | -------- |
| Factorial     | T(n)=T(n−1)+1        | O(n)                  | O(n)     |
| Fibonacci     | T(n)=T(n−1)+T(n−2)+1 | O(2ⁿ) _(exact O(φⁿ))_ | O(n)     |
| Binary Search | T(n)=T(n/2)+1        | O(log n)              | O(log n) |
| Merge Sort    | T(n)=2T(n/2)+n       | O(n log n)            | O(n)     |

---

# Pattern Recognition Cheat Sheet

| Code Pattern                                        | Recurrence        | Time Complexity |
| --------------------------------------------------- | ----------------- | --------------- |
| One recursive call reducing by 1                    | T(n)=T(n−1)+O(1)  | O(n)            |
| One recursive call reducing by half                 | T(n)=T(n/2)+O(1)  | O(log n)        |
| Two recursive calls reducing by half + linear merge | T(n)=2T(n/2)+O(n) | O(n log n)      |
| Two recursive calls reducing by 1                   | T(n)=2T(n−1)+O(1) | O(2ⁿ)           |
| Three recursive calls reducing by 1                 | T(n)=3T(n−1)+O(1) | O(3ⁿ)           |
| `k` recursive calls reducing by 1                   | T(n)=kT(n−1)+O(1) | O(kⁿ)           |
