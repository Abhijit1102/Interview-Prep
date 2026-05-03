#include <iostream>
#include <climits>
using namespace std;

// Basic Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Info structure to return from helper
class Info {
public:
    int min;   // Minimum value in subtree
    int max;   // Maximum value in subtree
    int sz;    // Size of the largest BST in subtree
    bool isBST; // Whether the subtree itself is BST

    Info(int mn, int mx, int size, bool bst) {
        min = mn;
        max = mx;
        sz = size;
        isBST = bst;
    }
};

// Helper function to compute largest BST
Info helper(Node* root) {
    if (!root) {
        return Info(INT_MAX, INT_MIN, 0, true);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if (left.isBST && right.isBST && root->data > left.max && root->data < right.min) {
        // Current tree is BST
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currSz = left.sz + right.sz + 1;
        return Info(currMin, currMax, currSz, true);
    } else {
        // Not a BST, return the largest BST size of children
        int currSz = max(left.sz, right.sz);
        return Info(0, 0, currSz, false);
    }
}

class Solution {
public:
    int largestBSTinBT(Node* root) {
        Info info = helper(root);
        return info.sz;
    }
};

// Example usage
int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    Solution sol;
    cout << "Size of largest BST is: " << sol.largestBSTinBT(root) << endl; // Output: 3
    return 0;
}
