# Object Oriented Programming (OOP) — Notes

## What is OOP?

Object Oriented Programming is a programming paradigm that models real-world entities using **objects**.
It helps in building software that is **secure, scalable, reusable, and easy to maintain**.

In OOP:

* Programs are organized around **objects** instead of functions.
* Each object contains **data (properties)** and **behavior (methods)**.
* Objects interact with each other to solve a problem.

---

## Why OOP is Important

OOP is widely used in real-world software systems because it provides:

* Real world modeling (maps real life entities to code)
* Data security
* Code reusability
* Scalability for large applications
* Easier debugging and maintenance

Example:

* Bank Account
* Car
* User in a website
* Order in an e-commerce system

Each of these can be represented as an **object**.

---

## Object

An **Object** is an instance of a class.

An object has:

1. **Characteristics (State / Properties)** → variables
2. **Behavior (Functions / Methods)** → actions it can perform

Example:
Car Object:

* Properties → color, speed, brand
* Behaviors → start(), brake(), accelerate()

---

## Class

A **Class** is a blueprint or template used to create objects.

Example:

```
class Car {
    string color;
    int speed;

    void start() {}
    void stop() {}
}
```

Here, `Car` is the class and actual cars created from it are objects.

---

# Four Pillars of OOP

---

## 1. Abstraction

**Definition:**
Abstraction hides unnecessary internal details and shows only the essential features to the user.

We focus on **what an object does**, not **how it does it**.

Example (Real Life):
You drive a car using a steering wheel and pedals.
You do NOT need to know how the engine works internally.

Programming Example:

```
ATM Machine
You withdraw money
You don't see bank server logic
```

Benefit:

* Reduces complexity
* Cleaner interface
* Easier usage

---

## 2. Encapsulation

**Definition:**
Encapsulation means **binding data and methods into a single unit (class)** and restricting direct access to data.

It also provides **data security** using access modifiers.

We protect data using:

* private
* public
* protected

Example:

```
class BankAccount {
private:
    int balance;

public:
    void deposit(int amount) {
        balance += amount;
    }
};
```

Here, balance cannot be changed directly from outside.

Benefits:

* Data hiding
* Data protection
* Controlled access

---

## 3. Inheritance

**Definition:**
Inheritance allows a **child class to acquire properties and behaviors of a parent class**.

It represents **parent–child relationship**.

Example:

```
class Vehicle {
public:
    void start() {}
};

class Car : public Vehicle {
};
```

Car now automatically has `start()` method.

Benefits:

* Code reusability
* Avoids duplication
* Easier extension of features

---

## 4. Polymorphism

**Definition:**
Polymorphism means **same function name behaves differently in different situations**.

("Poly" = many, "morph" = forms)

### Types:

### 1. Compile Time (Function Overloading)

```
int add(int a, int b);
double add(double a, double b);
```

### 2. Run Time (Method Overriding)

```
class Animal {
public:
    void sound() {
        cout << "Animal sound";
    }
};

class Dog : public Animal {
public:
    void sound() {
        cout << "Bark";
    }
};
```

Benefits:

* Flexibility
* Extensibility
* Cleaner code

---

## Summary Table

| Pillar        | Purpose                            |
| ------------- | ---------------------------------- |
| Abstraction   | Hide implementation details        |
| Encapsulation | Secure and protect data            |
| Inheritance   | Reuse code                         |
| Polymorphism  | Same interface, different behavior |

---

## Final Note

OOP is heavily used in:

* Backend development
* Game development
* Mobile apps (Android, iOS)
* Enterprise software
* System design interviews

Understanding OOP is essential for **DSA + LLD + HLD interviews**.
