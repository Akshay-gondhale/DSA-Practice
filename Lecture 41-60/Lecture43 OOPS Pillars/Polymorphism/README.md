# C++ Polymorphism — Cheat Sheet

**Polymorphism** means **"one interface, multiple forms."**
It allows the same function/interface to behave differently depending on the situation.

## Types of Polymorphism

| Type             | When decided       | Examples                                   |
| ---------------- | ------------------ | ------------------------------------------ |
| **Compile-Time** | During compilation | Function Overloading, Operator Overloading |
| **Run-Time**     | During execution   | Virtual Functions                          |

---

## 1. Compile-Time Polymorphism

The compiler decides which operation/function to use.

### Function Overloading

Same function name with different parameters.

```cpp
class Calculator
{
public:
    int add(int a, int b);
    int add(int a, int b, int c);
};
```

### Operator Overloading

Allows operators to work with **user-defined objects**.

```cpp
class Number
{
public:
    int value;

    Number(int value)
    {
        this->value = value;
    }

    Number operator+(Number obj)
    {
        return Number(value + obj.value);
    }
};

int main()
{
    Number a(10);
    Number b(20);

    Number c = a + b;

    cout << c.value;   // 30
}
```

Here, the `+` operator is overloaded to add two `Number` objects.

**Common operators that can be overloaded:**

`+  -  *  /  ==  !=  <  >  ++  --  []  ()`

---

## 2. Run-Time Polymorphism

The function to execute is decided **at runtime** using virtual functions.

```cpp
class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal speaks";
    }
};

class Dog : public Animal
{
public:
    void speak() override
    {
        cout << "Dog barks";
    }
};

Animal *animal = new Dog();
animal->speak();   // Dog barks
```

### Key Concepts

- `virtual` → Enables runtime polymorphism.
- `override` → Indicates that a derived class is overriding a virtual function.
- **Base class pointer/reference** → Can refer to a derived class object.
- **Dynamic binding** → Function call is resolved at runtime.
- **Upcasting** → Derived object is treated as a base class object.

## Quick Memory Trick

> **Compile-Time → Overloading**
> **→ Function Overloading + Operator Overloading**
>
> **Run-Time → Overriding**
> **→ Virtual Function + Inheritance**

### In One Line

**Polymorphism = Same interface/operation + Different behavior.**
