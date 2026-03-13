#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

int idx = -1;

TreeNode* buildTree(vector<int> &nodes) {
    idx++;

    if(nodes[idx] == -1) {
        return NULL;
    }

    TreeNode* newNode = new TreeNode(nodes[idx]);

    newNode->left = buildTree(nodes);
    newNode->right = buildTree(nodes);

    return newNode;
}

// Lowest Common Ancestor
TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(root == NULL) {
        return NULL;
    }

    if(root == p || root == q) {
        return root;
    }

    TreeNode* leftLCA = LowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = LowestCommonAncestor(root->right, p, q);

    if(leftLCA && rightLCA) {
        return root;
    }

    if(leftLCA != NULL) {
        return leftLCA;
    }

    return rightLCA;
}

int main() {

    vector<int> preorder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};

    TreeNode* root = buildTree(preorder);

    TreeNode* p = root->left;          // Node 2
    TreeNode* q = root->right->right;  // Node 5

    TreeNode* lca = LowestCommonAncestor(root, p, q);

    cout << "LCA: " << lca->data << endl;

    return 0;
}
