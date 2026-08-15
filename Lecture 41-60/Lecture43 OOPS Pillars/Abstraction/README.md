# C++ Abstraction — Cheat Sheet

## 🧠 What is Abstraction?

**Abstraction is the process of hiding unnecessary implementation details and exposing only the functionality that the user needs.**

### Simple idea

```text
              ABSTRACTION
                   │
          ┌────────┴────────┐
          │                 │
       EXPOSE             HIDE
          │                 │
     WHAT to do          HOW it works
```

### Real-world example

When you use an **ATM**:

```text
You see:
    ├── Withdraw
    ├── Deposit
    └── Check Balance

You don't see:
    ├── Database operations
    ├── Account verification
    ├── Transaction processing
    └── Security checks
```

You only interact with the **essential interface**.

---

# 🔑 Abstraction in C++

C++ mainly provides abstraction through:

1. **Access Modifiers**
2. **Classes**
3. **Abstract Classes**
4. **Pure Virtual Functions**

---

## 1. Access Modifiers

Access modifiers control **which members of a class can be accessed from where**.

```cpp
class Car
{
public:
    void start();

private:
    void igniteEngine();
    void injectFuel();

protected:
    void engineCheck();
};
```

### `public`

Accessible from anywhere the object itself is accessible.

```cpp
Car car;
car.start();        // ✅
```

Use `public` for functionality that should be exposed to the user.

---

### `private`

Accessible only inside the same class.

```cpp
Car car;
car.igniteEngine();    // ❌
```

Useful for hiding internal implementation details and protecting data.

---

### `protected`

Accessible:

- Inside the same class
- Inside derived classes

```text
             Car
              │
         protected
              │
              ▼
         SportsCar
```

Useful when derived classes need access to implementation details that should remain hidden from normal users.

---

## ⚠️ Important Distinction

`public`, `private`, and `protected` are technically **access specifiers**.

They are primarily associated with **encapsulation**, but they also help achieve **abstraction**.

```text
Access Modifiers
       │
       ├── Control ACCESS
       │       ↓
       │   Encapsulation
       │
       └── Hide unnecessary details
               ↓
           Abstraction
```

So don't think:

> "`private` = abstraction"

Instead think:

> **Access control is a tool that can help us implement abstraction and encapsulation.**

---

# 2. Abstract Classes

An **abstract class** is a class that cannot be instantiated directly.

It is commonly used to define a common interface for derived classes.

```cpp
class Animal
{
public:
    virtual void speak() = 0;
};
```

Because `speak()` is a **pure virtual function**, `Animal` becomes an abstract class.

```cpp
Animal animal;    // ❌ Cannot create object
```

But:

```cpp
class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Bark";
    }
};

Dog dog;          // ✅
```

---

# 3. Pure Virtual Function

A pure virtual function is declared using:

```cpp
virtual void speak() = 0;
```

The `= 0` means:

> The base class is declaring the required behavior, but does not provide the implementation that derived classes must use.

```text
             Animal
                │
          ┌─────┴─────┐
          │ speak()   │
          │   = 0     │
          └─────┬─────┘
                │
       ┌────────┴────────┐
       ▼                 ▼
      Dog               Cat
       │                 │
     Bark              Meow
```

### Key idea

```text
Base class
    │
    │ WHAT should happen?
    ▼
speak()

Derived class
    │
    │ HOW should it happen?
    ▼
Bark / Meow
```

This is one of the strongest examples of **abstraction** in C++.

---

# 4. Abstraction Through a Public Interface

A common abstraction pattern is:

```cpp
class Database
{
public:
    void saveData();

private:
    void connect();
    void executeQuery();
    void closeConnection();
};
```

The user only needs:

```cpp
database.saveData();
```

They don't need to know:

```text
saveData()
   │
   ├── connect()
   ├── executeQuery()
   └── closeConnection()
```

The public function acts as the **interface**, while the implementation remains hidden.

---

# 🆚 Abstraction vs Encapsulation

These two concepts are closely related, which is why they are often confused.

|              | **Abstraction**                                      | **Encapsulation**                       |
| ------------ | ---------------------------------------------------- | --------------------------------------- |
| Main idea    | Hide complexity                                      | Control access                          |
| Focus        | **WHAT**                                             | **HOW/WHO can access**                  |
| Goal         | Simplify usage                                       | Protect internal state                  |
| Example      | `withdraw()` hides banking logic                     | `balance` is `private`                  |
| Common tools | Abstract classes, pure virtual functions, interfaces | `private`, `protected`, getters/setters |

### Example

```cpp
class BankAccount
{
private:
    double balance;

public:
    void withdraw(double amount);
};
```

### Encapsulation

```text
balance
   │
   ▼
private
   │
   ▼
Outside code cannot directly modify it
```

### Abstraction

```text
User
  │
  │ withdraw()
  ▼
BankAccount
  │
  └── Complex withdrawal logic is hidden
```

---

# 🧠 The Best Way to Remember

### Encapsulation asks:

> **"Who should be allowed to access this?"**

### Abstraction asks:

> **"What does the user actually need to know?"**

```text
                CLASS
                  │
        ┌─────────┴─────────┐
        ▼                   ▼
  ENCAPSULATION         ABSTRACTION
        │                   │
   Control access       Hide complexity
        │                   │
   private/protected     Interface
   getters/setters       Abstract class
                         Pure virtual
```

---

# 📌 Important Points

- **Abstraction hides unnecessary complexity.**
- It exposes only the functionality required by the user.
- `public`, `private`, and `protected` are **access specifiers**.
- Access specifiers are primarily used for **encapsulation**, but they also help achieve abstraction.
- **Abstract classes** cannot be instantiated.
- A class with at least one **pure virtual function** is abstract.
- `virtual ... = 0` declares a pure virtual function.
- Abstract classes define **WHAT** derived classes should do.
- Derived classes define **HOW** they do it.

---

## ⭐ One-Line Interview Definitions

**Abstraction:**

> Hiding implementation complexity and exposing only essential functionality.

**Encapsulation:**

> Bundling data and methods together while controlling access to the object's internal state.

**Abstract Class:**

> A class that cannot be instantiated directly and is typically used to define a common interface for derived classes.

**Pure Virtual Function:**

> A virtual function declared with `= 0` that makes its class abstract and requires derived classes to provide an implementation.
