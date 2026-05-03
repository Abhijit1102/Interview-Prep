## What is OOP?

Before OOP, code was written as along list of instructions. As projects grew bigger, it become messy and hard to manage. OOP sloves this by organising code around real-world objects.

- Everthing in the real world is an Object - OOP brings that thinkig into Code.
- Code is organised into classes, making it clean and structured.
- Easier to debug, extend and maintain large applications.
- Build on 4 core pillars : `Encapsulation`, `Inheritance`, `Polymorphism`, & `Abstraction`.

### Inheritance

Inheritance allows one class to acquire the properties and methods of another class. This avoids writing the same code again and again, and makes your codebase much cleaner.

- `Parent Class` (also called `base class`) contains common, shared features.
- `Child Class` (also called `Derived class`) inherts everything from parent.
- Child class can also add its own nw attributes and methods on top.
- Changes made in the parent class automatically reflelt in child classes.
- Real life example: Animal class has eat() and sleep(). Dog and cat inherit these, and Dog adds bark(), Cat adds meow().

## Polymorphism

Poly means many, morph means forms, Polymorphism allows the same method name to behave differently depending on which objects call it. This makes your code hightly flexible and extensible.

- Same method name works differently for differenct classes
- You don't need to remember multiple method names for simillar actions.
- `Method Overriding`: Child class provides its own version of a parent's method.

**Real life example: A `draw()` method on a Circle draw a circle on a Rectangle its draws a rectangle - same name, different behavior**

## Encapsulation

Encapsulation is about protecting the internal data of a class You control what the outside world can see and what it cannot. This prevents accidental modification of important data.

- Data and methods that operate on that data are bundled together inside a class.
- Sensitive data is marked private so it can't be accessed directly from outside.
- Access is given throught controlled methods called getters and setters .
- Makes code more secures and predictable
- `Real life example`: ATM machine you can check balance and withdraw. but you can't access the bank's intenal system directly.

## Abstraction

Abstraction is about reduing complexity. You expose only the necessary details to the user and hide all the complicated internal logic. The user does't need to know how things work inside, just that they work.
