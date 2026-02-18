# UML Diagrams — Quick Guide for Developers

A beginner-friendly reference to understanding UML (Unified Modeling Language) diagrams, with a focus on **Class Diagrams** and **Sequence Diagrams** — essential for Object-Oriented Programming (OOP), Low Level Design (LLD), and System Design interviews.

---

## Table of Contents

- [What is UML?](#what-is-uml)
- [Types of UML Diagrams](#types-of-uml-diagrams)
- [Class Diagrams](#class-diagrams)
  - [Access Modifiers](#access-modifiers)
  - [Abstract Classes](#abstract-classes)
  - [Example: Car Class](#example-car-class)
  - [Access Scope Table](#access-scope-table)
  - [Associations](#associations)
- [Sequence Diagrams](#sequence-diagrams)
  - [Components](#components)
  - [Message Types](#message-types)
  - [Example: Login Flow](#example-login-flow)
- [Why Developers Should Learn UML](#why-developers-should-learn-uml)
- [Folder Structure](#folder-structure)
- [Usage](#usage)
- [Screenshots](#screenshots)
- [Contributing](#contributing)
---

## What is UML?

**UML (Unified Modeling Language)** is a standardized way to visually represent software architecture and object-oriented systems — before writing any actual code.

It helps developers:

- Plan software structure
- Communicate design decisions with teams
- Reduce implementation errors
- Model real-world systems
- Prepare for System Design interviews

---

## Types of UML Diagrams

UML diagrams are divided into two major categories:

### 1. Structural (Static) Diagrams

Describe *how the system is organized*.

> Examples: Class Diagram, Object Diagram, Component Diagram, Package Diagram

### 2. Behavioral (Dynamic) Diagrams

Describe *how the system behaves over time*.

> Examples: Sequence Diagram, Use Case Diagram, Activity Diagram, State Diagram

---

## Class Diagrams

A **Class Diagram** shows:

- Classes and their relationships
- Properties (attributes/variables)
- Methods (functions/behaviours)

It represents the **blueprint of your code** before implementation.

---

### Access Modifiers

| Symbol | Access Level | Meaning                                       |
|--------|--------------|-----------------------------------------------|
| `+`    | Public       | Accessible from anywhere                      |
| `-`    | Private      | Accessible only inside the class              |
| `#`    | Protected    | Accessible inside the class and child classes |

---

### Abstract Classes

Abstract classes are annotated using the `<<abstract>>` stereotype above the class name:

```
<<abstract>>
ClassName
```

---

### Example: Car Class

```
          <<abstract>>
┌───────────────────────────┐
│            Car            │
├───────────────────────────┤
│  + brand   : String       │
│  + model   : String       │
│  # engine  : int          │
├───────────────────────────┤
│  - startEngine() : void   │
│  - stopEngine()  : void   │
│  - accelerate()  : void   │
│  - brake()       : void   │
└───────────────────────────┘
```

**Attributes:**

- `brand` — Public
- `model` — Public
- `engine` — Protected

**Methods:**

- `startEngine()`, `stopEngine()`, `accelerate()`, `brake()` — all Private

---

### Access Scope Table

| Access Level | Within Class | Child Class | Outside Class |
|--------------|:------------:|:-----------:|:-------------:|
| Public       | ✅           | ✅          | ✅            |
| Protected    | ✅           | ✅          | ❌            |
| Private      | ✅           | ❌          | ❌            |

---

### Associations

Associations describe the **relationships between classes**.

#### 1. Inheritance — IS-A Relationship

Represents a parent → child relationship.

```
SportsCar ----|> Car
```

> A `SportsCar` *is a* `Car`

---

#### 2. Simple Association — HAS-A Relationship

Represents when one object uses another object.

```
Arun ---- House
```

> Arun *has a* House

---

#### 3. Aggregation — Weak HAS-A Relationship

The child object **can exist independently** of the parent.

```
Room <>---- Chair
```

> A Room has a Chair and a Bed. If the Room is destroyed, the Chair still exists.

---

#### 4. Composition — Strong HAS-A Relationship

The child object **cannot exist without** the parent.

```
House ◆---- Room
```

> A House has Rooms. If the House is destroyed, the Rooms are also destroyed.

---

## Sequence Diagrams

A **Sequence Diagram** shows how objects interact with each other **over time** within an application.

Common use cases include:

- API request/response flows
- Login and authentication systems
- Payment processing flows
- Database call sequences

---

### Components

| Component          | Description                                                                         |
|--------------------|-------------------------------------------------------------------------------------|
| **Objects**        | The participants in the interaction (e.g., User, Server, Database)                  |
| **Lifeline**       | A vertical dashed line showing how long an object exists during execution           |
| **Activation Bar** | A vertical rectangle on the lifeline showing when an object is actively executing   |
| **Messages**       | Arrows between objects representing communication                                   |

---

### Message Types

| Type             | Description                                           | Example                                 |
|------------------|-------------------------------------------------------|-----------------------------------------|
| **Synchronous**  | The caller waits for a response before continuing     | `User → Server : login()`              |
| **Asynchronous** | The caller does not wait and continues immediately    | `Server → EmailService : sendEmail()`  |

---

### Example: Login Flow

```
User     ->  Server   : login(username, password)
Server   ->  Database : verifyUser()
Database --> Server   : userValid
Server   --> User     : Login Success
```

---

## Why Developers Should Learn UML

- Required for **System Design** and **LLD interviews**
- Improves code architecture and planning
- Prevents poor design decisions before implementation
- Simplifies communication in team discussions
- Useful for documenting existing systems

---

## Folder Structure

```
uml-diagrams/
│
├── class-diagrams/
├── sequence-diagrams/
├── examples/
└── README.md
```

---

## Usage

Create UML diagrams **before coding** when:

- Designing a new project from scratch
- Building scalable backend systems
- Preparing for software engineering interviews
- Working collaboratively in a team

**Recommended Tools:**

| Tool       | Type       | Link                       |
|------------|------------|----------------------------|
| Draw.io    | Web-based  | https://draw.io            |
| Lucidchart | Web-based  | https://lucidchart.com     |
| Excalidraw | Web-based  | https://excalidraw.com     |
| PlantUML   | Code-based | https://plantuml.com       |

---
 # UML Diagrams — Quick Guide for Developers

A beginner-friendly reference to understanding UML (Unified Modeling Language) diagrams, with a focus on **Class Diagrams** and **Sequence Diagrams** — essential for Object-Oriented Programming (OOP), Low Level Design (LLD), and System Design interviews.

---

## Table of Contents

- [What is UML?](#what-is-uml)
- [Types of UML Diagrams](#types-of-uml-diagrams)
- [Class Diagrams](#class-diagrams)
  - [Access Modifiers](#access-modifiers)
  - [Abstract Classes](#abstract-classes)
  - [Example: Car Class](#example-car-class)
  - [Access Scope Table](#access-scope-table)
  - [Associations](#associations)
- [Sequence Diagrams](#sequence-diagrams)
  - [Components](#components)
  - [Message Types](#message-types)
  - [Example: Login Flow](#example-login-flow)
  - [Example: ATM Transaction](#example-atm-transaction)
- [Why Developers Should Learn UML](#why-developers-should-learn-uml)
- [Folder Structure](#folder-structure)
- [Usage](#usage)
- [Screenshots](#screenshots)
- [Contributing](#contributing)
- [Future Improvements](#future-improvements)
- [License](#license)

---

## What is UML?

**UML (Unified Modeling Language)** is a standardized way to visually represent software architecture and object-oriented systems — before writing any actual code.

It helps developers:

- Plan software structure
- Communicate design decisions with teams
- Reduce implementation errors
- Model real-world systems
- Prepare for System Design interviews

---

## Types of UML Diagrams

UML diagrams are divided into two major categories:

### 1. Structural (Static) Diagrams

Describe *how the system is organized*.

> Examples: Class Diagram, Object Diagram, Component Diagram, Package Diagram

### 2. Behavioral (Dynamic) Diagrams

Describe *how the system behaves over time*.

> Examples: Sequence Diagram, Use Case Diagram, Activity Diagram, State Diagram

---

## Class Diagrams

A **Class Diagram** shows:

- Classes and their relationships
- Properties (attributes/variables)
- Methods (functions/behaviours)

It represents the **blueprint of your code** before implementation.

---

### Access Modifiers

| Symbol | Access Level | Meaning                                       |
|--------|--------------|-----------------------------------------------|
| `+`    | Public       | Accessible from anywhere                      |
| `-`    | Private      | Accessible only inside the class              |
| `#`    | Protected    | Accessible inside the class and child classes |

---

### Abstract Classes

Abstract classes are annotated using the `<<abstract>>` stereotype above the class name:

```
<<abstract>>
ClassName
```

---

### Example: Car Class

```
          <<abstract>>
┌───────────────────────────┐
│            Car            │
├───────────────────────────┤
│  + brand   : String       │
│  + model   : String       │
│  # engine  : int          │
├───────────────────────────┤
│  - startEngine() : void   │
│  - stopEngine()  : void   │
│  - accelerate()  : void   │
│  - brake()       : void   │
└───────────────────────────┘
```

**Attributes:**

- `brand` — Public
- `model` — Public
- `engine` — Protected

**Methods:**

- `startEngine()`, `stopEngine()`, `accelerate()`, `brake()` — all Private

---

### Access Scope Table

| Access Level | Within Class | Child Class | Outside Class |
|--------------|:------------:|:-----------:|:-------------:|
| Public       | ✅           | ✅          | ✅            |
| Protected    | ✅           | ✅          | ❌            |
| Private      | ✅           | ❌          | ❌            |

---

### Associations

Associations describe the **relationships between classes**.

#### 1. Inheritance — IS-A Relationship

Represents a parent → child relationship.

```
SportsCar ----|> Car
```

> A `SportsCar` *is a* `Car`

---

#### 2. Simple Association — HAS-A Relationship

Represents when one object uses another object.

```
Arun ---- House
```

> Arun *has a* House

---

#### 3. Aggregation — Weak HAS-A Relationship

The child object **can exist independently** of the parent.

```
Room <>---- Chair
```

> A Room has a Chair and a Bed. If the Room is destroyed, the Chair still exists.

---

#### 4. Composition — Strong HAS-A Relationship

The child object **cannot exist without** the parent.

```
House ◆---- Room
```

> A House has Rooms. If the House is destroyed, the Rooms are also destroyed.

---

## Sequence Diagrams

A **Sequence Diagram** shows how objects interact with each other **over time** within an application.

Common use cases include:

- API request/response flows
- Login and authentication systems
- Payment processing flows
- Database call sequences

---

### Components

| Component          | Description                                                                         |
|--------------------|-------------------------------------------------------------------------------------|
| **Objects**        | The participants in the interaction (e.g., User, Server, Database)                  |
| **Lifeline**       | A vertical dashed line showing how long an object exists during execution           |
| **Activation Bar** | A vertical rectangle on the lifeline showing when an object is actively executing   |
| **Messages**       | Arrows between objects representing communication                                   |

---

### Message Types

| Type             | Description                                           | Example                                 |
|------------------|-------------------------------------------------------|-----------------------------------------|
| **Synchronous**  | The caller waits for a response before continuing     | `User → Server : login()`              |
| **Asynchronous** | The caller does not wait and continues immediately    | `Server → EmailService : sendEmail()`  |

---

### Example: Login Flow

```
User     ->  Server   : login(username, password)
Server   ->  Database : verifyUser()
Database --> Server   : userValid
Server   --> User     : Login Success
```

---

### Example: ATM Transaction

This diagram models a complete ATM cash withdrawal flow involving four participants: the **Customer**, the **ATM Machine**, the **Bank Server**, and the **Database**.

#### Participants

| Participant     | Role                                                              |
|-----------------|-------------------------------------------------------------------|
| `Customer`      | The person interacting with the ATM                               |
| `ATM`           | The physical machine handling input, display, and cash dispensing |
| `BankServer`    | The backend system that processes authentication and transactions  |
| `Database`      | Stores account details, PINs, and balance information             |

---

#### Step-by-Step Flow

```
Customer          ATM               BankServer         Database
   |               |                    |                   |
   |-- insertCard->|                    |                   |
   |               |                    |                   |
   |               |-- validateCard() ->|                   |
   |               |                    |-- checkCard() --> |
   |               |                    |<-- cardValid ---- |
   |               |<-- cardAccepted ---|                   |
   |               |                    |                   |
   |<-- promptPIN -|                    |                   |
   |               |                    |                   |
   |-- enterPIN -->|                    |                   |
   |               |                    |                   |
   |               |-- verifyPIN() ---> |                   |
   |               |                    |-- matchPIN() --> |
   |               |                    |<-- pinCorrect -- |
   |               |<-- authSuccess ----|                   |
   |               |                    |                   |
   |<-- showMenu --|                    |                   |
   |               |                    |                   |
   |-- selectWithdraw(amount) -------> |                   |
   |               |                    |                   |
   |               |-- requestFunds() ->|                   |
   |               |                    |-- checkBalance()->|
   |               |                    |<-- balanceOK ---- |
   |               |                    |-- deductAmount()->|
   |               |                    |<-- updateDone --- |
   |               |<-- approveDispense-|                   |
   |               |                    |                   |
   |<-- dispenseCash|                   |                   |
   |               |                    |                   |
   |<-- printReceipt                    |                   |
   |               |                    |                   |
   |-- ejectCard ->|                    |                   |
   |               |                    |                   |
   [END]
```

---

#### Flow Breakdown

**Step 1 — Card Insertion & Validation** *(Synchronous)*

The Customer inserts their card. The ATM sends a `validateCard()` request to the BankServer, which checks the card details against the Database and returns `cardValid` or `cardInvalid`.

**Step 2 — PIN Entry & Authentication** *(Synchronous)*

The ATM prompts the Customer for their PIN. The entered PIN is forwarded to the BankServer, which matches it against the stored hash in the Database. On success, `authSuccess` is returned.

**Step 3 — Transaction Request** *(Synchronous)*

The Customer selects a withdrawal amount from the menu. The ATM sends a `requestFunds(amount)` call to the BankServer, which checks the account balance in the Database.

**Step 4 — Balance Check & Deduction** *(Synchronous)*

The BankServer verifies sufficient funds, deducts the amount, and confirms the update. It then responds with `approveDispense` to the ATM.

**Step 5 — Cash Dispensing & Session End** *(Asynchronous)*

The ATM dispenses cash and asynchronously prints the receipt (no wait). Finally, the card is ejected and the session ends.

---

#### Message Summary Table

| Step | From        | To           | Message                      | Type          |
|------|-------------|--------------|------------------------------|---------------|
| 1    | Customer    | ATM          | `insertCard`                 | Synchronous   |
| 2    | ATM         | BankServer   | `validateCard()`             | Synchronous   |
| 3    | BankServer  | Database     | `checkCard()`                | Synchronous   |
| 4    | ATM         | Customer     | `promptPIN`                  | Synchronous   |
| 5    | Customer    | ATM          | `enterPIN`                   | Synchronous   |
| 6    | ATM         | BankServer   | `verifyPIN()`                | Synchronous   |
| 7    | BankServer  | Database     | `matchPIN()`                 | Synchronous   |
| 8    | Customer    | ATM          | `selectWithdraw(amount)`     | Synchronous   |
| 9    | ATM         | BankServer   | `requestFunds(amount)`       | Synchronous   |
| 10   | BankServer  | Database     | `checkBalance()`             | Synchronous   |
| 11   | BankServer  | Database     | `deductAmount()`             | Synchronous   |
| 12   | ATM         | Customer     | `dispenseCash`               | Synchronous   |
| 13   | ATM         | Customer     | `printReceipt`               | Asynchronous  |
| 14   | ATM         | Customer     | `ejectCard`                  | Synchronous   |

---

#### Error / Alternate Flows

| Scenario              | Trigger                        | ATM Response                                 |
|-----------------------|--------------------------------|----------------------------------------------|
| Invalid Card          | `cardInvalid` from BankServer  | Display error, eject card                    |
| Wrong PIN             | `pinIncorrect` from BankServer | Prompt retry; block card after 3 failures    |
| Insufficient Funds    | `balanceLow` from Database     | Display "Insufficient Balance", cancel transaction |
| Network Timeout       | No response from BankServer    | Display "Service Unavailable", eject card    |

---

## Why Developers Should Learn UML

- Required for **System Design** and **LLD interviews**
- Improves code architecture and planning
- Prevents poor design decisions before implementation
- Simplifies communication in team discussions
- Useful for documenting existing systems

---

## Folder Structure

```
uml-diagrams/
│
├── class-diagrams/
├── sequence-diagrams/
├── examples/
└── README.md
```

---

## Usage

Create UML diagrams **before coding** when:

- Designing a new project from scratch
- Building scalable backend systems
- Preparing for software engineering interviews
- Working collaboratively in a team

**Recommended Tools:**

| Tool       | Type       | Link                       |
|------------|------------|----------------------------|
| Draw.io    | Web-based  | https://draw.io            |
| Lucidchart | Web-based  | https://lucidchart.com     |
| Excalidraw | Web-based  | https://excalidraw.com     |
| PlantUML   | Code-based | https://plantuml.com       |

---

## Screenshots

> 📌 *Diagram screenshots will be added here.*

```
/screenshots/class-diagram.png
/screenshots/sequence-diagram.png
```

---

## Contributing

Contributions are welcome! To contribute:

---