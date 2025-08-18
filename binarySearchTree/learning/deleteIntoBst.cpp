#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.*/
/*
Approach- 

*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* findLastRight(TreeNode* root){
    if(!root->right) return root;
    return findLastRight(root->right);
    
}
TreeNode* helper(TreeNode* root){
    if(!root->left) return root->right;
    if(!root->right) return root->left;
    TreeNode* rightChild=root->right;
    TreeNode* lastRightChild=findLastRight(root->left);
    lastRightChild->right=rightChild;
    return root->left;
}
TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key){
            return helper(root);
        }
        TreeNode* dummyNode=root;
        while (root)
        {
            if(root->val>key){
                if(root->left && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
    return dummyNode;
}
int main(){
  
    return 0;
}