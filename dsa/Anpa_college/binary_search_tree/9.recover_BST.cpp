#include <iostream>
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
    TreeNode* first = NULL;
    TreeNode* sec = NULL;

    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
    }

    void recoverTree(TreeNode* root){

    }
}

int main() {

    return 0;
}
