#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {

        if (root == NULL) {
            return true;
        }

        if (min != NULL && root->val <= min->val) {
            return false;
        }

        if (max != NULL && root->val >= max->val) {
            return false;
        }

        return helper(root->left, min, root) &&
               helper(root->right, root, max);
    }

    bool validateBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};

int main() {

    /*
           5
         /   \
        3     7
       / \   / \
      2   4 6   8
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;

    if(obj.validateBST(root)){
        cout << "Valid BST";
    } else {
        cout << "Not a BST";
    }

    return 0;
}
