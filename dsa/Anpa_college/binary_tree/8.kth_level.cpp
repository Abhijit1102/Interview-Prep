#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int idx = -1;

Node* buildTree(vector<int> &nodes) {
    idx++;

    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* newNode = new Node(nodes[idx]);

    newNode->left = buildTree(nodes);
    newNode->right = buildTree(nodes);

    return newNode;
}

// kth level of the Tree
void KthLevel(Node* root, int K) {
    if(root == NULL) {
        return;
    }

    if(K == 1) {
        cout << root->data << " ";
        return;
    }

    KthLevel(root->left, K-1);
    KthLevel(root->right, K-1);
}

int main() {

    vector<int> preorder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);

    KthLevel(root, 3);

    cout << endl;

    return 0;
}
