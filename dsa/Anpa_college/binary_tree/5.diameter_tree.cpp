#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        return max(leftHt, rightHt) + 1; // +1 for current node
    }

    int diameterBinaryTree(TreeNode* root){
        if(root == nullptr) return 0;

        int leftDiameter = diameterBinaryTree(root->left);
        int rightDiameter = diameterBinaryTree(root->right);
        int currDiameter = height(root->left) + height(root->right);

        return max(currDiameter, max(leftDiameter, rightDiameter));
    }
};

// Helper function to build a simple tree for testing
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;
    cout << "Diameter of binary tree: " << sol.diameterBinaryTree(root) << endl;

    // Cleanup (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
