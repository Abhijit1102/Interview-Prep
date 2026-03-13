# Binary Search Tree (BST)

## 1. What is a Binary Search Tree

A **Binary Search Tree (BST)** is a binary tree where each node follows these rules:

- All values in the **left subtree are smaller than the root**
- All values in the **right subtree are greater than the root**
- Both left and right subtrees must also be BSTs

Example:

```
        8
       / \
      3   10
     / \    \
    1   6    14
       / \   /
      4   7 13
```

---

# 2. Properties of BST

1. Left subtree values **< root**
2. Right subtree values **> root**
3. No duplicate values (usually)
4. **Inorder traversal produces sorted order**

---

# 3. Time Complexity

| Operation | Average  | Worst Case |
| --------- | -------- | ---------- |
| Search    | O(log n) | O(n)       |
| Insert    | O(log n) | O(n)       |
| Delete    | O(log n) | O(n)       |

Worst case happens when the tree becomes **skewed**.

Example:

```
1
 \
  2
   \
    3
     \
      4
```

---

# 4. Inorder Traversal Property

The **inorder traversal of a BST always produces sorted order**.

Example:

```
      5
     / \
    3   7
   / \ / \
  2  4 6  8
```

Inorder traversal:

```
2 3 4 5 6 7 8
```

---

# 5. BST Operations

## Search

Idea:

- If key < root → go left
- If key > root → go right

```cpp
TreeNode* search(TreeNode* root, int key){
    if(root == NULL || root->val == key){
        return root;
    }

    if(key < root->val){
        return search(root->left, key);
    }

    return search(root->right, key);
}
```

---

## Insert

Insertion always happens at a **leaf node**.

```cpp
TreeNode* insert(TreeNode* root, int key){

    if(root == NULL){
        return new TreeNode(key);
    }

    if(key < root->val){
        root->left = insert(root->left, key);
    }
    else{
        root->right = insert(root->right, key);
    }

    return root;
}
```

---

## Delete

Deletion has **three cases**.

### Case 1: Leaf Node

```
  5
 /
3
```

Delete `3` → simply remove it.

---

### Case 2: One Child

```
  5
 /
3
 \
  4
```

Replace node with its child.

---

### Case 3: Two Children

Replace the node with:

- **Inorder Successor** (smallest node in right subtree)

Example:

```
       8
      / \
     4   12
        /
       10
```

Delete `8` → replace with `10`.

---

# 6. Important BST Concepts

## Inorder Successor

Smallest node in the **right subtree**.

## Inorder Predecessor

Largest node in the **left subtree**.

---

# 7. Height of BST

Best case (balanced tree):

```
Height = log2(n)
```

Worst case:

```
Height = n
```

---

# 8. Important BST Interview Problems

Common problems include:

- Search in BST
- Insert into BST
- Delete node in BST
- Validate BST
- Lowest Common Ancestor in BST
- Kth smallest element in BST
- BST Iterator
- Convert BST to sorted list
- Two Sum in BST

---

# 9. BST vs Binary Tree

| Feature  | Binary Tree | BST                 |
| -------- | ----------- | ------------------- |
| Ordering | No rule     | Left < Root < Right |
| Search   | O(n)        | O(log n)            |
| Inorder  | Random      | Sorted              |

---

# 10. Self Balancing BST

To prevent worst-case scenarios, balanced trees are used:

- AVL Tree
- Red-Black Tree
- Treap
- Splay Tree

These are used in:

- Databases
- File systems
- `map` and `set` in C++ STL

---

# Key Takeaways

- BST maintains **sorted order**
- **Inorder traversal = sorted output**
- Average complexity **O(log n)**
- Worst case **O(n)** when tree becomes skewed
