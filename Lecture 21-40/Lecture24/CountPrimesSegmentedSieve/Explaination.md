# Segmented Sieve — Clear Explanation

## 🔹 Goal

Find all prime numbers less than `n` efficiently.

---

## 🔹 Key Idea

Instead of using a large array up to `n`, we:

1. Compute primes up to √n
2. Process remaining numbers in **segments (chunks)**

---

## 🔹 Why √n?

Any composite number `x` must have at least one factor ≤ √x.

So primes up to √n are enough to mark all non-primes.

---

## 🔹 Algorithm Steps

### Step 1: Simple Sieve

Find primes up to √n.

Example:

```
n = 50 → √n ≈ 7
primes = [2, 3, 5, 7]
```

---

### Step 2: Create Segments

We process ranges like:

```
[8–16), [16–24), [24–32), ...
```

Each segment size ≈ √n

---

### Step 3: Mark Composites in Segment

For each prime `p`, find:

## 🔥 First multiple of p in segment

```
loLim = floor(low / p) * p
if (loLim < low)
    loLim += p
```

---

## ❗ Why adding p works?

Multiples of p are spaced like:

```
p, 2p, 3p, 4p, ...
```

If we land on:

```
k*p < low
```

Then next multiple is:

```
(k+1)*p = k*p + p
```

So adding `p` moves to the next valid multiple.

---

### Cleaner Formula

```
loLim = ((low + p - 1) / p) * p
```

---

### Step 4: Mark using mapping

We don’t store actual numbers.

Instead:

```
index = number - low
```

Example:

```
Segment = [50–100]

50 → mark[0]
51 → mark[1]
...
```

---

### Step 5: Remaining TRUE values = primes

---

## 🔹 Example (n = 50)

### Segment [8–16]

Numbers:

```
8 9 10 11 12 13 14 15
```

After marking:

```
11, 13 → primes
```

---

### Segment [16–24]

```
17, 19, 23 → primes
```

---

### Segment [24–32]

```
29, 31 → primes
```

---

## 🔹 Complexity

Time:

```
O(n log log n)
```

Space:

```
O(√n)
```

---

## 🔹 Key Takeaways

- Only compute primes up to √n once
- Process numbers in chunks
- Use mapping: `mark[j - low]`
- `loLim` finds first multiple in segment
- Adding `p` jumps to next multiple

---

## 🔚 Mental Model

Think:

```
Small primes = tools
Segments = blocks to clean

Use tools to clean each block
```

---
