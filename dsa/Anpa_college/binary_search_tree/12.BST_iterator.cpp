#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

class BSTIterator {
public:
    stack<Node*> s;

    // Push all left nodes
    void storeLeftNodes(Node* root) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(Node* root) {
        storeLeftNodes(root);
    }

    int next() {
        Node* ans = s.top();
        s.pop();

        if (ans->right != NULL) {
            storeLeftNodes(ans->right);
        }

        return ans->val;
    }

    bool hasNext() {
        return !s.empty();
    }
};

int main() {
    /*
          7
         / \
        3   15
           /  \
          9    20
    */

    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTIterator it(root);

    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}
