# Initialization List in C++

An **Initialization List** is used to initialize member variables **before the constructor body executes**.

Instead of assigning values inside the constructor body, the members are initialized directly.

General syntax:

```cpp
ClassName(parameters)
    : member1(value1), member2(value2)
{
    // Constructor body
}
```

---

# Why Do We Need Initialization Lists?

Normally, member variables are first default initialized and then assigned new values inside the constructor.

Example:

```cpp
class Car
{
    int mileage;

public:

    Car(int mileage)
    {
        this->mileage = mileage;
    }
};
```

Execution:

```
Step 1:
mileage is default initialized.

Step 2:
mileage is assigned a new value.
```

Using an initialization list:

```cpp
class Car
{
    int mileage;

public:

    Car(int mileage)
        : mileage(mileage)
    {
    }
};
```

Execution:

```
Step 1:
mileage is initialized directly with the given value.
```

This avoids an unnecessary assignment.

---

# Basic Example

```cpp
#include <iostream>
using namespace std;

class Car
{
    int mileage;
    int seatingCapacity;

public:

    Car(int mileage, int seatingCapacity)
        : mileage(mileage),
          seatingCapacity(seatingCapacity)
    {
    }

    void print()
    {
        cout << mileage << endl;
        cout << seatingCapacity << endl;
    }
};

int main()
{
    Car car(20, 5);

    car.print();
}
```

Output

```
20
5
```

---

# Initialization List vs Assignment

### Assignment inside constructor

```cpp
class Car
{
    int mileage;

public:

    Car(int mileage)
    {
        this->mileage = mileage;
    }
};
```

### Initialization List

```cpp
class Car
{
    int mileage;

public:

    Car(int mileage)
        : mileage(mileage)
    {
    }
};
```

The second approach is generally preferred because the object is initialized directly.

---

# Multiple Member Initialization

You can initialize multiple variables.

```cpp
class Student
{
    string name;
    int age;
    float marks;

public:

    Student(string name, int age, float marks)
        : name(name),
          age(age),
          marks(marks)
    {
    }
};
```

---

# Initialization Order

**Important:** Members are initialized in the **order they are declared inside the class**, **not** the order written in the initialization list.

Example:

```cpp
class Test
{
    int a;
    int b;

public:

    Test()
        : b(20),
          a(10)
    {
    }
};
```

Actual initialization order:

```
1. a = 10
2. b = 20
```

because `a` is declared before `b`.

---

# Why Initialization Order Matters

Consider:

```cpp
class Test
{
    int a;
    int b;

public:

    Test()
        : b(20),
          a(b)
    {
    }
};
```

Many people expect:

```
b = 20
a = 20
```

Actual execution:

```
a is initialized first.
b has not been initialized yet.

Result:
Undefined Behavior
```

Correct version:

```cpp
class Test
{
    int b;
    int a;

public:

    Test()
        : b(20),
          a(b)
    {
    }
};
```

Now execution becomes:

```
b = 20
a = 20
```

---

# Initialization List with Const Members

Const members **must** be initialized using an initialization list.

Incorrect:

```cpp
class Car
{
    const int wheels;

public:

    Car()
    {
        wheels = 4;      // ❌ Error
    }
};
```

Correct:

```cpp
class Car
{
    const int wheels;

public:

    Car()
        : wheels(4)
    {
    }
};
```

Reason:

A const variable can only be initialized once.

---

# Initialization List with Reference Members

Reference members also **must** be initialized using an initialization list.

Incorrect:

```cpp
class Test
{
    int &value;

public:

    Test(int &x)
    {
        value = x;      // ❌ Error
    }
};
```

Correct:

```cpp
class Test
{
    int &value;

public:

    Test(int &x)
        : value(x)
    {
    }
};
```

Reason:

A reference must be bound to an object when it is created.

---

# Initialization List with Objects

If a class contains another object, it is best to initialize it using an initialization list.

```cpp
class Engine
{
public:

    Engine(int hp)
    {
    }
};

class Car
{
    Engine engine;

public:

    Car()
        : engine(150)
    {
    }
};
```

This directly constructs `engine` with the desired value.

Without an initialization list:

```cpp
class Car
{
    Engine engine;

public:

    Car()
    {
        engine = Engine(150);
    }
};
```

Execution:

```
1. Engine default constructor
2. Temporary Engine object created
3. Copy assignment
```

This is less efficient and may not even compile if `Engine` has no default constructor.

---

# Initialization List with Inheritance

The base class constructor is also called using the initialization list.

```cpp
class Animal
{
public:

    Animal(int age)
    {
    }
};

class Dog : public Animal
{
public:

    Dog()
        : Animal(5)
    {
    }
};
```

Here, the `Animal` constructor executes before the `Dog` constructor body.

---

# Constructor Body vs Initialization List

```cpp
class Car
{
    int mileage;

public:

    Car(int mileage)
        : mileage(mileage)
    {
        cout << "Constructor Body" << endl;
    }
};
```

Execution:

```
1. mileage is initialized.
2. Constructor body executes.
```

The constructor body always runs **after** the initialization list.

---

# Advantages of Initialization Lists

- Members are initialized directly.
- More efficient than assigning values later.
- Required for `const` members.
- Required for reference members.
- Required when a member object has no default constructor.
- Used to call base class constructors.
- Makes constructors cleaner and easier to read.

---

# Common Mistakes

## Mistake 1: Assuming initialization happens in list order

```cpp
class Test
{
    int a;
    int b;

public:

    Test()
        : b(20),
          a(10)
    {
    }
};
```

Initialization still happens as:

```
a
↓

b
```

because declaration order always wins.

---

## Mistake 2: Assigning const members

```cpp
const int x;

Test()
{
    x = 10;      // ❌ Error
}
```

Always use:

```cpp
Test()
    : x(10)
{
}
```

---

## Mistake 3: Assigning reference members

```cpp
int &ref;

Test(int &x)
{
    ref = x;     // ❌ Error
}
```

Correct:

```cpp
Test(int &x)
    : ref(x)
{
}
```

---

# Summary

| Situation                                  | Initialization List Required? |
| ------------------------------------------ | ----------------------------- |
| Normal member variables                    | Recommended                   |
| `const` members                            | ✅ Yes                        |
| Reference members                          | ✅ Yes                        |
| Member objects without default constructor | ✅ Yes                        |
| Base class constructor                     | ✅ Yes                        |

---

# Rules to Remember

- Initialization lists run **before** the constructor body.
- Members are initialized in **declaration order**, not initialization list order.
- Prefer initialization lists over assignments inside constructors.
- `const` members must be initialized using an initialization list.
- Reference members must be initialized using an initialization list.
- Base class constructors are called through the initialization list.
- Member objects are best initialized using initialization lists.
