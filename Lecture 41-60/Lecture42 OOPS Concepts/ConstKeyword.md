# Const Keyword in C++

The `const` keyword is used to make something **read-only**. Once a value is declared as `const`, it cannot be modified.

It helps in:

- Preventing accidental modifications.
- Making code safer and easier to understand.
- Allowing the compiler to perform certain optimizations.

---

# 1. Const Variables

A constant variable cannot be modified after initialization.

```cpp
const int age = 25;

age = 30;   // ❌ Error
```

---

# 2. Const Pointers

There are three different ways `const` can be used with pointers.

## Case 1: Pointer to Constant Data

The pointer can point somewhere else, but cannot modify the data.

```cpp
int a = 10;
int b = 20;

const int *ptr = &a;

*ptr = 50;     // ❌ Error
ptr = &b;      // ✅ Allowed
```

**Meaning:**

```
Data      -> Constant
Pointer   -> Not Constant
```

---

## Case 2: Constant Pointer

The pointer cannot point somewhere else, but can modify the data.

```cpp
int a = 10;
int b = 20;

int *const ptr = &a;

*ptr = 50;     // ✅ Allowed
ptr = &b;      // ❌ Error
```

**Meaning:**

```
Data      -> Not Constant
Pointer   -> Constant
```

---

## Case 3: Constant Pointer to Constant Data

Neither the pointer nor the data can change.

```cpp
int a = 10;

const int *const ptr = &a;

*ptr = 50;     // ❌ Error
ptr = nullptr; // ❌ Error
```

**Meaning:**

```
Data      -> Constant
Pointer   -> Constant
```

---

# 3. Const Function Parameters

Passing parameters as `const` ensures the function does not modify them.

```cpp
void printValue(const int value)
{
    // value cannot be modified
}
```

For primitive data types (`int`, `char`, `float`), this isn't very useful because they are passed by value.

It becomes useful when passing by reference.

```cpp
void print(const string &name)
{
    cout << name << endl;
}
```

The function promises not to modify the original string.

---

# 4. Const References

Using `const` references avoids copying while preventing modification.

```cpp
void printName(const string &name)
{
    cout << name << endl;
}
```

Advantages:

- No copy is created.
- Faster for large objects.
- Original object cannot be modified.

Without `const`:

```cpp
void printName(string &name)
{
    name = "ABC";    // Allowed
}
```

With `const`:

```cpp
void printName(const string &name)
{
    name = "ABC";    // ❌ Error
}
```

---

# 5. Const Member Functions

A member function marked as `const` promises **not to modify any member variables** of the object.

```cpp
class Car
{
    int mileage;

public:

    int getMileage() const
    {
        return mileage;
    }
};
```

Inside a const function:

```cpp
class Car
{
    int mileage;

public:

    void display() const
    {
        mileage = 100;   // ❌ Error
    }
};
```

Only reading member variables is allowed.

---

# 6. Const Objects

You can create an object as constant.

```cpp
class Car
{
public:

    void drive()
    {
        cout << "Driving";
    }
};

const Car car;
```

Since the object is constant, it cannot call non-const member functions.

```cpp
car.drive();      // ❌ Error
```

---

## Why?

A non-const member function may modify the object.

```cpp
void drive()
{
    mileage++;
}
```

Calling it on a constant object would violate the promise that the object cannot change.

---

# 7. Const Member Function with Const Object

```cpp
class Car
{
    int mileage = 20;

public:

    int getMileage() const
    {
        return mileage;
    }
};

const Car car;

cout << car.getMileage();     // ✅ Allowed
```

Because `getMileage()` promises not to modify the object.

---

# 8. Non-Const Object Can Call Const Function

A normal object can call both const and non-const member functions.

```cpp
class Car
{
public:

    void start()
    {
        cout << "Start";
    }

    void display() const
    {
        cout << "Display";
    }
};

Car car;

car.start();      // ✅
car.display();    // ✅
```

---

# 9. Const Return Value

A function can return a constant value.

```cpp
const int getValue()
{
    return 100;
}
```

Although valid, this is rarely useful for primitive types.

It is more commonly used when returning references.

```cpp
class Car
{
    string name;

public:

    const string& getName() const
    {
        return name;
    }
};
```

This prevents the caller from modifying the internal data.

```cpp
Car car;

car.getName() = "BMW";     // ❌ Error
```

---

# 10. Const vs Non-Const Member Functions

```cpp
class Car
{
    int mileage = 20;

public:

    int getMileage() const
    {
        return mileage;
    }

    void setMileage(int value)
    {
        mileage = value;
    }
};
```

Usage:

```cpp
Car car;

car.getMileage();     // ✅
car.setMileage(40);   // ✅

const Car c;

c.getMileage();       // ✅
c.setMileage(40);     // ❌ Error
```

---

# Summary

| Declaration                     | Meaning                                                |
| ------------------------------- | ------------------------------------------------------ |
| `const int x`                   | Constant variable                                      |
| `const int *ptr`                | Pointer to constant data                               |
| `int *const ptr`                | Constant pointer                                       |
| `const int *const ptr`          | Constant pointer to constant data                      |
| `const string &name`            | Read-only reference                                    |
| `void show() const`             | Function cannot modify object                          |
| `const Car car;`                | Constant object                                        |
| `const string& getName() const` | Returns read-only reference and does not modify object |

---

# Rules to Remember

- `const` variables cannot be modified.
- `const` references prevent modification while avoiding copies.
- `const` member functions can only read member variables.
- A `const` object can call **only const member functions**.
- A non-const object can call both const and non-const member functions.
- Returning `const` references protects internal data from modification.
