#include <iostream>
#include <vector>
#include <climits>
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

    TreeNode* helper(vector<int>& preorder, int &i, int bound){
        if(i >= preorder.size() || preorder[i] > bound){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, bound);

        return root;
    }

    TreeNode* BSTFromPreorder(vector<int>& preorder){
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};

void inorder(TreeNode* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){

    vector<int> preorder = {8,5,1,7,10,12};

    Solution obj;
    TreeNode* root = obj.BSTFromPreorder(preorder);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
