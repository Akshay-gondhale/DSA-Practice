# C++ Runtime Polymorphism — Visual Cheat Sheet

## 1. Function Overriding vs Runtime Polymorphism

|                         | Function Overriding                           | Runtime Polymorphism                       |
| ----------------------- | --------------------------------------------- | ------------------------------------------ |
| Meaning                 | Derived class provides its own implementation | Derived implementation selected at runtime |
| `virtual` required?     | ❌ No                                         | ✅ Yes                                     |
| Base pointer/reference? | ❌ Not required                               | ✅ Required                                |
| Decision                | Compile-time                                  | Runtime                                    |

> **Overriding creates different implementations. `virtual` enables runtime selection of those implementations.**

---

# 2. Function Overriding

```cpp
class Animal
{
public:
    void speak()
    {
        cout << "Speaking";
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Barking";
    }
};
```

`Dog` provides its own implementation of `speak()`.

```text
            Animal
              │
              │  speak()
              │  "Speaking"
              ▼
             Dog
              │
              │  speak()
              │  "Barking"
              ▼
        Function Overriding
```

Direct call:

```cpp
Dog dog;
dog.speak();
```

```text
Dog object
    │
    ▼
Dog::speak()
    │
    ▼
"Barking"
```

This is **function overriding**, but not runtime polymorphism.

---

# 3. Without `virtual`

```cpp
class Animal
{
public:
    void speak()
    {
        cout << "Speaking";
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Barking";
    }
};

Animal *ptr = new Dog();

ptr->speak();
```

### What happens?

```text
       ptr
        │
        │ Animal*
        ▼
┌─────────────────┐
│   Dog Object    │
│─────────────────│
│ Animal part     │
│ Dog part        │
└─────────────────┘
```

Even though the actual object is `Dog`:

```text
Pointer Type = Animal*
Object Type  = Dog
```

Because `speak()` is **not virtual**, C++ uses the pointer type:

```text
Animal*
  │
  ▼
Animal::speak()
  │
  ▼
"Speaking"
```

❌ **No runtime polymorphism**

---

# 4. With `virtual`

Add `virtual` to the base function:

```cpp
class Animal
{
public:
    virtual void speak()
    {
        cout << "Speaking";
    }
};
```

Now:

```cpp
Animal *ptr = new Dog();

ptr->speak();
```

### What happens?

```text
             ptr
              │
              │ Animal*
              ▼
      ┌───────────────┐
      │   Dog Object  │
      └───────────────┘
              │
              │ virtual function
              ▼
        Check actual object
              │
              ▼
        Dog::speak()
              │
              ▼
          "Barking"
```

✅ **Runtime polymorphism**

---

# 5. What Does `virtual` Do?

### Without `virtual`

```text
Animal* ptr
     │
     ▼
Pointer type = Animal
     │
     ▼
Animal::speak()
```

### With `virtual`

```text
Animal* ptr
     │
     ▼
Actual object = Dog
     │
     ▼
Dog::speak()
```

So:

> **`virtual` tells C++ to resolve the overridden function based on the actual object at runtime when accessed through a base pointer/reference.**

---

# 6. `virtual` + `override`

Recommended pattern:

```cpp
class Animal
{
public:
    virtual void speak()
    {
        cout << "Speaking";
    }
};

class Dog : public Animal
{
public:
    void speak() override
    {
        cout << "Barking";
    }
};
```

Think of the keywords like this:

```text
       BASE CLASS
           │
           │ virtual
           ▼
    "This function can
     be dynamically dispatched"
           │
           ▼
    DERIVED CLASS
           │
           │ override
           ▼
    "I am replacing the
     base implementation"
```

### Remember

```text
virtual  → enables runtime dispatch

override → tells compiler "I am overriding"
```

---

# 7. Complete Runtime Polymorphism Flow

```text
┌──────────────────────┐
│      Animal          │
│                      │
│ virtual speak()      │
└──────────┬───────────┘
           │
           │ inheritance
           ▼
┌──────────────────────┐
│        Dog           │
│                      │
│ speak() override     │
└──────────┬───────────┘
           │
           │
           ▼
┌──────────────────────┐
│ Animal* ptr = new    │
│ Dog();               │
└──────────┬───────────┘
           │
           │ ptr->speak()
           ▼
┌──────────────────────┐
│ Runtime checks       │
│ actual object        │
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│     Dog::speak()     │
│       "Barking"      │
└──────────────────────┘
```

---

# 8. Quick Comparison

```text
FUNCTION OVERRIDING
────────────────────

Animal::speak()
      │
      ▼
Dog::speak()

Derived class provides
a different implementation.


RUNTIME POLYMORPHISM
────────────────────

Animal* ───────► Dog object
  │
  │ speak()
  ▼
virtual dispatch
  │
  ▼
Dog::speak()

Actual implementation
selected at runtime.
```

---

# 9. Final Memory Trick

```text
        Function Overriding
                │
                ▼
       Different implementation
                │
                +
             virtual
                │
                +
       Base pointer/reference
                │
                ▼
      Runtime Polymorphism
```

### One Line to Remember

> **Overriding = "What implementation does the child provide?"**

> **Runtime polymorphism = "Which implementation should be called at runtime?"**
