# Encapsulation in C++

## 1. What is Encapsulation?

**Encapsulation** is an Object-Oriented Programming (OOP) concept where:

> **Data (variables) and the functions that operate on that data are bundled together inside a class, while direct access to the internal data is controlled.**

In C++, encapsulation is primarily achieved using:

- `class`
- Access modifiers:
  - `private`
  - `public`
  - `protected`

The main goal of encapsulation is **data protection and controlled access**.

---

# 2. Why Do We Need Encapsulation?

Consider a bank account.

An account has data such as:

```cpp
balance
accountNumber
```

We should not allow anyone to directly modify the balance:

```cpp
account.balance = -50000;
```

That could put the object into an invalid state.

Instead, we expose controlled functions:

```cpp
account.deposit(5000);
account.withdraw(2000);
```

The class decides **how its internal data can be accessed or modified**.

This is the basic idea behind encapsulation.

---

# 3. Without Encapsulation

Consider this class:

```cpp
class BankAccount
{
public:
    double balance;
};
```

Now anyone can modify the balance:

```cpp
int main()
{
    BankAccount account;

    account.balance = 10000;

    account.balance = -50000;

    cout << account.balance << endl;
}
```

There is no protection.

The class cannot control what value is assigned to `balance`.

This is a problem because:

```cpp
account.balance = -50000;
```

may violate the rules of a bank account.

---

# 4. Encapsulation Using `private`

We can make the data `private`.

```cpp
class BankAccount
{
private:
    double balance;

public:
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    double getBalance()
    {
        return balance;
    }
};
```

Now this is not allowed:

```cpp
int main()
{
    BankAccount account;

    account.balance = 10000;  // ERROR
}
```

Because `balance` is private.

Instead, we use the public functions:

```cpp
int main()
{
    BankAccount account;

    account.deposit(10000);

    cout << account.getBalance() << endl;
}
```

Output:

```text
10000
```

The object controls how its internal state can be modified.

---

# 5. Access Modifiers

C++ provides three access modifiers.

| Modifier    | Same Class | Derived Class | Outside Class |
| ----------- | ---------- | ------------- | ------------- |
| `private`   | Yes        | No            | No            |
| `protected` | Yes        | Yes           | No            |
| `public`    | Yes        | Yes           | Yes           |

For encapsulation, `private` and `public` are used most commonly.

---

# 6. `private`

A `private` member can only be accessed from inside the class.

Example:

```cpp
class Student
{
private:
    int marks;

public:
    void setMarks(int m)
    {
        marks = m;
    }

    int getMarks()
    {
        return marks;
    }
};
```

This is valid:

```cpp
Student s;

s.setMarks(90);

cout << s.getMarks();
```

But this is invalid:

```cpp
s.marks = 90;
```

because `marks` is private.

---

# 7. `public`

A `public` member can be accessed from outside the class.

```cpp
class Student
{
public:
    int rollNumber;
};
```

Now:

```cpp
Student s;

s.rollNumber = 10;

cout << s.rollNumber;
```

is valid.

---

# 8. Default Access Modifier in C++

There is an important difference between `class` and `struct`.

## Class

Members of a class are `private` by default.

```cpp
class Car
{
    int speed;
};
```

Here:

```cpp
speed
```

is private.

This is equivalent to:

```cpp
class Car
{
private:
    int speed;
};
```

---

## Struct

Members of a struct are `public` by default.

```cpp
struct Car
{
    int speed;
};
```

Here:

```cpp
speed
```

is public.

Therefore:

```cpp
Car car;

car.speed = 100;
```

is valid.

---

# 9. Getters and Setters

One common way of implementing encapsulation is using **getters and setters**.

Consider:

```cpp
class Person
{
private:
    int age;

public:

    void setAge(int age)
    {
        this->age = age;
    }

    int getAge()
    {
        return age;
    }
};
```

Usage:

```cpp
int main()
{
    Person p;

    p.setAge(25);

    cout << p.getAge() << endl;
}
```

Output:

```text
25
```

Here:

```cpp
setAge()
```

is a **setter**.

And:

```cpp
getAge()
```

is a **getter**.

---

# 10. Why Not Make Everything Public?

You might wonder:

> Why not simply make all variables public?

For example:

```cpp
class Person
{
public:
    int age;
};
```

Then:

```cpp
Person p;

p.age = -100;
```

This is syntactically valid.

But logically it is wrong.

We can prevent this by controlling access:

```cpp
class Person
{
private:
    int age;

public:
    void setAge(int age)
    {
        if (age >= 0)
        {
            this->age = age;
        }
    }

    int getAge()
    {
        return age;
    }
};
```

Now:

```cpp
p.setAge(-100);
```

will not modify the object.

This is the real benefit of encapsulation.

---

# 11. Encapsulation Allows Validation

One major advantage of encapsulation is that we can validate data before modifying the object.

Example:

```cpp
class BankAccount
{
private:
    double balance = 0;

public:

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount" << endl;
            return;
        }

        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount" << endl;
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient balance" << endl;
            return;
        }

        balance -= amount;
    }

    double getBalance()
    {
        return balance;
    }
};
```

Now the class maintains the validity of its own state.

---

# 12. Encapsulation Is More Than Getters and Setters

A common misconception is:

> Encapsulation means making variables private and creating getters and setters.

That is only one way of implementing it.

Consider:

```cpp
class BankAccount
{
private:
    double balance = 0;

public:

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
        }
    }
};
```

Notice that there is no:

```cpp
setBalance()
```

This is actually better.

Why?

Because we don't want arbitrary code to set the balance.

We want the balance to change only through valid operations:

```cpp
deposit()
withdraw()
```

Therefore, good encapsulation is about:

> **Controlling how an object's internal state can be accessed and modified.**

Not simply creating getters and setters for every variable.

---

# 13. Real-World Example

Consider a `Car`.

A car has internal state:

```cpp
fuel
speed
engineStatus
```

We don't want external code to directly manipulate everything.

For example:

```cpp
car.fuel = -100;
car.speed = 5000;
```

Instead, the class provides meaningful operations:

```cpp
car.startEngine();
car.accelerate();
car.brake();
car.refuel();
```

Example:

```cpp
class Car
{
private:
    int speed = 0;
    int fuel = 0;
    bool engineStarted = false;

public:

    void startEngine()
    {
        if (fuel > 0)
        {
            engineStarted = true;
        }
    }

    void accelerate(int value)
    {
        if (engineStarted && value > 0)
        {
            speed += value;
        }
    }

    void brake(int value)
    {
        if (value > 0)
        {
            speed -= value;

            if (speed < 0)
            {
                speed = 0;
            }
        }
    }

    int getSpeed()
    {
        return speed;
    }
};
```

Usage:

```cpp
int main()
{
    Car car;

    car.startEngine();
    car.accelerate(50);

    cout << car.getSpeed() << endl;
}
```

The user of the class doesn't need to know how the internal state is maintained.

---

# 14. Encapsulation and Data Hiding

The terms **encapsulation** and **data hiding** are closely related but are not exactly the same.

## Encapsulation

Encapsulation means:

> Bundling data and the operations that work on that data together inside a class and controlling access to them.

## Data Hiding

Data hiding means:

> Preventing external code from directly accessing internal implementation details.

For example:

```cpp
class BankAccount
{
private:
    double balance;

public:
    void deposit(double amount);
    void withdraw(double amount);
};
```

Here:

- `balance` is hidden.
- `deposit()` and `withdraw()` provide controlled access.
- Data and operations are bundled inside `BankAccount`.

So:

```text
Encapsulation
      |
      +---- Bundles data + methods
      |
      +---- Controls access
      |
      +---- Enables data hiding
```

---

# 15. Encapsulation and Abstraction

Encapsulation and abstraction are often confused.

They are related but different.

## Encapsulation

Focuses on:

> **How data and methods are packaged and access is controlled.**

Example:

```cpp
class Car
{
private:
    int speed;

public:
    void accelerate();
};
```

`speed` is hidden and can only be accessed through controlled operations.

---

## Abstraction

Focuses on:

> **What should be exposed while hiding unnecessary implementation details.**

For example:

```cpp
car.accelerate();
```

The user doesn't need to know how acceleration is internally implemented.

---

### Simple Difference

```text
Encapsulation
    ↓
Protects and controls data

Abstraction
    ↓
Hides unnecessary implementation complexity
```

A useful way to remember:

> **Encapsulation = How we protect and package things.**

> **Abstraction = What we choose to expose and hide.**

---

# 16. Encapsulation Example With Constructor

Encapsulation can also be combined with constructors.

```cpp
class Employee
{
private:
    string name;
    double salary;

public:

    Employee(string name, double salary)
    {
        this->name = name;

        if (salary >= 0)
        {
            this->salary = salary;
        }
        else
        {
            this->salary = 0;
        }
    }

    string getName()
    {
        return name;
    }

    double getSalary()
    {
        return salary;
    }
};
```

Usage:

```cpp
Employee e("Akshay", 50000);

cout << e.getName() << endl;
cout << e.getSalary() << endl;
```

The constructor ensures that the object starts with a valid state.

---

# 17. Encapsulation With `protected`

`protected` is useful when inheritance is involved.

```cpp
class Animal
{
protected:
    string name;
};

class Dog : public Animal
{
public:

    void setName(string name)
    {
        this->name = name;
    }

    void printName()
    {
        cout << name << endl;
    }
};
```

Here:

```cpp
name
```

cannot be accessed directly from outside:

```cpp
Dog d;

d.name = "Tommy";  // ERROR
```

But a derived class can access it.

```cpp
class Dog : public Animal
{
    // Can access name
};
```

So `protected` provides controlled access between a base class and its derived classes.

---

# 18. Complete Example

Let's create a `Student` class.

Requirements:

- Student has a name.
- Student has marks.
- Marks should be between `0` and `100`.
- Outside code should not directly modify marks.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    string name;
    int marks;

public:

    Student(string name, int marks)
    {
        this->name = name;

        if (marks >= 0 && marks <= 100)
        {
            this->marks = marks;
        }
        else
        {
            this->marks = 0;
        }
    }

    void setMarks(int marks)
    {
        if (marks >= 0 && marks <= 100)
        {
            this->marks = marks;
        }
    }

    int getMarks()
    {
        return marks;
    }

    string getName()
    {
        return name;
    }
};

int main()
{
    Student student("Rahul", 85);

    cout << student.getName() << endl;
    cout << student.getMarks() << endl;

    student.setMarks(95);

    cout << student.getMarks() << endl;

    return 0;
}
```

Output:

```text
Rahul
85
95
```

Trying to do this:

```cpp
student.marks = 500;
```

will result in a compilation error because `marks` is private.

---

# 19. Advantages of Encapsulation

## 1. Data Protection

Internal data cannot be directly modified.

```cpp
private:
    int balance;
```

---

## 2. Validation

We can validate values before modifying the object.

```cpp
void setAge(int age)
{
    if (age >= 0)
    {
        this->age = age;
    }
}
```

---

## 3. Maintainability

Internal implementation can change without affecting the code using the class.

For example, initially:

```cpp
private:
    int speed;
```

Later we might change the implementation:

```cpp
private:
    int speed;
    int acceleration;
```

As long as the public interface remains compatible, external code doesn't need to know about the change.

---

## 4. Reduced Coupling

External code depends on the public interface instead of internal implementation.

Instead of:

```cpp
car.speed += 10;
```

we use:

```cpp
car.accelerate(10);
```

This gives the class control over how the operation is performed.

---

## 5. Better Object Design

The class becomes responsible for maintaining its own state.

For example:

```cpp
BankAccount
```

should be responsible for ensuring:

```text
balance >= 0
```

rather than forcing every user of the class to remember this rule.

---

# 20. Important Principle: Keep Invariants Inside the Class

An **invariant** is a condition that should remain true for a valid object.

For example:

```cpp
class BankAccount
{
private:
    double balance;
};
```

Suppose the rule is:

```text
balance >= 0
```

If `balance` is public:

```cpp
account.balance = -5000;
```

The object can become invalid.

With encapsulation:

```cpp
class BankAccount
{
private:
    double balance;

public:
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
    }
};
```

The class can protect its invariant.

This is one of the most important practical reasons for encapsulation.

---

# 21. Encapsulation vs Public Data

### Poor design

```cpp
class Employee
{
public:
    double salary;
};
```

Usage:

```cpp
employee.salary = -100000;
```

The object has no control.

---

### Better design

```cpp
class Employee
{
private:
    double salary;

public:

    void setSalary(double salary)
    {
        if (salary >= 0)
        {
            this->salary = salary;
        }
    }

    double getSalary()
    {
        return salary;
    }
};
```

Now the class controls its state.

---

# 22. Encapsulation Does Not Mean Everything Must Be Private

You don't have to make every member private.

For example:

```cpp
class Point
{
public:
    int x;
    int y;
};
```

For a simple value-like type, public data may be completely reasonable.

Encapsulation is about **appropriate control**, not blindly making everything private.

The important question is:

> Does the object need to protect or validate this state?

If yes, private data with controlled operations may be appropriate.

---

# 23. Best Practices

### 1. Keep implementation details private

Prefer:

```cpp
class Car
{
private:
    int speed;
};
```

over exposing internal state unnecessarily.

---

### 2. Expose meaningful operations

Prefer:

```cpp
car.accelerate(20);
car.brake(10);
```

instead of:

```cpp
car.speed += 20;
car.speed -= 10;
```

---

### 3. Don't blindly create getters and setters

This:

```cpp
getBalance()
setBalance()
```

may not always be good design.

For a bank account, this is dangerous:

```cpp
account.setBalance(-100000);
```

It may be better to expose:

```cpp
deposit()
withdraw()
```

because these represent meaningful operations.

---

### 4. Keep validation close to the data

If a rule belongs to the `BankAccount` class, implement it inside `BankAccount`.

Don't rely on every caller to remember the rule.

---

# 24. Key Interview Definition

A concise interview answer:

> **Encapsulation in C++ is the bundling of data and the methods that operate on that data within a class, while restricting direct access to the internal state using access modifiers such as private, protected, and public. It provides controlled access to an object's state and helps maintain data integrity.**

---

# 25. Quick Revision

```text
                 ENCAPSULATION
                       |
          +------------+------------+
          |                         |
     Bundle together          Control access
          |                         |
    Data + Methods          private/public/protected
          |
          ↓
    Class
          |
          ↓
   Protect object state
          |
          ↓
   Validate modifications
```

### Remember

```cpp
class BankAccount
{
private:
    double balance;

public:
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
};
```

Here:

- `balance` → internal/private state
- `deposit()` → controlled modification
- `withdraw()` → controlled modification
- `getBalance()` → controlled read access

The outside world does **not** directly manipulate `balance`.

That is the core idea of **encapsulation**.

---

# 26. One-Line Summary

> **Encapsulation means keeping an object's data and the operations on that data together, while controlling how the outside world can access or modify that data.**
