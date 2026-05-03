#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x) {
        val = x;
        left = right = next = NULL;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = NULL;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (prev != NULL) {
                    prev->next = curr;
                }
                prev = curr;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            prev->next = NULL; // last node of level
        }

        return root;
    }
};

// Function to print tree level-wise using next pointers
void printLevels(Node* root) {
    Node* levelStart = root;

    while (levelStart != NULL) {
        Node* curr = levelStart;

        while (curr != NULL) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;

        levelStart = levelStart->left; // move to next level
    }
}

int main() {
    /*
        Create Tree:
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    root = sol.connect(root);

    cout << "Level order using next pointers:\n";
    printLevels(root);

    return 0;
}
