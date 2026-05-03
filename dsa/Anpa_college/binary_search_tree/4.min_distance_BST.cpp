#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution{
public:
    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root){
        if(root == NULL){
            return INT_MAX;
        }

        int ans = INT_MAX;

        // left subtree
        if(root->left != NULL){
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }

        // current node
        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        // right subtree
        if(root->right != NULL){
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }

        return ans;
    }
};

int main(){

    /*
        Example BST

              4
            /   \
           2     6
          / \
         1   3
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    int result = obj.minDiffInBST(root);

    cout << "Minimum difference in BST: " << result << endl;

    return 0;
}
