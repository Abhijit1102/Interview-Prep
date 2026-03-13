#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
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

    vector<int> MorrisInorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* curr = root;

        while(curr != NULL) {

            if(curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {

                TreeNode* Ip = curr->left;

                while(Ip->right != NULL && Ip->right != curr) {
                    Ip = Ip->right;
                }

                if(Ip->right == NULL) {
                    Ip->right = curr;
                    curr = curr->left;
                }
                else {
                    Ip->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

int main() {

    // Create sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    vector<int> result = obj.MorrisInorderTraversal(root);

    cout << "Morris Inorder Traversal: ";

    for(int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
