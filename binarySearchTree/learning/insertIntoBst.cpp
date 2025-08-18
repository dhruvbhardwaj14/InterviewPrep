#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
*/
/*Approach- 
Move in the binary tree and for each node
-> If val<root->val and if left child exist move left if not exist then place this value new node on right
-> if val> root-> val  and if right child exist do same.
-> if it's a leaf node we know both left and right do not exist then add to bst at valid left or right
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) {
        root=new TreeNode(val);
        return root;
    }
    if(!root->left && !root->right){
        if(root->val > val){
            root->left=new TreeNode(val);
            return root;
        }
        else{
            root->right=new TreeNode(val);
            return root;
        }
    }
    if(root->val > val){
       if(root->left) insertIntoBST(root->left,val);
       else root->left=new TreeNode(val);
       return root;
    }
    if(root->right) insertIntoBST(root->right,val); 
    else root->right=new TreeNode(val);
    return root;
}
int main(){
  
    return 0;
}