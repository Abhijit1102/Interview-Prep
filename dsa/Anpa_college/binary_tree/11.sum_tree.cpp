#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int sumTree(Node* root) {
        if (root == NULL) {
            return 0;
        }

        int leftSum = sumTree(root->left);
        int rightSum = sumTree(root->right);

        root->data += leftSum + rightSum;
        return root->data;
    }
};

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    // Creating tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);

    Solution obj;

    obj.sumTree(root);

    cout << "Inorder traversal after converting to Sum Tree:\n";
    inorder(root);
    cout << endl;

    return 0;
}
