# 📚 Stack — DSA Notes

> A complete reference for Stack data structure: concepts, implementation, problems & interview tips.

---

## 🔹 What is a Stack?

A **Stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle.
The element inserted **last** is removed **first** — just like a stack of plates 🍽️

```
Push 1 → Push 2 → Push 3

Stack:
┌───┐
│ 3 │ ← Top
├───┤
│ 2 │
├───┤
│ 1 │
└───┘

Pop → removes 3 first
```

---

## 🔹 Basic Operations

| Operation        | Description                          |
|------------------|--------------------------------------|
| `push(x)`        | Insert element into stack            |
| `pop()`          | Remove top element                   |
| `top()` / `peek()` | Get top element without removing   |
| `isEmpty()`      | Check if stack is empty              |
| `size()`         | Number of elements in the stack      |

---

## 🔹 Implementation Methods

### 1. Using Array
- ✅ Fixed size
- ✅ Faster
- ❌ Possible overflow

### 2. Using Linked List
- ✅ Dynamic size
- ✅ No overflow (until memory full)
- ❌ Slightly slower

---

## 🔹 Stack in C++

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;       // 30

    st.pop();

    cout << "After pop Top: " << st.top() << endl;  // 20

    return 0;
}
```

---

## 🔹 Time Complexity

| Operation | Complexity |
|-----------|------------|
| Push      | O(1)       |
| Pop       | O(1)       |
| Peek      | O(1)       |

---

## 🔹 When to Use a Stack?

Stack is ideal when **reversal** or **recent memory access** is required.

**Common signals in interview problems:**
- Nearest element (previous/next)
- Balanced symbols
- Undo operations
- Backtracking

---

## 🔹 Important Applications

### 1. ✅ Balanced Parentheses
```
( ) { } [ ]  →  valid
( [ ) ]      →  invalid
```

### 2. 🔄 Expression Conversion
- Infix → Postfix
- Infix → Prefix

### 3. 📞 Function Call Stack
Used internally by **recursion** — each function call is pushed onto the call stack.

### 4. ↩️ Undo / Redo
- `Ctrl + Z` in editors
- Browser **back** button

### 5. 📈 Monotonic Stack *(VERY IMPORTANT)*
Used in:
- Next Greater Element
- Stock Span Problem
- Largest Rectangle in Histogram
- Daily Temperatures *(LeetCode)*

---

## 🔹 Classic Interview Problems

| Problem | Difficulty |
|---------|------------|
| Valid Parentheses | Easy |
| Next Greater Element | Medium |
| Min Stack | Medium |
| Stock Span Problem | Medium |
| Largest Rectangle in Histogram | Hard |
| Trapping Rain Water (optimized) | Hard |

---

## 🔹 Example: Valid Parentheses

```cpp
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            if (st.empty()) return false;
            char t = st.top();
            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '['))
                return false;
            st.pop();
        }
    }

    return st.empty();
}
```

---

## 🔹 Advantages & Disadvantages

| ✅ Advantages | ❌ Disadvantages |
|--------------|-----------------|
| O(1) push, pop, peek | Only top element is directly accessible |
| Simple implementation | Not suitable for searching |
| Essential for recursion & parsing | Fixed size (array-based) can overflow |

---

## 🧠 Interview Tip

> If a problem mentions any of the following keywords, **think Stack first:**

```
nearest previous / next greater
balanced / matching
remove duplicates
span
undo / redo
backtracking
```

---

*Happy Coding! 🚀*