# Inheritance in C++ — Cheat Sheet

## 1. What is Inheritance?

**Inheritance** allows a derived class to acquire properties and behavior of an existing base class.

```cpp
class Derived : public Base
{
};
```

- `Base` → Parent/Base class
- `Derived` → Child/Derived class
- Used for **code reuse** and **IS-A relationships**

Example:

```text
Human
  |
Student
```

`Student IS-A Human`.

---

## 2. Access Modifiers

| Modifier    | Same Class | Derived Class | Outside |
| ----------- | ---------- | ------------- | ------- |
| `public`    | ✅         | ✅            | ✅      |
| `protected` | ✅         | ✅            | ❌      |
| `private`   | ✅         | ❌            | ❌      |

---

## 3. Inheritance Access Modes

```cpp
class Student : public Human
class Student : protected Human
class Student : private Human
```

### Most Important Table

| Base Member | `public` Inheritance | `protected` Inheritance | `private` Inheritance |
| ----------- | -------------------- | ----------------------- | --------------------- |
| `public`    | `public`             | `protected`             | `private`             |
| `protected` | `protected`          | `protected`             | `private`             |
| `private`   | ❌                   | ❌                      | ❌                    |

> **Private members of the base class cannot be directly accessed by the derived class.**

### Easy Memory Trick

```text
public    → public / protected / private
            depending on inheritance mode

protected → protected / protected / private

private   → ❌ always directly inaccessible
```

---

# 4. Types of Inheritance

### 1. Single

One base → one derived.

```text
A
|
B
```

```cpp
class B : public A {};
```

---

### 2. Multilevel

Chain of inheritance.

```text
A
|
B
|
C
```

```cpp
class B : public A {};
class C : public B {};
```

---

### 3. Multiple

One class inherits multiple base classes.

```text
A     B
 \   /
   C
```

```cpp
class C : public A, public B {};
```

---

### 4. Hierarchical

Multiple classes inherit from one base.

```text
    A
   / \
  B   C
```

```cpp
class B : public A {};
class C : public A {};
```

---

### 5. Hybrid

Combination of two or more types of inheritance.

```text
    A
   / \
  B   C
   \ /
    D
```

Usually involves **Multiple + Hierarchical inheritance**.

---

## 5. Diamond Problem

Can occur in Hybrid/Multiple inheritance:

```text
      A
     / \
    B   C
     \ /
      D
```

`D` may get two copies of `A`.

Use **virtual inheritance** to solve it:

```cpp
class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {};
```

---

## 6. Key Points

- **Inheritance = reuse + extension of an existing class**
- `public` inheritance is commonly used for **IS-A relationships**
- `protected` members are accessible in derived classes
- `private` base members cannot be directly accessed by derived classes
- `public`, `protected`, and `private` can be used as inheritance modes
- Five types:
  - **Single**
  - **Multilevel**
  - **Multiple**
  - **Hierarchical**
  - **Hybrid**

- **Virtual inheritance** solves the Diamond Problem
