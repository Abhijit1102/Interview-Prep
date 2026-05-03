## UML Diagram

`UML (Unified Modeling Language)` is a standard way to visually design and represent software using `diagrams`.

The main purpose is to have a common `visual language` that shows how classes, objects, relationships, and interactions work in a system.

This makes it easier for developers and teams to understand, discuss, and plan the system before writing actual code.

# UML Diagrams Importance

- **Visualization**: UML diagrams let you see the system visually, like a `blueprint`. This makes it much easier to understand how different parts of the system are `structured`, how they `connect`, and how they work together.

- **Documentation**: UML diagrams act as detailed documentation of your software design. This is very helpful when you need to maintain the code later or when the system needs to grow bigger.

- **Communications**: UML Diagrams create a common language that designers, developers, and teams can all understand. Everyone can look at the same diagram and discuss the design clearly without confusion.

- **Standardization**: Since UML is a universally accepted standard, everyone in the software industry reads and understands these diagrams the same way. No matter where you work, UML will be the same.

## Class Diagrams

Class diagrams show the blueprint of your system, including:

- What classes you have
- Their properties (attributes)
- Their actions (methods)
- How these classes are connected to each other (like inheritance, association, etc.)

### Student Class:

- **Attributes**:
  - `name`: str
  - `roll_no`: int
  - `cgpa`: float

- **Methods**:
  - `attend_class()`
  - `submit_assignment()`

## Association

Association is a fundamental relationship between two classes that illustrates how their objects interact with one another. It signifies that the object of one class can utilize or reference the object of another class, forming a connection.

In simpler terms: A class (Class A) knows about another class (Class B) and can use it. For example, consider a `Teacher` who teaches a `Student`—both classes interact with and depend on each other.

### Example:
| Teacher | Student |
|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - |
| - string name | - string name |
| + get_name() : str | +get_name() : str |
| + teach(student: Student): None | + get_name() : str |