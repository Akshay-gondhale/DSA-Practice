# Segmented Sieve — Complete Guide (With Full Dry Run)

---

## 📌 Why Segmented Sieve?

Normal sieve:

- Time: O(n log log n)
- Space: O(n) ❌ (too large for big n)

Segmented sieve:

- Time: O(n log log n)
- Space: O(√n) ✅

---

## 🧠 Core Idea

1. Compute primes up to √n
2. Use those primes to mark composites in small chunks `[L, R]`

---

## 🔑 Key Mathematical Truth

> If a number N is composite, it has at least one factor ≤ √N

And since:

```
N ≤ R
⇒ √N ≤ √R
```

👉 So we only need primes up to √R

---

# 🚀 FULL DRY RUN (Step by Step)

Let’s find all primes up to:

```
n = 50
```

---

## ✅ Step 1: Compute primes up to √n

```
√50 ≈ 7
```

Primes:

```
2, 3, 5, 7
```

---

## ✅ Step 2: Choose segment size

Let’s take:

```
segment size = 10
```

So segments:

```
[1–10], [11–20], [21–30], [31–40], [41–50]
```

---

# 🔍 Segment 1: [1–10]

Initial:

```
1  2  3  4  5  6  7  8  9  10
T  T  T  T  T  T  T  T  T  T
```

Mark:

- Using 2 → 4,6,8,10
- Using 3 → 6,9
- Using 5 → 10

Final:

```
2, 3, 5, 7
```

---

# 🔍 Segment 2: [11–20]

Initial:

```
11 12 13 14 15 16 17 18 19 20
 T  T  T  T  T  T  T  T  T  T
```

### Using p = 2

Start = 12  
→ 12,14,16,18,20

### Using p = 3

Start = 12  
→ 12,15,18

### Using p = 5

Start = 15  
→ 15,20

### Using p = 7

Start = 14  
→ 14

Final primes:

```
11, 13, 17, 19
```

---

# 🔍 Segment 3: [21–30]

Initial:

```
21 22 23 24 25 26 27 28 29 30
 T  T  T  T  T  T  T  T  T  T
```

### Using p = 2

Start = 22  
→ 22,24,26,28,30

### Using p = 3

Start = 21  
→ 21,24,27,30

### Using p = 5

Start = 25  
→ 25,30

### Using p = 7

Start = 49 ❌ (outside segment)

Final primes:

```
23, 29
```

---

# 🔍 Segment 4: [31–40]

Initial:

```
31 32 33 34 35 36 37 38 39 40
 T  T  T  T  T  T  T  T  T  T
```

### Using p = 2

→ 32,34,36,38,40

### Using p = 3

→ 33,36,39

### Using p = 5

→ 35,40

### Using p = 7

→ 35

Final primes:

```
31, 37
```

---

# 🔍 Segment 5: [41–50]

Initial:

```
41 42 43 44 45 46 47 48 49 50
 T  T  T  T  T  T  T  T  T  T
```

### Using p = 2

→ 42,44,46,48,50

### Using p = 3

→ 42,45,48

### Using p = 5

→ 45,50

### Using p = 7

→ 42,49

Final primes:

```
41, 43, 47
```

---

# 🎯 Final Answer

All primes up to 50:

```
2, 3, 5, 7,
11, 13, 17, 19,
23, 29,
31, 37,
41, 43, 47
```

---

# 💥 Where your earlier doubt is resolved

Take:

```
49 = 7 × 7 → caught by 7
39 = 3 × 13 → caught by 3
46 = 2 × 23 → caught by 2
```

👉 Even if one factor is large, the other is always ≤ √N

---

# ⚙️ Important Formula

```
start = max(p*p, ceil(L/p) * p)
```

---

# 🧠 Key Takeaways

- You only need primes up to √n
- Segment size is flexible
- Each segment is processed independently
- Memory stays small

---

# 🚫 Common Mistakes

- Forgetting to handle `p*p`
- Wrong start calculation
- Not mapping index as `i - L`
- Treating 1 as prime ❌

---

# 🎯 Final One-Liner

> Segmented sieve works because every composite number has a small factor (≤ √N), and we precompute all such factors.

---
