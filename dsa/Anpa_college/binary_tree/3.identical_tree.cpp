#include <iostream>
using namespace std;

// Assume TreeNode is already defined
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
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if( p == NULL || q == NULL) {
            return p == q;
        }
        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return isLeftSame && isRightSame;
    };
};

int main() {
    // Create first tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Create second tree
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    // Create Solution object
    Solution sol;

    // Call function
    bool result = sol.isSameTree(root1, root2);

    // Print result
    if (result)
        cout << "Trees are same" << endl;
    else
        cout << "Trees are not same" << endl;

    return 0;
}
