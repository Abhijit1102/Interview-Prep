#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int idx = -1;

Node* buildTree(vector<int>& preorder, int &idx) {
    idx++;

    if (idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

void levelOrder(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();  // 🔥 IMPORTANT

        if(curr == NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }

        cout << curr->data << " ";

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }

    cout << endl;
}

int heightTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int LeftHt = heightTree(root->left);
    int rightHt = heightTree(root->right);

    return max(LeftHt, rightHt) + 1;
}

int CountNodeTree(Node* root){

}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    int idx = -1;
    Node* root = buildTree(preorder, idx);

    levelOrder(root);

    cout << "Height of Tree " << heightTree(root) << endl;

    return 0;
}
