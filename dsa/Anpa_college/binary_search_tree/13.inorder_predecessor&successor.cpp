#include <iostream>
#include <vector>
using namespace std;

// Define Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert in BST
Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Rightmost in left subtree (Predecessor)
Node* rightMostInLeftSubTree(Node* root) {
    Node* ans = NULL;
    while (root != NULL) {
        ans = root;
        root = root->right;
    }
    return ans;
}

// Leftmost in right subtree (Successor)
Node* leftMostInRightSubTree(Node* root) {
    Node* ans = NULL;
    while (root != NULL) {
        ans = root;
        root = root->left;
    }
    return ans;
}

// Find predecessor and successor
vector<int> getPredecessorSuccessor(Node* root, int key) {
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while (curr != NULL) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if (key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            if (curr->left != NULL)
                pred = rightMostInLeftSubTree(curr->left);

            if (curr->right != NULL)
                succ = leftMostInRightSubTree(curr->right);

            break;
        }
    }

    int predecessor = (pred != NULL) ? pred->data : -1;
    int successor = (succ != NULL) ? succ->data : -1;

    return {predecessor, successor};
}

// MAIN FUNCTION
int main() {
    Node* root = NULL;

    // Build BST
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    int key = 20;

    vector<int> result = getPredecessorSuccessor(root, key);

    cout << "Predecessor: " << result[0] << endl;
    cout << "Successor: " << result[1] << endl;

    return 0;
}
