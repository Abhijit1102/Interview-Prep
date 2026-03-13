#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Helper function to build a binary tree from preorder array with -1 as NULL
Node* buildTree(vector<int>& preorder, int& index) {
    if(index >= preorder.size() || preorder[index] == -1) {
        index++;
        return nullptr;
    }
    Node* root = new Node(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}

void topView(Node* root) {
    if(root == nullptr) return;

    queue<pair<Node*, int>> q; // pair of node and horizontal distance
    map<int, int> m; // horizontal distance -> node data

    q.push({root, 0});

    while(!q.empty()) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        // Insert only first node at each horizontal distance
        if(m.find(currHD) == m.end()) {
            m[currHD] = curr->data;
        }

        if(curr->left != nullptr) {
            q.push({curr->left, currHD - 1});
        }

        if(curr->right != nullptr) {
            q.push({curr->right, currHD + 1});
        }
    }

    // Print the top view
    for(auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = buildTree(preorder, index);

    cout << "Top View: ";
    topView(root);

    return 0;
}
