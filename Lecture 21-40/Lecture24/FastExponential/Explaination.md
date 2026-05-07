# Modular Exponentiation (Binary Exponentiation)

## Problem

Compute:

(x^n) % m

efficiently.

---

## Full Code

```cpp
int modularExponentiation(int x, int n, int m)
{
    int res = 1;

    while (n > 0)
    {
        // If n is odd
        if (n & 1)
        {
            res = (1LL `*` res `*` x % m) % m;
        }

        // Square x
        x = (1LL `*` x % m `*` x % m) % m;

        // Divide n by 2
        n = n >> 1;
    }

    return res;
}
```

---

## Key Idea

We use:

- If n is even:
  (x^n) = (x^(n/2))^(2)

- If n is odd:
  (x^n) = x `*` (x^(n/2))^(2)

---

## Why Modulo Works

### Important Property

(a `*` b) % m = ((a % m) `*` (b % m)) % m

This allows us to take modulo at every step safely.

---

## Why We Use Modulo at Every Step

Without modulo:

```cpp
x = x `*` x;
```

This may overflow.

With modulo:

```cpp
x = (x `*` x) % m;
```

Value always stays within [0, m-1].

---

## Step-by-Step Dry Run

### Input

```
x = 3
n = 13
m = 7
```

We compute:

```
3^13 % 7
```

---

### Initial State

```
res = 1
x = 3
n = 13
```

---

### Iteration 1

```
n = 13 (odd)

res = (1 `*` 3) % 7 = 3
x = (3 `*` 3) % 7 = 2
n = 6
```

---

### Iteration 2

```
n = 6 (even)

res = 3
x = (2 `*` 2) % 7 = 4
n = 3
```

---

### Iteration 3

```
n = 3 (odd)

res = (3 `*` 4) % 7 = 5
x = (4 `*` 4) % 7 = 2
n = 1
```

---

### Iteration 4

```
n = 1 (odd)

res = (5 `*` 2) % 7 = 3
x = (2 `*` 2) % 7 = 4
n = 0
```

---

### Final Answer

```
res = 3
```

So:

```
3^13 % 7 = 3
```

---

## How Modulo Keeps Values Small

Example:

```
res = 1000
x = 2000
m = 7
```

Normal:

```
1000 `*` 2000 = 2000000
2000000 % 7 = 2
```

Using modulo property:

```
1000 % 7 = 6
2000 % 7 = 5

(6 `*` 5) % 7 = 30 % 7 = 2
```

Same result, smaller numbers.

---

## Important Notes

- Always apply `% m` after multiplication
- Use `1LL` to prevent overflow
- `n & 1` checks if n is odd
- `n >> 1` divides n by 2

---

## Time Complexity

```
O(log n)
```

---

## Space Complexity

```
O(1)
```

---

## Final Intuition

We are not computing:

```
x `*` x `*` x `*` x ...
```

Instead, we use powers:

```
x → x^2 → x^4 → x^8 ...
```

And pick only required ones based on binary of n.

Example:

```
13 = 1101 (binary)

So:
3^13 = 3^8 `*` 3^4 `*` 3^1
```

---

## Conclusion

Modulo arithmetic ensures:

- No overflow
- Correct results
- Efficient computation

Binary exponentiation reduces complexity from O(n) to O(log n)
