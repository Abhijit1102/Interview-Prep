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
private:
    int ans; // store diameter
public:
    Solution() : ans(0) {} // initialize ans to 0

    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        ans = max(ans, leftHt + rightHt); // update diameter
        return max(leftHt, rightHt) + 1;  // height of current node
    }

    int diameterBinaryTree(TreeNode* root){
        ans = 0; // reset ans for multiple calls
        height(root);
        return ans;
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
