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
    int count = 0;
    int ans = -1;

    void inorder(TreeNode* root, int k) {
        if (root == NULL) return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};

int main() {

    /*
          5
        /   \
       3     6
      / \
     2   4
    /
   1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution obj;

    int k = 3;

    cout << "Kth Smallest Element: " << obj.kthSmallest(root, k) << endl;

    return 0;
}
