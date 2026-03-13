# 🌳 Tree Data Structures

> **Complete Study Notes & Reference**

---

## Table of Contents

1. [What is a Tree?](#1-what-is-a-tree)
2. [Types of Trees](#2-types-of-trees)
3. [Tree Traversals](#3-tree-traversals)
4. [Common Tree Algorithms](#4-common-tree-algorithms)
5. [BST Operations](#5-bst-operations)
6. [Complexity Summary](#6-complexity-summary)
7. [Interview Tips & Problem Patterns](#7-interview-tips--problem-patterns)

---

## 1. What is a Tree?

A tree is a **hierarchical, non-linear** data structure consisting of nodes connected by edges. Unlike arrays or linked lists, trees represent data in a parent-child relationship.

> 📌 **Key Properties**
>
> - ✔ Non-linear — data arranged hierarchically, not sequentially
> - ✔ Connected — every node reachable from the root
> - ✔ Acyclic — no cycles; exactly one path between any two nodes
> - ✔ N nodes → exactly **N-1 edges**

### 1.1 Core Terminology

| Term                | Definition                               |
| ------------------- | ---------------------------------------- |
| **Root**            | The topmost node with no parent          |
| **Leaf / External** | A node with no children                  |
| **Internal Node**   | A node with at least one child           |
| **Edge**            | The link between a parent and child node |
| **Height**          | Longest path from a node to a leaf       |
| **Depth / Level**   | Distance from root to the node           |
| **Subtree**         | A node plus all its descendants          |
| **Degree**          | Number of children a node has            |

---

## 2. Types of Trees

### 2.1 Binary Tree

**Definition:** Each node has at most 2 children (left and right).

- **Full** — every node has 0 or 2 children
- **Complete** — all levels filled except last; last filled left-to-right
- **Perfect** — all internal nodes have 2 children; all leaves at same level
- **Balanced** — height O(log n); |h(left) - h(right)| ≤ 1 at every node
- **Degenerate** — every internal node has one child — essentially a linked list

```
    1          ← Root (depth 0)
   / \
  2   3        ← Internal (depth 1)
 / \   \
4   5   6      ← Leaves (depth 2)
```

---

### 2.2 Binary Search Tree (BST)

Ordering property: for any node N:

- **Left subtree** — all keys < N.key
- **Right subtree** — all keys > N.key
- No duplicate keys (by convention)

```
        8
       / \
      3   10
     / \    \
    1   6   14
       / \  /
      4  7 13
```

| Operation | Average  | Worst Case |
| --------- | -------- | ---------- |
| Search    | O(log n) | O(n)       |
| Insert    | O(log n) | O(n)       |
| Delete    | O(log n) | O(n)       |
| Min/Max   | O(log n) | O(n)       |

> ⚠️ Worst case O(n) occurs when the tree degenerates (sorted input).

---

### 2.3 AVL Tree (Self-Balancing BST)

Auto-balances using rotations after insertions and deletions.

- **Balance Factor** = `height(left) - height(right)`
- Valid balance factors: **-1, 0, +1**
- If |BF| > 1 → trigger rotation to rebalance

| Case | Rotation              |
| ---- | --------------------- |
| LL   | Single Right Rotation |
| RR   | Single Left Rotation  |
| LR   | Left then Right       |
| RL   | Right then Left       |

| Operation | Average  | Worst Case |
| --------- | -------- | ---------- |
| Search    | O(log n) | O(log n)   |
| Insert    | O(log n) | O(log n)   |
| Delete    | O(log n) | O(log n)   |

---

### 2.4 Red-Black Tree

Self-balancing BST where every node is colored **Red** or **Black**.

#### Rules (Invariants)

1. Every node is RED or BLACK
2. Root is always **BLACK**
3. Every leaf (NIL) is **BLACK**
4. Red nodes can only have **BLACK** children (no two consecutive reds)
5. Every root-to-NIL path has the same count of BLACK nodes (**Black-Height**)

| Operation | Average  | Worst Case |
| --------- | -------- | ---------- |
| Search    | O(log n) | O(log n)   |
| Insert    | O(log n) | O(log n)   |
| Delete    | O(log n) | O(log n)   |

> 📌 **AVL vs Red-Black**
>
> - **AVL** → more strictly balanced → faster lookups, slower inserts/deletes
> - **Red-Black** → faster inserts/deletes, slightly slower lookups
> - Use AVL when **read-heavy**; use Red-Black when **write-heavy**

---

### 2.5 B-Tree

Multi-way search tree of order `m`, used in databases and file systems.

- Each node holds up to `m-1` keys and `m` children
- All leaves at same level (height-balanced)
- Minimizes disk I/O — node size fits one disk block
- **B+ Tree** — all data in leaves; leaves linked for range queries

| Operation | Average  | Worst Case |
| --------- | -------- | ---------- |
| Search    | O(log n) | O(log n)   |
| Insert    | O(log n) | O(log n)   |
| Delete    | O(log n) | O(log n)   |

---

### 2.6 Heap (Binary Heap)

A **complete binary tree** stored as array, satisfying the heap property.

- **Max-Heap** — parent ≥ children; root = maximum
- **Min-Heap** — parent ≤ children; root = minimum

#### Array Representation

```
For node at index i:
  Parent      = (i - 1) / 2
  Left child  = 2*i + 1
  Right child = 2*i + 2
```

| Operation   | Average    | Worst Case |
| ----------- | ---------- | ---------- |
| Get Max/Min | O(1)       | O(1)       |
| Insert      | O(log n)   | O(log n)   |
| Delete Max  | O(log n)   | O(log n)   |
| Build Heap  | O(n)       | O(n)       |
| Heap Sort   | O(n log n) | O(n log n) |

---

### 2.7 Trie (Prefix Tree)

Tree for storing strings; each path spells a prefix.

- Each node represents one character
- Shares common prefixes — space-efficient for string sets
- **Use cases:** Autocomplete, spell check, IP routing, dictionary lookups

```
Words: ["cat","car","card","care","bat"]

        root
       /    \
      c      b
      |      |
      a      a
     / \     |
    t   r    t*
   *   /|\
      d* e* *
```

| Operation | Time |
| --------- | ---- |
| Search    | O(m) |
| Insert    | O(m) |
| Delete    | O(m) |

> `m` = length of the key/string

---

### 2.8 Segment Tree

Tree for storing interval info and answering range queries.

- **Use cases:** Range sum, min/max, GCD, lazy propagation
- Space: `O(4n)` array

```
Array: [1, 3, 5, 7, 9, 11]

         [36]         ← sum of all
        /     \
      [9]     [27]
     /   \   /    \
   [4]  [5][16]  [11]
   / \       / \
  [1][3]   [7] [9]
```

| Operation           | Average  | Worst Case |
| ------------------- | -------- | ---------- |
| Build               | O(n)     | O(n)       |
| Range Query         | O(log n) | O(log n)   |
| Point Update        | O(log n) | O(log n)   |
| Range Update (Lazy) | O(log n) | O(log n)   |

---

## 3. Tree Traversals

### 3.1 Depth-First Search (DFS)

#### Pre-order (Root → Left → Right)

```python
def preorder(node):
    if not node: return
    print(node.val)       # Visit root first
    preorder(node.left)
    preorder(node.right)
```

**Use:** Copying/serializing trees, prefix expressions

#### In-order (Left → Root → Right)

```python
def inorder(node):
    if not node: return
    inorder(node.left)
    print(node.val)        # Visit root middle
    inorder(node.right)
```

**Use:** BST → sorted output; infix expression evaluation

#### Post-order (Left → Right → Root)

```python
def postorder(node):
    if not node: return
    postorder(node.left)
    postorder(node.right)
    print(node.val)        # Visit root last
```

**Use:** Deleting trees, postfix expressions, directory size

---

### 3.2 BFS / Level-Order

```python
from collections import deque

def bfs(root):
    if not root: return
    q = deque([root])
    while q:
        node = q.popleft()
        print(node.val)
        if node.left:  q.append(node.left)
        if node.right: q.append(node.right)
```

**Use:** Shortest path, level-wise processing, serialization

---

> 📌 **Quick Comparison**
>
> | Traversal  | Order       | Best For                        |
> | ---------- | ----------- | ------------------------------- |
> | Pre-order  | Root first  | Copying / prefix expressions    |
> | In-order   | Root middle | BST sorted output               |
> | Post-order | Root last   | Deletion / postfix evaluation   |
> | BFS        | Level order | Shortest path, level processing |

---

## 4. Common Tree Algorithms

### 4.1 Height of a Tree

```python
def height(node):
    if not node: return -1
    return 1 + max(height(node.left), height(node.right))

# Time: O(n)  |  Space: O(h)
```

### 4.2 Lowest Common Ancestor (LCA)

```python
def lca(root, p, q):
    if not root or root == p or root == q:
        return root
    left  = lca(root.left,  p, q)
    right = lca(root.right, p, q)
    if left and right:
        return root   # p and q in different subtrees
    return left or right

# Time: O(n)  |  Space: O(h)
```

### 4.3 Check if BST is Valid

```python
def is_valid_bst(node, lo=float('-inf'), hi=float('inf')):
    if not node: return True
    if node.val <= lo or node.val >= hi:
        return False
    return (is_valid_bst(node.left,  lo,       node.val) and
            is_valid_bst(node.right, node.val, hi))

# Time: O(n)  |  Space: O(h)
```

### 4.4 Diameter of Binary Tree

> Diameter = longest path between any two nodes (may not pass through root).

```python
def diameter(root):
    max_d = [0]
    def depth(node):
        if not node: return 0
        l, r = depth(node.left), depth(node.right)
        max_d[0] = max(max_d[0], l + r)
        return 1 + max(l, r)
    depth(root)
    return max_d[0]

# Time: O(n)  |  Space: O(h)
```

### 4.5 Level-Order Zigzag Traversal

```python
def zigzag(root):
    if not root: return []
    result, q, left_to_right = [], deque([root]), True
    while q:
        level = []
        for _ in range(len(q)):
            node = q.popleft()
            level.append(node.val)
            if node.left:  q.append(node.left)
            if node.right: q.append(node.right)
        result.append(level if left_to_right else level[::-1])
        left_to_right = not left_to_right
    return result
```

---

## 5. BST Operations

### 5.1 Insert

```python
def insert(root, val):
    if not root: return TreeNode(val)
    if val < root.val:
        root.left  = insert(root.left,  val)
    elif val > root.val:
        root.right = insert(root.right, val)
    return root
```

### 5.2 Search

```python
def search(root, val):
    if not root or root.val == val:
        return root
    if val < root.val:
        return search(root.left, val)
    return search(root.right, val)
```

### 5.3 Delete

```python
def delete(root, key):
    if not root: return None
    if key < root.val:
        root.left  = delete(root.left,  key)
    elif key > root.val:
        root.right = delete(root.right, key)
    else:
        # Case 1: Leaf  /  Case 2: One child
        if not root.left:  return root.right
        if not root.right: return root.left
        # Case 3: Two children — replace with in-order successor
        successor = root.right
        while successor.left:
            successor = successor.left
        root.val   = successor.val
        root.right = delete(root.right, successor.val)
    return root
```

---

## 6. Complexity Summary

| Structure      | Search   | Insert   | Delete   | Space | Notes             |
| -------------- | -------- | -------- | -------- | ----- | ----------------- |
| BST (balanced) | O(log n) | O(log n) | O(log n) | O(n)  | Height O(log n)   |
| BST (skewed)   | O(n)     | O(n)     | O(n)     | O(n)  | Degenerate        |
| AVL Tree       | O(log n) | O(log n) | O(log n) | O(n)  | Strictly balanced |
| Red-Black Tree | O(log n) | O(log n) | O(log n) | O(n)  | ~2x height of AVL |
| B-Tree         | O(log n) | O(log n) | O(log n) | O(n)  | Disk-friendly     |
| Binary Heap    | O(n)     | O(log n) | O(log n) | O(n)  | O(1) get-max/min  |
| Trie           | O(m)     | O(m)     | O(m)     | O(nm) | m = key length    |
| Segment Tree   | O(log n) | O(log n) | O(log n) | O(n)  | Range queries     |

---

## 7. Interview Tips & Problem Patterns

### 7.1 Recognizing Tree Problems

- **Hierarchical data** — file systems, org charts, DOM → Trees
- **Sorted retrieval / range queries** → BST, AVL, B-Tree
- **Prefix matching, autocomplete** → Trie
- **Priority queue, scheduling** → Heap
- **Range queries on array** → Segment Tree or Fenwick Tree

### 7.2 Common Patterns

- **Recursion + return value** — height, diameter, path sum, LCA
- **DFS with state** — path tracking, sum validation
- **BFS for level properties** — level order, min depth, zigzag
- **Two-pass DFS** — rerooting technique for tree DP
- **Parent pointers + DFS** — convert tree ↔ graph problems

### 7.3 Edge Cases to Always Check

- [ ] Empty tree (root is `null`)
- [ ] Single node tree
- [ ] Skewed / linear tree (degenerate BST)
- [ ] Node values at integer limits (`INT_MIN`, `INT_MAX`)
- [ ] Duplicate values in BST
- [ ] Disconnected or invalid inputs

---

> 📌 **Golden Rules for Tree Interviews**
>
> 1. Always handle the **base case first** (null check)
> 2. Think recursively — **trust the recursive call**
> 3. Decide: **top-down** (pre-order) or **bottom-up** (post-order)?
> 4. For BST: exploit **ordering** to prune subtrees
> 5. Use **BFS (queue)** for level-related problems
> 6. Pass extra **state down** (lo/hi, path sum, etc.)
> 7. Watch for **O(n) stack space** on very tall trees

---

_— End of Notes —_
