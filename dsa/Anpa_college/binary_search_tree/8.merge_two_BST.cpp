#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Build Balanced BST from Sorted Array
Node* buildBSTFromSorted(vector<int> &arr, int st, int end){
    if(st > end){
        return NULL;
    }

    int mid = st + (end - st) / 2;

    Node* root = new Node(arr[mid]);

    root->left = buildBSTFromSorted(arr, st, mid - 1);
    root->right = buildBSTFromSorted(arr, mid + 1, end);

    return root;
}

// Inorder traversal → gives sorted array
void inorder(Node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Merge two BSTs
Node* merge2BST(Node* root1, Node* root2){

    vector<int> arr1, arr2;

    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> merged;

    int i = 0, j = 0;

    // merge sorted arrays
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            merged.push_back(arr1[i++]);
        }
        else{
            merged.push_back(arr2[j++]);
        }
    }

    while(i < arr1.size()){
        merged.push_back(arr1[i++]);
    }

    while(j < arr2.size()){
        merged.push_back(arr2[j++]);
    }

    // build balanced BST
    return buildBSTFromSorted(merged, 0, merged.size() - 1);
}

void printInorder(Node* root){
    if(root == NULL) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){

    /*
        BST 1
           2
          / \
         1   4
    */

    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    /*
        BST 2
           3
          / \
         0   5
    */

    Node* root2 = new Node(3);
    root2->left = new Node(0);
    root2->right = new Node(5);

    Node* mergedRoot = merge2BST(root1, root2);

    cout << "Merged BST Inorder: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}
