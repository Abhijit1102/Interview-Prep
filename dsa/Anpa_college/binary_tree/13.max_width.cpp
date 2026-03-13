#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

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
    int widthBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        int maxWidth = 0;

        while(!q.empty()) {

            int currLevelSize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

            for(int i = 0; i < currLevelSize; i++) {

                pair<TreeNode*, unsigned long long> curr = q.front();
                q.pop();

                TreeNode* node = curr.first;
                unsigned long long idx = curr.second;

                if(node->left) {
                    q.push({node->left, idx * 2 + 1});
                }

                if(node->right) {
                    q.push({node->right, idx * 2 + 2});
                }
            }
        }

        return maxWidth;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution obj;

    int width = obj.widthBinaryTree(root);

    cout << "Maximum width of binary tree: " << width << endl;

    return 0;
}
