#include <iostream>
using namespace std;

// Define TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {

    bool isSameTree(TreeNode* p, TreeNode* q){
        if (p == NULL || q == NULL) {
            return p == q;
        }

        return p->val == q->val &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (root == NULL) {
            return false;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main() {

    /*
            Main Tree
                3
               / \
              4   5
             / \
            1   2
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    /*
            Subtree (Valid)
                4
               / \
              1   2
    */

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;

    bool result = sol.isSubtree(root, subRoot);

    if (result)
        cout << "Subtree Found ✅" << endl;
    else
        cout << "Subtree Not Found ❌" << endl;

    return 0;
}
